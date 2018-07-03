/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:39:26 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/21 16:39:27 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_chars(unsigned int c, t_flags flag, char **print_str)
{
	if (flag.flag_2 > 99 && flag.flag_2 < 1000)
	{
		ft_chars_uni(c, flag, print_str);
		return ;
	}
	if (flag.f1_minus == 1)
	{
		if (c != 0)
			join_char(print_str, c);
		else
			join_char(print_str, -125);
	}
	if (flag.f1_zero == 1 && flag.width > 1)
		while ((flag.width)-- > 1)
			join_and_free(print_str, "0");
	else if (!(flag.f1_zero == 1) && flag.width > 1)
		while ((flag.width)-- > 1)
			join_and_free(print_str, " ");
	if (!(flag.f1_minus == 1))
	{
		if (c != 0)
			join_char(print_str, c);
		else
			join_char(print_str, -125);
	}
}

static void	ft_2bit(unsigned int c, t_flags flag, char **print_str)
{
	if (flag.f1_minus == 1)
	{
		join_char(print_str, ((c >> 6) | 0xC0));
		join_char(print_str, (((c << 26) >> 26) | 0x80));
	}
	if (flag.f1_zero == 1 && flag.width > 2)
		while ((flag.width)-- > 2)
			join_and_free(print_str, "0");
	else if (!(flag.f1_zero == 1) && flag.width > 2)
		while ((flag.width)-- > 2)
			join_and_free(print_str, " ");
	if (!(flag.f1_minus == 1))
	{
		join_char(print_str, ((c >> 6) | 0xC0));
		join_char(print_str, (((c << 26) >> 26) | 0x80));
	}
}

static void	ft_3bit(unsigned int c, t_flags flag, char **print_str)
{
	if (flag.f1_minus == 1)
	{
		join_char(print_str, ((c >> 12) | 0xE0));
		join_char(print_str, (((c << 20) >> 26) | 0x80));
		join_char(print_str, (((c << 26) >> 26) | 0x80));
	}
	if (flag.f1_zero == 1 && flag.width > 3)
		while ((flag.width)-- > 3)
			join_and_free(print_str, "0");
	else if (!(flag.f1_zero == 1) && flag.width > 3)
		while ((flag.width)-- > 3)
			join_and_free(print_str, " ");
	if (!(flag.f1_minus == 1))
	{
		join_char(print_str, ((c >> 12) | 0xE0));
		join_char(print_str, (((c << 20) >> 26) | 0x80));
		join_char(print_str, (((c << 26) >> 26) | 0x80));
	}
}

static void	ft_4bit(unsigned int c, t_flags flag, char **print_str)
{
	if (flag.f1_minus == 1)
	{
		join_char(print_str, ((c >> 18) | 0xF0));
		join_char(print_str, (((c << 14) >> 26) | 0x80));
		join_char(print_str, (((c << 20) >> 26) | 0x80));
		join_char(print_str, (((c << 26) >> 26) | 0x80));
	}
	if (flag.f1_zero == 1 && flag.width > 4)
		while ((flag.width)-- > 4)
			join_and_free(print_str, "0");
	else if (!(flag.f1_zero == 1) && flag.width > 4)
		while ((flag.width)-- > 4)
			join_and_free(print_str, " ");
	if (!(flag.f1_minus == 1))
	{
		join_char(print_str, ((c >> 18) | 0xF0));
		join_char(print_str, (((c << 14) >> 26) | 0x80));
		join_char(print_str, (((c << 20) >> 26) | 0x80));
		join_char(print_str, (((c << 26) >> 26) | 0x80));
	}
}

void		ft_chars_uni(unsigned int c, t_flags flag, char **print_str)
{
	if (MB_CUR_MAX != 4)
	{
		join_char(print_str, c);
		return ;
	}
	if (c <= 0x7F)
	{
		if (c != 0)
			join_char(print_str, c);
		else
			join_char(print_str, -125);
	}
	else if (c <= 0x7FF)
		ft_2bit(c, flag, print_str);
	else if (c <= 0xFFFF)
		ft_3bit(c, flag, print_str);
	else if (c <= 0x1FFFFF)
		ft_4bit(c, flag, print_str);
}
