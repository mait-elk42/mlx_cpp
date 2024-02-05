/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:59:31 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/04 11:25:47 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	slen;

	if (!s || !f)
		return ;
	i = 0;
	slen = ft_strlen(s);
	while (i < slen)
	{
		f (i, &((char *)(s))[i]);
		i++;
	}
}
