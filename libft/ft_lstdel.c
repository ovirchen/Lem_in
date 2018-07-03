/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:30:34 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/30 17:30:35 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nnext;

	if (*alst && del)
	{
		lst = *alst;
		while (lst)
		{
			nnext = lst->next;
			(*del)(lst->content, lst->content_size);
			free(lst);
			lst = nnext;
		}
		*alst = NULL;
	}
}
