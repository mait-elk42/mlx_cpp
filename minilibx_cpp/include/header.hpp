/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:45:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/05 20:01:23 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP
extern "C"
{
	void	*_nsx_mlx_init();
	void	*_nsx_mlx_new_window(void *mlx_ptr);
}
#endif