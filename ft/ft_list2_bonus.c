/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:56:34 by tkong             #+#    #+#             */
/*   Updated: 2023/03/02 12:22:16 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_ll	*ft_lstnew(void *content)
{
	t_ll	*elem;

	elem = (t_ll *) malloc(sizeof(t_ll));
	if (!elem)
		return (elem);
	elem->content = content;
	elem->next = (t_ll *) 0;
	return (elem);
}

t_i32	ft_lstsize(t_ll *lst)
{
	t_i32	len;

	len = 0;
	while (lst)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}

t_ll	*ft_lstlast(t_ll *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

t_ll	*ft_lstmap(t_ll *lst, void *(*f)(void *), void (*del)(void *))
{
	t_ll	*lst2;
	t_ll	*cur;

	lst2 = ft_lstnew(f(lst->content));
	lst = lst->next;
	cur = lst2;
	if (lst2)
	{
		while (lst)
		{
			cur->next = ft_lstnew(f(lst->content));
			cur = cur->next;
			lst = lst->next;
			if (cur)
				continue ;
			ft_lstclear(&lst2, del);
			break ;
		}
	}
	return (lst2);
}
