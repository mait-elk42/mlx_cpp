/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:57:42 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/13 11:08:59 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_nsx_intlen(int n)
{
	int	r;

	r = 0;
	while (n)
	{
		r++;
		n /= 10;
	}
	return (r);
}

static char	*_nsx_numballoc(int n, int len, int is_negative)
{
	char	*res;

	if (is_negative)
		len++;
	res = malloc(len + 1);
	if (!res)
		return (0);
	if (is_negative)
	{
		n *= -1;
		res[0] = '-';
	}
	res[len] = '\0';
	while (len)
	{
		if (len == 1 && is_negative)
			break ;
		res[len -1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (_nsx_numballoc(n, _nsx_intlen(n), n < 0));
}
