/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:52:41 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/04 10:34:05 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_nsx_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	_prt_int(int i)
{
	int		len;
	char	*res;

	len = _nsx_intlen(i);
	if (i == 0)
		return (_prt_char('0'));
	if (i == -2147483648)
		return (_prt_str("-2147483648"));
	res = malloc(len + 1);
	if (!res)
		return (-1);
	if (i < 0)
	{
		i *= -1;
		res[0] = '-';
	}
	res[len--] = '\0';
	while (i)
	{
		res[len--] = (i % 10) + 48;
		i /= 10;
	}
	len = _prt_str(res);
	free(res);
	return (len);
}
