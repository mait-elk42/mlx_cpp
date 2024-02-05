/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cpp_api.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:51:12 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/05 20:00:45 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	*_nsx_mlx_init()
{
	return (mlx_init());
}

void	*_nsx_mlx_new_window(void	*mlx_ptr)
{
	return (_nsx_mlx_new_window(mlx_ptr));
}