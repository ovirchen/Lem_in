/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:26:14 by ovirchen          #+#    #+#             */
/*   Updated: 2017/11/19 19:26:16 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_stat	*add_list(t_stat **list, const int fd)
{
	t_stat	*new;

	new = (t_stat*)malloc(sizeof(t_stat));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->str = ft_strnew(BUFF_SIZE);
	if (!list)
	{
		list = (t_stat**)malloc(sizeof(t_stat*));
		if (!list)
			return (NULL);
		*list = new;
		new->next = NULL;
	}
	else
	{
		new->next = *list;
		*list = new;
	}
	return (new);
}

static t_stat	*find_fd(t_stat **list, const int fd)
{
	t_stat	*tmp;

	if (list)
	{
		tmp = *list;
		while (tmp)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (add_list(list, fd));
}

static int		read_file(const int fd, t_stat *node, char **tmp)
{
	char	*buf;
	char	*tmp2;
	int		ret;
	int		i;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	ret = 1;
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp2 = node->str;
		node->str = ft_strjoin(node->str, buf);
		free(tmp2);
		free(buf);
		if (++i && (*tmp = ft_strchr(node->str, '\n'))
			&& !(*tmp[0] = '\0'))
			break ;
		if (!(buf = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	if (i == 0 || ret == 0)
		free(buf);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_stat	*list;
	t_stat			*node;
	char			*tmp;
	char			*buf;
	int				ret;

	if (!(ret = -2) || !line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	node = find_fd(&list, fd);
	if (!(tmp = ft_strchr(node->str, '\n')) &&
		(ret = read_file(fd, node, &tmp)) == -1)
		return (-1);
	else if (ret == -2)
		tmp[0] = '\0';
	if (ret == 0 && ft_strequ(node->str, "") && !(*line = NULL))
		return (0);
	*line = ft_strdup(node->str);
	if (ret != 0 && (buf = node->str))
	{
		node->str = ft_strdup(++tmp);
		free(buf);
	}
	else if (ret == 0)
		ft_bzero(node->str, ft_strlen(node->str));
	return (1);
}
