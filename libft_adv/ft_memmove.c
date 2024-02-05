/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:10:54 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/13 20:50:41 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*_dst;
	unsigned char		*_src;

	if (! dst && ! src)
		return (0);
	_dst = (unsigned char *)dst;
	_src = (unsigned char *)src;
	if (dst > src)
	{
		while (len--)
			_dst[len] = _src[len];
	}
	else
	{
		_dst = ft_memcpy(dst, src, len);
	}
	return (_dst);
}
