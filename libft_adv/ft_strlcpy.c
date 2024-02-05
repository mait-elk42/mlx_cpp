/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:09:29 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/11 19:38:06 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	while (src[len] && len + 1 < dstsize)
	{
		dst[len] = src[len];
		len++;
	}
	if (dstsize > 0)
		dst[len] = '\0';
	while (src[len])
		len++;
	return (len);
}
