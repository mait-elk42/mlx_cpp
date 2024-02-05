/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:41:51 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/04 10:37:52 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_nsx_ptrlenght(unsigned long ptr)
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

int	_prt_pointer(unsigned long ptr)
{
	int		len;
	char	*res;

	if (ptr == 0)
		return (_prt_str("0x0"));
	len = _nsx_ptrlenght(ptr);
	res = malloc(len + 1);
	if (!res)
		return (-1);
	res[len--] = '\0';
	while (ptr)
	{
		res[len--] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
	}
	if (_prt_str("0x") == -1)
	{
		free (res);
		return (-1);
	}
	len = _prt_str(res);
	free(res);
	if (len == -1)
		return (-1);
	return (len + 2);
}
