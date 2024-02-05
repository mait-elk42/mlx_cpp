/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:41:11 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/14 10:22:35 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newmphead;
	t_list	*node;
	void	*content;

	newmphead = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&newmphead, del);
			return (0);
		}
		ft_lstadd_back(&newmphead, node);
		lst = lst->next;
	}
	return (newmphead);
}
