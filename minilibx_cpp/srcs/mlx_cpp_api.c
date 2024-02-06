/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cpp_api.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:51:12 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/06 16:37:11 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	*_nsx_mlx_init()
{
	return (mlx_init());
}

void	*_nsx_mlx_new_window(void	*mlx_ptr, int win_x, int win_y, const char *win_title)
{
	return (mlx_new_window(mlx_ptr, win_x, win_y, (char *)win_title));
}

int	_nsx_mlx_loop(void *mlx_ptr)
{
	return (mlx_loop(mlx_ptr));
}

int		_nsx_new_color(const char r, const char g, const char b)
{
	int	color;

	color = (color << 16) + r;
	color = (color << 8) + g;
	color += b;
	return (color);
}

int	_nsx_mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, const char *string)
{
	return (mlx_string_put(mlx_ptr, win_ptr, x, y, color, (char *)string));
}