/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:58:58 by ovirchen          #+#    #+#             */
/*   Updated: 2018/03/04 13:58:59 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_error(void)
{
	write(1, "ERROR\n", 6);
	return (0);
}

int			main(void)
{
	t_all	all;
	t_near	*way;

	all.str = NULL;
	if (parser(&all) != 1)
	{
		free_all(&all);
		return (ft_error());
	}
	else
	{
		if ((way = find_way(all)) == NULL)
		{
			free_all(&all);
			return (ft_error());
		}
		ft_printf("%s\n", all.str);
		print_way(all, way);
	}
	free_t_near(&way);
	free_all(&all);
	return (0);
}
