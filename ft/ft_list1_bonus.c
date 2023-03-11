/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:56:31 by tkong             #+#    #+#             */
/*   Updated: 2023/03/02 12:22:16 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_lstadd_back(t_ll **lst, t_ll *new_)
{
	if (*lst)
		ft_lstlast(*lst)->next = new_;
	else
		*lst = new_;
}

void	ft_lstadd_front(t_ll **lst, t_ll *new_)
{
	new_->next = *lst;
	*lst = new_;
}

void	ft_lstclear(t_ll **lst, void (*del)(void *))
{
	t_ll	*cur;

	while (*lst)
	{
		cur = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(cur, del);
	}
}

void	ft_lstdelone(t_ll *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstiter(t_ll *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
