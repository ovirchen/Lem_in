/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:26:53 by ovirchen          #+#    #+#             */
/*   Updated: 2018/05/09 14:26:54 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_ants(t_all all, t_near **way, t_near **prev, t_room **start)
{
	while (*way && (*way)->room->ant != 0 && (*way)->room->num != all.start)
	{
		if ((*way)->room->num != all.end)
		{
			ft_printf("L%d-%s ", (*way)->room->ant, (*prev)->room->name);
			(*prev)->room->ant = (*way)->room->ant;
		}
		(*prev) = (*way);
		(*way) = (*way)->next;
	}
	if ((*way)->room->num == all.start && (*way)->room->ant != 0)
	{
		(*start)->ant -= 1;
		ft_printf("L%d-%s ", all.ants - (*start)->ant, (*prev)->room->name);
		(*prev)->room->ant = all.ants - (*start)->ant;
	}
	else if ((*way)->room->ant == 0)
	{
		(*prev)->room->ant = 0;
	}
}

void		print_way(t_all all, t_near *way)
{
	t_room *start;
	t_near *end;
	t_near *prev;

	start = all.list_rooms;
	while (start->num != all.start)
		start = start->next;
	start->ant = all.ants;
	end = way;
	while (end->room->ant != all.ants)
	{
		way = end;
		while (way->room->ant == 0)
		{
			prev = way;
			way = way->next;
		}
		print_ants(all, &way, &prev, &start);
		ft_printf("\n");
	}
}
