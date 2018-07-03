/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:14:32 by ovirchen          #+#    #+#             */
/*   Updated: 2018/03/04 15:14:34 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	get_rooms(t_all **all, char **line, int i)
{
	int		check;

	if (*line)
		ft_strdel(line);
	if (get_next_line(0, line) != 1)
		return (0);
	join_and_free(&((*all)->str), *line);
	join_and_free(&((*all)->str), "\n");
	if (ft_strcmp(*line, "##start") == 0)
	{
		if ((*all)->start != 0)
			return (0);
		(*all)->start = i--;
	}
	else if (ft_strcmp(*line, "##end") == 0)
	{
		if ((*all)->end != 0)
			return (0);
		(*all)->end = i--;
	}
	else if ((*line)[0] == '#')
		return (get_rooms(all, line, i));
	else if ((check = check_rooms(all, line, &i)) == 0 || check == 1)
		return (check);
	return (get_rooms(all, line, ++i));
}

static int	make_ways(t_room **tmp, int *count, char **split)
{
	t_room	*new;
	t_near	*ex;

	if (ft_strcmp((*tmp)->name, split[0]) == 0 ||
		ft_strcmp((*tmp)->name, split[1]) == 0)
	{
		if (*count == 0)
			new = (*tmp);
		else if (check_near(*tmp, new))
		{
			if ((ex = (t_near*)malloc(sizeof(t_near))) == NULL)
				return (0);
			ex->next = new->near;
			ex->room = (*tmp);
			new->near = ex;
			if ((ex = (t_near*)malloc(sizeof(t_near))) == NULL)
				return (0);
			ex->next = (*tmp)->near;
			ex->room = new;
			(*tmp)->near = ex;
		}
		(*count)++;
	}
	return (1);
}

static int	add_ways(t_all **all, char **line, int *count)
{
	char	**split;
	t_room	*tmp;
	int		j;

	if ((split = ft_strsplit(*line, '-')) == NULL)
		return (0);
	j = 0;
	while (split[j])
		j++;
	if ((tmp = (*all)->list_rooms) && j != 2)
	{
		free_split(&split);
		return (0);
	}
	while (tmp && *count != 2)
	{
		if (make_ways(&tmp, count, split) == 0)
		{
			free_split(&split);
			return (0);
		}
		tmp = tmp->next;
	}
	free_split(&split);
	return (1);
}

static int	get_ways(t_all **all, char **line)
{
	int		count;
	int		gnl;

	if ((*all)->start == 0 || (*all)->end == 0 || (*all)->list_rooms->num
		!= (*all)->rooms || (*all)->start == (*all)->end || (*all)->start
		> (*all)->rooms || (*all)->end > (*all)->rooms)
		return (0);
	count = 2;
	if ((*line)[0] != '#' && !(count = 0) && add_ways(all, line, &count) == 0)
		return (0);
	else if (ft_strcmp(*line, "##start") == 0 || ft_strcmp(*line, "##end") == 0)
		return (0);
	ft_strdel(line);
	if (count != 2 || (gnl = get_next_line(0, line)) == -1)
		return (0);
	if (gnl == 0 || ft_strcmp(*line, "") == 0)
	{
		ft_strdel(line);
		return (1);
	}
	join_and_free(&((*all)->str), *line);
	join_and_free(&((*all)->str), "\n");
	return (get_ways(all, line));
}

int			parser(t_all *all)
{
	char	*line;

	if (get_next_line(0, &line) != 1)
		return (0);
	join_and_free(&(all->str), line);
	join_and_free(&(all->str), "\n");
	if (line[0] == '#' && ft_strcmp(line, "##start") &&
		ft_strcmp(line, "##end"))
	{
		ft_strdel(&line);
		return (parser(all));
	}
	if (ft_strisnum(line) == 0 || (all->ants = ft_atoi(line)) == 0)
		return (0);
	ft_strdel(&line);
	all->start = 0;
	all->end = 0;
	if (get_rooms(&all, &line, 1) != 1 || get_ways(&all, &line) != 1)
		return (0);
	if (line)
		ft_strdel(&line);
	return (1);
}
