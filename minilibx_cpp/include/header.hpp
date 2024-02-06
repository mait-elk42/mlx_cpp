/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:45:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/06 20:25:27 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP
extern "C"
{
	typedef struct s_image
	{
		unsigned char		*buffer;
		int					width;
		int					height;
		int					channels;
		char				type;
	} t_image;

	typedef struct s_vector2
	{
		int	x;
		int	y;
	} t_vector2;

	typedef struct s_mlx
	{
		void	*mlx_ptr;
		void	*win_ptr;
	} t_mlx;

	void	*_nsx_mlx_init();
	void	*_nsx_mlx_new_window(void	*mlx_ptr, int win_x, int win_y, const char *win_title);
	int		_nsx_mlx_loop(void *mlx_ptr);
	int		_nsx_mlx_loop_hook(void	*mlx_ptr, int (*f)(void *), void *param);
	int		_nsx_new_color(const unsigned char r, const unsigned char g, const unsigned char b);
	int		_nsx_mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, const char *string);
	int		_nsx_mlx_destroy_window(void *mlx_ptr, void *win_ptr);
	int		_nsx_mlx_xpm_file_to_image(void *mlx_ptr, const char *filename, t_image *output);
	int		_nsx_mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, t_image image, t_vector2 position);
	int		_nsx_mlx_png_file_to_image(void *mlx_ptr, const char *filename, t_image *output);
}
#endif