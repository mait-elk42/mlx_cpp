/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:31:35 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/04 10:54:53 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*saver;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		saver = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = saver;
	}
}
