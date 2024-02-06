/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:45:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/06 16:37:08 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP
extern "C"
{
	void	*_nsx_mlx_init();
	void	*_nsx_mlx_new_window(void	*mlx_ptr, int win_x, int win_y, const char *win_title);
	int		_nsx_mlx_loop(void *mlx_ptr);
	int		_nsx_new_color(const char r, const char g, const char b);
	int		_nsx_mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, const char *string);
}
#endif