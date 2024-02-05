/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:33 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/13 11:50:02 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_nsx_isset(char c, const char *list)
{
	while (*list)
	{
		if (*list == c)
			return (1);
		list++;
	}
	return (0);
}

size_t	_nsx_getit(const char *str, int is_start, const char *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (is_start == 1)
	{
		while (_nsx_isset(str[i], set))
			i++;
		return (i);
	}
	else if (is_start == 0)
	{
		len -= 1;
		while (_nsx_isset(str[len], set))
			len--;
		return (len);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	start = _nsx_getit(s1, 1, set);
	end = _nsx_getit(s1, 0, set) + 1;
	if (!s1[start])
		return (ft_strdup(""));
	res = malloc(end - start + 1);
	if (!res)
		return (0);
	while (start < end)
	{
		res[i] = s1[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
