/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:22:07 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/05 19:38:29 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H
#include <mlx.h>
#include <fcntl.h>
#include <libft.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <keys.h>
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_image
{
	unsigned char	*data;
	int				height;
	int				width;
	int				colorstype;
} t_image;

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	tex;
} t_mlx_info;

typedef struct s_vector2
{
	int		x;
	int		y;
} t_vector2;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
} t_color;


#endif