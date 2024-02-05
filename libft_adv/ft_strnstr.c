/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:14:45 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/14 09:58:13 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_nsx_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_of_needle;

	len_of_needle = 0;
	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	len_of_needle = ft_strlen(needle);
	while (*haystack && len)
	{
		if (*haystack == *needle)
		{
			if (_nsx_strncmp(haystack, needle, len_of_needle)
				&& (len_of_needle <= len))
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
