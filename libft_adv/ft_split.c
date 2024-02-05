/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:32:55 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/13 14:25:59 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	_nsx_wordc(const char *str, char btwn)
{
	size_t	wc;

	wc = 0;
	if (*str && *str != btwn)
		wc++;
	while (*str)
	{
		if (*str && *str == btwn)
		{
			while (*str && *str == btwn)
				str++;
			if (*str && *str != btwn)
				wc++;
		}
		else
		{
			str++;
		}
	}
	return (wc);
}

static void	_nsx_skipc(char **s, char c)
{
	while (**s && **s == c)
	{
		(*s)++;
	}
}

static char	*_nsx_newstr(char **src, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(len + 1);
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = **src;
		i++;
		(*src)++;
	}
	res[i] = '\0';
	return (res);
}

static char	**_nsx_fillarr(char **res, size_t wordc, char *s, char c)
{
	size_t	w;
	size_t	len_word;

	w = 0;
	len_word = 0;
	while (w < wordc)
	{
		_nsx_skipc(&s, c);
		len_word = 0;
		while (s[len_word] && s[len_word] != c)
			len_word++;
		res[w] = _nsx_newstr(&s, len_word);
		if (!res[w])
		{
			while (w--)
				free(res[w]);
			free(res);
			return (0);
		}
		w++;
	}
	res[w] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	wordc;
	char	**res;

	if (!s)
		return (0);
	wordc = _nsx_wordc(s, c);
	res = malloc((wordc + 1) * sizeof(char **));
	if (!res)
		return (0);
	res = _nsx_fillarr(res, wordc, (char *)s, c);
	return (res);
}
