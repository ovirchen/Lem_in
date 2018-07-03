/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:47:01 by ovirchen          #+#    #+#             */
/*   Updated: 2018/03/04 14:47:02 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "../libftprintf/libftprintf.h"

typedef struct	s_room
{
	int				x;
	int				y;
	int				ant;
	int				visit;
	char			*name;
	int				num;
	struct s_room	*next;
	struct s_room	*from;
	void			*near;
}				t_room;

typedef struct	s_near
{
	t_room			*room;
	struct s_near	*next;
}				t_near;

typedef struct	s_all
{
	int		rooms;
	int		ants;
	t_room	*list_rooms;
	int		start;
	int		end;
	char	*str;

}				t_all;

int				ft_error(void);
int				parser(t_all *all);
int				check_rooms(t_all **all, char **line, int *i);
int				check_near(t_room *tmp, t_room *new);
t_near			*find_way(t_all all);
void			print_way(t_all all, t_near *way);
void			free_split(char ***split);
void			free_t_near(t_near **head);
void			free_all(t_all *all);

#endif
