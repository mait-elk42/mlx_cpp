/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:29:16 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/06 20:22:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H
#include <mlx.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

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
#endif