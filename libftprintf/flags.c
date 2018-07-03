/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:23:12 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/14 18:23:13 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_flag_1(char **str, t_flags *flag)
{
	char	*s;

	s = *str;
	while (*s == '-' || *s == '+' || *s == ' ' || *s == '#' || *s == '0')
	{
		if (*s == '-' && flag->f1_zero == 1 && (flag->f1_minus = 1))
			flag->f1_zero = 0;
		else if (*s == '+' && flag->f1_space == 1 && (flag->f1_plus = 1))
			flag->f1_space = 0;
		else if (!(*s == '0' && flag->f1_minus == 1) &&
			!(*s == ' ' && flag->f1_plus == 1))
		{
			if (*s == '-')
				flag->f1_minus = 1;
			else if (*s == '+')
				flag->f1_plus = 1;
			else if (*s == ' ')
				flag->f1_space = 1;
			else if (*s == '#')
				flag->f1_hesh = 1;
			else if (*s == '0')
				flag->f1_zero = 1;
		}
		*str = ++s;
	}
}

int			ft_flag_2(char **str)
{
	int		flag_2;
	char	*s;

	s = *str;
	flag_2 = 0;
	while (*s && (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z'))
	{
		if (*s == 'h' && *(s - 1) == 'h')
			flag_2 -= 9;
		else if (*s == 'h' && *(s - 1) != 'h')
			flag_2 += 10;
		else if (*s == 'l' && *(s - 1) != 'l')
			flag_2 += 100;
		else if (*s == 'l' && *(s - 1) == 'l')
			flag_2 += 1000;
		else if (*s == 'j')
			flag_2 += 10000;
		else if (*s == 'z')
			flag_2 += 100000;
		s++;
		if (*s == ' ')
			s++;
	}
	*str = s;
	return (flag_2);
}

static char	*ft_join_zero(char *n, ssize_t count, size_t *len, char c)
{
	char *tmp;

	if (c != 'x' && c != 'X')
		while (count > (ssize_t)*len)
		{
			tmp = n;
			n = ft_strjoin("0", n);
			free(tmp);
			*len += 1;
		}
	else if (!(n[0] == '0' && n[1] == '\0'))
	{
		tmp = n;
		if (c == 'X')
			n = ft_strjoin("0X", n);
		else
			n = ft_strjoin("0x", n);
		free(tmp);
		*len += 2;
	}
	return (n);
}

char		*ft_add_zero(char *n, t_flags flag, char str, size_t *len)
{
	int		i;

	i = 0;
	if (flag.prec > (ssize_t)*len)
		n = ft_join_zero(n, flag.prec, len, '0');
	if (flag.width > *len && flag.prec == -1 && flag.f1_zero == 1)
		n = ft_join_zero(n, flag.width, len, '0');
	if (flag.f1_hesh == 1 && (str == 'o' || str == 'O')
		&& flag.prec != 0 && !(n[0] == '0'))
		n = ft_join_zero(n, *len + 1, len, '0');
	else if (flag.f1_hesh == 1 && (str == 'x' || str == 'X'))
	{
		if (n[i] == '0' && flag.width == *len)
		{
			while (n[i] && n[i] == '0')
				i++;
			if (n[i] != '\0' && i >= 2)
				n[1] = str;
			else if (n[i] != '\0' && i == 1 && (n[0] = str))
				n = ft_join_zero(n, *len + 1, len, '0');
		}
		else
			n = ft_join_zero(n, 0, len, str);
	}
	return (n);
}
