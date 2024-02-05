/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uinthex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:57:39 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/04 10:33:19 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_nsx_uintlen(unsigned int ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr /= 16;
	}
	return (i);
}

int	_prt_uinthex(unsigned int ptr,	char form)
{
	char	*base;
	int		len;
	char	*res;

	base = "0123456789abcdef";
	if (form == 'X')
		base = "0123456789ABCDEF";
	if (ptr == 0)
		return (_prt_char('0'));
	len = _nsx_uintlen(ptr);
	res = malloc(len + 1);
	if (!res)
		return (-1);
	res[len--] = '\0';
	while (ptr)
	{
		res[len] = base[ptr % 16];
		ptr /= 16;
		len--;
	}
	len = _prt_str(res);
	free(res);
	return (len);
}
