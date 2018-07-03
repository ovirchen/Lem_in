/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:22:20 by exam              #+#    #+#             */
/*   Updated: 2017/10/13 16:03:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	unsize(size_t value, int base, int sign)
{
	size_t size;

	size = 1;
	while (value >= (size_t)base)
	{
		size++;
		value = value / base;
	}
	if (sign == -1)
		size++;
	return (size);
}

static char		*stsize(long long int value, int base, int sign, char *tab)
{
	ssize_t size;
	char	*res;
	size_t	val;

	size = 1;
	val = (size_t)value;
	while (val >= (size_t)base)
	{
		size++;
		val = val / base;
	}
	if (sign == -1)
		size++;
	res = (char *)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	while (--size >= 0)
	{
		res[size] = tab[value % base];
		value = value / base;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}

static char		*ft_res(size_t value, int base, int sign, char *tab)
{
	ssize_t	size;
	char	*res;

	size = unsize(value, base, sign);
	res = (char *)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	while (--size >= 0)
	{
		res[size] = tab[value % base];
		value = value / base;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}

char			*ft_itoa_base(long long int value, char x)
{
	char	*tab;
	int		sign;
	int		base;

	sign = 1;
	base = 10;
	if (value < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (x == 'o' || x == 'O')
		base = 8;
	else if (x == 'x' || x == 'X')
		base = 16;
	if (value < 0 && (x == 'd' || x == 'D' || x == 'i' || x == 'I'))
	{
		sign = -1;
		value = -value;
	}
	tab = "0123456789abcdef";
	if (x == 'X')
		tab = "0123456789ABCDEF";
	return (stsize(value, base, sign, tab));
}

char			*ft_itoa_base_unsigned(size_t value, char x)
{
	char			*tab;
	int				base;

	if (x == 'o' || x == 'O')
		base = 8;
	else if (x == 'x' || x == 'X')
		base = 16;
	else
		base = 10;
	tab = "0123456789ABCDEF";
	if (x == 'x')
		tab = "0123456789abcdef";
	return (ft_res(value, base, 1, tab));
}
