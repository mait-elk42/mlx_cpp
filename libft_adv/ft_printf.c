/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:52 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/04 10:54:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_handle_this(char c, va_list list)
{
	if (c == 'c')
		return (_prt_char(va_arg(list, int)));
	else if (c == 's')
		return (_prt_str(va_arg(list, char *)));
	else if (c == 'd' || c == 'i')
		return (_prt_int(va_arg(list, int)));
	else if (c == 'u')
		return (_prt_uint(va_arg(list, unsigned int)));
	else if (c == 'x')
		return (_prt_uinthex(va_arg(list, unsigned int), 'x'));
	else if (c == 'X')
		return (_prt_uinthex(va_arg(list, unsigned int), 'X'));
	else if (c == 'p')
		return (_prt_pointer(va_arg(list, unsigned long)));
	else if (c == '%')
		return (_prt_char('%'));
	else if (c == '\0')
		return (0);
	return (_prt_char(c));
}

static int	handle_err(char c, int ret, int length)
{
	if (!c)
	{
		return (length);
	}
	else if (ret == -1)
	{
		return (-1);
	}
	else
		return (99);
}

int	ft_printf(const char	*s, ...)
{
	int		ret;
	int		length;
	va_list	list;

	length = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ret = _handle_this(*s, list);
		}
		else
			ret = _prt_char(*s);
		if (handle_err(*s, ret, length) != 99)
		{
			va_end(list);
			return (handle_err(*s, ret, length));
		}
		length += ret;
		s++;
	}
	va_end(list);
	return (length);
}
