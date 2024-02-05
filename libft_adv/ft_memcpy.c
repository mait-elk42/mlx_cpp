/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:29:54 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/14 10:26:54 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*_dst;
	unsigned char	*_src;

	if (!dst && !src)
		return (0);
	_dst = (unsigned char *)dst;
	_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		_dst[i] = _src[i];
		i++;
	}
	return (_dst);
}
