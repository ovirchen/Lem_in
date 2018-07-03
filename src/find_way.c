/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:25:09 by ovirchen          #+#    #+#             */
/*   Updated: 2018/05/08 13:25:11 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	check_queue(t_near *queue, int num)
{
	t_near	*list;

	list = queue;
	while (list)
	{
		if (list->room->num == num)
			return (0);
		list = list->next;
	}
	return (1);
}

static int	make_queue(t_near **tmp, t_near **list, t_near **tail, t_near **que)
{
	t_near	*new;

	if ((*tmp)->room->visit == 0 && check_queue(*que, (*tmp)->room->num))
	{
		(*tmp)->room->from = (*list)->room;
		if ((new = (t_near*)malloc(sizeof(t_near))) == NULL)
			return (0);
		new->next = NULL;
		new->room = (*tmp)->room;
		(*tail)->next = new;
		(*tail) = (*tail)->next;
	}
	return (1);
}

static int	find_way_continue(t_near **que, t_all all)
{
	t_near	*tmp;
	t_near	*tail;
	t_near	*list;

	list = *que;
	tail = *que;
	while (tail->next)
		tail = tail->next;
	while (list)
	{
		if (list->room->num == all.end)
			return (1);
		if (list->room->visit == 0 && (list->room->visit = 1))
		{
			tmp = list->room->near;
			while (tmp)
			{
				if (make_queue(&tmp, &list, &tail, que) == 0)
					return (0);
				tmp = tmp->next;
			}
		}
		list = list->next;
	}
	return (0);
}

static int	make_way(t_all all, t_near **way)
{
	t_near	*tail;
	t_room	*tmp;
	t_near	*new;

	tmp = all.list_rooms;
	while (tmp->num != all.end)
		tmp = tmp->next;
	if (((*way) = (t_near*)malloc(sizeof(t_near))) == NULL)
		return (0);
	(*way)->next = NULL;
	(*way)->room = tmp;
	tail = (*way);
	while (tail->room->num != all.start)
	{
		if ((new = (t_near*)malloc(sizeof(t_near))) == NULL)
			return (0);
		new->next = NULL;
		new->room = tail->room->from;
		tail->next = new;
		tail = tail->next;
	}
	return (1);
}

t_near		*find_way(t_all all)
{
	t_near	*que;
	t_near	*way;
	t_room	*tmp;

	tmp = all.list_rooms;
	while (tmp->num != all.start)
		tmp = tmp->next;
	if ((que = (t_near*)malloc(sizeof(t_near))) == NULL)
		return (0);
	que->next = NULL;
	que->room = tmp;
	if (find_way_continue(&que, all) != 1)
	{
		free_t_near(&que);
		return (NULL);
	}
	free_t_near(&que);
	if (make_way(all, &way) == 0)
		return (0);
	return (way);
}
