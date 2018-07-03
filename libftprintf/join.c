/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:41:49 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/22 13:41:51 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	join_and_free(char **s1, char *s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = ft_strjoin(*s1, s2);
	free(tmp);
}

void	join_char(char **s1, unsigned int c)
{
	char s[2];
	char *tmp;

	s[1] = '\0';
	s[0] = c;
	tmp = *s1;
	*s1 = ft_strjoin(*s1, s);
	free(tmp);
}

char	*join_first(char *s1, char *n)
{
	char	*tmp;

	tmp = n;
	n = ft_strjoin(s1, n);
	free(tmp);
	return (n);
}

void	check_zero_char(char **s1)
{
	char	*s;

	s = *s1;
	while (*s != '\0')
	{
		if (*s == -125)
			*s = '\0';
		s++;
	}
}
