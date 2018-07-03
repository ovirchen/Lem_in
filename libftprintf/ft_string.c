/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:42:09 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/21 16:42:11 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	part_ft_strings(char *n, t_flags flag, char **print_str, int prec)
{
	if (flag.f1_minus == 1 && flag.prec == -1)
		join_and_free(print_str, n);
	else if (flag.f1_minus == 1 && flag.prec > 0)
		while ((flag.prec)-- > 0 && *n)
			join_char(print_str, *n++);
	if (flag.f1_zero == 1 && flag.width > 0)
		while ((flag.width)-- > (size_t)prec)
			join_and_free(print_str, "0");
	else
		while ((flag.width)-- > (size_t)prec)
			join_and_free(print_str, " ");
	if (!(flag.f1_minus == 1) && flag.prec == -1)
		join_and_free(print_str, n);
	else if (!(flag.f1_minus == 1) && flag.prec > 0)
		while (--prec >= 0 && *n)
			join_char(print_str, *n++);
}

void		ft_strings(char *n, t_flags flag, char **print_str)
{
	int		prec;
	size_t	len;

	if (n != NULL)
	{
		len = ft_strlen(n);
		prec = (int)flag.prec;
		if (flag.prec == -1 || len == 0)
			prec = 0;
		if (((size_t)prec > len || flag.prec == -1) && (flag.prec = -1))
			prec = len;
		part_ft_strings(n, flag, print_str, prec);
	}
	else
	{
		if (flag.f1_zero == 1 && flag.width > 0)
			while ((flag.width)-- > 0)
				join_and_free(print_str, "0");
		else
			join_and_free(print_str, "(null)");
	}
}

static void	add_unichar(unsigned int c, char **print_str)
{
	if (c <= 0x7F)
		join_char(print_str, c);
	else if (c <= 0x7FF)
	{
		join_char(print_str, ((c >> 6) | 0xC0));
		join_char(print_str, (((c << 26) >> 26) | 0x80));
	}
	else if (c <= 0xFFFF)
	{
		join_char(print_str, ((c >> 12) | 0xE0));
		join_char(print_str, (((c << 20) >> 26) | 0x80));
		join_char(print_str, (((c << 26) >> 26) | 0x80));
	}
	else if (c <= 0x1FFFFF)
	{
		join_char(print_str, ((c >> 18) | 0xF0));
		join_char(print_str, (((c << 14) >> 26) | 0x80));
		join_char(print_str, (((c << 20) >> 26) | 0x80));
		join_char(print_str, (((c << 26) >> 26) | 0x80));
	}
}

static void	part_ft_str_uni(unsigned int *n, t_flags flag, char **print_str,
	int prec)
{
	if (flag.f1_minus == 1 && flag.prec == -1)
		while (*n++ != '\0')
			add_unichar(*(n - 1), print_str);
	else if (flag.f1_minus == 1 && flag.prec > 0)
		while ((flag.prec)-- > ft_size_char(*n) && *n++ != '\0')
			add_unichar(*(n - 1), print_str);
	if (flag.f1_zero == 1 && flag.width > 0)
		while ((flag.width)-- > (size_t)prec)
			join_and_free(print_str, "0");
	else
		while ((flag.width)-- > (size_t)prec)
			join_and_free(print_str, " ");
	if (!(flag.f1_minus == 1) && flag.prec == -1)
		while (*n++ != '\0')
			add_unichar(*(n - 1), print_str);
	else if (!(flag.f1_minus == 1) && flag.prec > 0)
		while (--prec >= ft_size_char(*n) && *n++ != '\0')
			add_unichar(*(n - 1), print_str);
}

void		ft_strings_uni(unsigned int *n, t_flags flag, char **print_str)
{
	int		prec;
	size_t	len;

	if (n)
	{
		len = ft_strlen_uni(n);
		prec = (int)flag.prec;
		if (flag.prec == -1 || len == 0)
			prec = 0;
		if (((size_t)prec > len || flag.prec == -1) && (flag.prec = -1))
			prec = len;
		part_ft_str_uni(n, flag, print_str, prec);
	}
	else
		join_and_free(print_str, "(null)");
}
