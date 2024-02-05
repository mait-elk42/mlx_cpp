/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:36:27 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/13 21:56:33 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(ft_strlen(s1) + 1);
	if (!res)
		return (0);
	while (*s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
