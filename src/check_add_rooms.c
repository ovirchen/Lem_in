/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:47:37 by ovirchen          #+#    #+#             */
/*   Updated: 2018/05/07 16:47:40 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	malloc_new(t_room **new, char **split, int i)
{
	if (!(*new = (t_room*)malloc(sizeof(t_room))))
		return (0);
	(*new)->num = i;
	(*new)->name = ft_strdup(split[0]);
	(*new)->x = ft_atoi(split[1]);
	(*new)->y = ft_atoi(split[2]);
	(*new)->near = NULL;
	(*new)->from = NULL;
	(*new)->visit = 0;
	(*new)->ant = 0;
	return (1);
}

static int	add_list_rooms(t_all **all, char **line, int i, char **split)
{
	t_room	*new;
	t_room	*tmp;

	if (ft_strisnum(split[1]) == 0 || ft_strisnum(split[2]) == 0 ||
		split[0][0] == 'L' || malloc_new(&new, split, i) == 0)
		return (0);
	if ((*all)->list_rooms == NULL && !(new->next = NULL))
		(*all)->list_rooms = new;
	else
	{
		tmp = (*all)->list_rooms;
		while (tmp)
		{
			if (ft_strcmp(tmp->name, new->name) == 0 || (tmp->x == new->x &&
				tmp->y == new->y))
				return (0);
			tmp = tmp->next;
		}
		new->next = (*all)->list_rooms;
		(*all)->list_rooms = new;
	}
	return (1);
}

int			check_rooms(t_all **all, char **line, int *i)
{
	char	**split;
	int		j;

	split = ft_strsplit(*line, ' ');
	j = 0;
	while (split[j])
		j++;
	if (j == 1 && ft_strchr(*line, '-') != NULL)
	{
		(*all)->rooms = --(*i);
		free_split(&split);
		return (1);
	}
	else if (j != 3 || add_list_rooms(all, line, *i, split) != 1)
	{
		free_split(&split);
		return (0);
	}
	free_split(&split);
	return (2);
}

int			check_near(t_room *tmp, t_room *new)
{
	t_near *tmp_near;

	tmp_near = (t_near*)tmp->near;
	while (tmp_near)
	{
		if (tmp_near->room->num == new->num)
			return (0);
		tmp_near = tmp_near->next;
	}
	return (1);
}
