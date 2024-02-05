/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:50:42 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/19 21:50:50 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	__nsx_get_bytes_ineed(long long n)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (n)
	{
		n /= 2;
		i++;
	}
	while ((i % 8) != 0)
		i++;
	while (i)
	{
		i -= 8;
		res++;
	}
	return (res);
}

char	*__nsx_getbits(long long num)
{
	int		bc;
	char	*bits;

	bc = __nsx_get_bytes_ineed(num) * 8;
	bits = malloc(bc + 1);
	if (!bits)
		return (0);
	bits[bc] = '\0';
	while (bc--)
	{
		bits[bc] = (num & 1) + 48;
		num >>= 1;
	}
	return (bits);
}

int	_nsx_putbits(long long number)
{
	int		i;
	char	*bits;

	i = 0;
	if (number == 0)
		return (ft_printf("00000000") * 0 + 1);
	bits = __nsx_getbits(number);
	if (!bits)
		return (-1);
	while (bits[i])
	{
		if ((i % 8) == 0 && i != 0)
			ft_printf(" ");
		ft_printf("%c", bits[i]);
		i++;
	}
	return (1);
}
