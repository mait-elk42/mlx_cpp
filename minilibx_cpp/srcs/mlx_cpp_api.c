/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cpp_api.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:51:12 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/06 20:25:07 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	*_nsx_mlx_init()
{
	return (mlx_init());
}

void	*_nsx_mlx_new_window(void	*mlx_ptr, int win_x, int win_y, const char *win_title)
{
	return (mlx_new_window(mlx_ptr, win_x, win_y, (char *)win_title));
}

int	_nsx_mlx_loop_hook(void	*mlx_ptr, int (*f)(void *), void *param)
{
	return (mlx_loop_hook(mlx_ptr, f, param));
}

int	_nsx_mlx_loop(void *mlx_ptr)
{
	return (mlx_loop(mlx_ptr));
}

int		_nsx_new_color(const unsigned char r, const unsigned char g, const unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

int	_nsx_mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, const char *string)
{
	return (mlx_string_put(mlx_ptr, win_ptr, x, y, color, (char *)string));
}

int	_nsx_mlx_destroy_window(void *mlx_ptr, void *win_ptr)
{
	return (mlx_destroy_window(mlx_ptr, win_ptr));
}

int	_nsx_mlx_png_file_to_image(void *mlx_ptr, const char *filename, t_image *output)
{
	output->buffer = stbi_load(filename, &output->width, &output->height, &output->channels, 0);
	if (!output->buffer)
		return (-1);
	output->type = 'P';
	return (1);
}

int	_nsx_mlx_xpm_file_to_image(void *mlx_ptr, const char *filename, t_image *output)
{
	output->buffer = mlx_xpm_file_to_image(mlx_ptr, (char *)filename, &output->width, &output->height);
	if (!output->buffer)
		return (-1);
	output->type = 'X';
	return (1);
}

int	_nsx_mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, t_image image, t_vector2 position)
{
	int	i, j;

	i = j = 0;
	if (!mlx_ptr || !win_ptr || !image.buffer)
		return (-1);
	if (image.type == 'X')
		return(mlx_put_image_to_window(mlx_ptr, win_ptr, (char *)image.buffer, position.x, position.y));
	if (image.type == 'P')
		while (image.height > i)
		{
			j = 0;
			while (image.width > j)
			{
				unsigned char R = *image.buffer++;
				unsigned char G = *image.buffer++;
				unsigned char B = *image.buffer++;
				unsigned char A = ((image.channels >= 4) && *image.buffer++);
				if ((A > 0 && image.channels >= 4) || image.channels == 3)
					mlx_pixel_put(mlx_ptr, win_ptr, position.x + j, position.y + i, _nsx_new_color(R, G, B));
				j++;
			}
			i++;
		}
	return (1);
}
