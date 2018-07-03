/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:58:07 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/30 17:58:08 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlst;
	t_list *new;

	if (lst && f)
	{
		nlst = (t_list*)malloc(sizeof(t_list));
		if (nlst)
		{
			nlst = (*f)(lst);
			if (!ft_lstnew(nlst->content, nlst->content_size))
				return (NULL);
			new = nlst;
			lst = lst->next;
			while (lst)
			{
				new->next = (*f)(lst);
				if (!ft_lstnew(new->next->content, new->next->content_size))
					return (NULL);
				new = new->next;
				lst = lst->next;
			}
			return (nlst);
		}
	}
	return (NULL);
}
