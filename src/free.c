/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:03:26 by ovirchen          #+#    #+#             */
/*   Updated: 2018/05/09 18:03:27 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_split(char ***split)
{
	int i;

	if (split == NULL && *split)
		return ;
	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		i++;
	}
	free(*split);
}

void	free_t_near(t_near **head)
{
	t_near *tmp;
	t_near *list;

	if (head && *head)
	{
		list = *head;
		while (list)
		{
			tmp = list;
			list = list->next;
			free(tmp);
		}
	}
}

void	free_all(t_all *all)
{
	t_room	*room;
	t_room	*list;
	t_near	*tmp;
	t_near	*tmp_near;

	if (all->str)
		free(all->str);
	list = all->list_rooms;
	while (list)
	{
		room = list;
		list = list->next;
		tmp_near = (t_near*)room->near;
		while (tmp_near)
		{
			tmp = tmp_near;
			tmp_near = tmp_near->next;
			free(tmp);
		}
		free(room->name);
		free(room);
	}
}
