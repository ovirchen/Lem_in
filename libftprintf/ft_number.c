/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:40:28 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/21 16:40:29 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*first_part_get_number(va_list ap, int flag_2, char str)
{
	if (flag_2 == 0 && str != 'D' && str != 'I')
		return (ft_itoa_base(va_arg(ap, int), str));
	else if (str == 'D' || str == 'I')
		return (ft_itoa_base(va_arg(ap, long int), str));
	else if (flag_2 < 10)
		return (ft_itoa_base((char)va_arg(ap, int), str));
	else if (flag_2 < 100)
		return (ft_itoa_base((short)va_arg(ap, int), str));
	else if (flag_2 < 1000)
		return (ft_itoa_base(va_arg(ap, long int), str));
	else if (flag_2 < 10000)
		return (ft_itoa_base(va_arg(ap, long long int), str));
	else if (flag_2 < 100000)
		return (ft_itoa_base(va_arg(ap, intmax_t), str));
	return (ft_itoa_base(va_arg(ap, size_t), str));
}

char		*get_number(va_list ap, int flag_2, char str)
{
	if (str == 'd' || str == 'i' || str == 'D' || str == 'I')
		return (first_part_get_number(ap, flag_2, str));
	if (str == 'O' || str == 'U')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned long int), str));
	else if (flag_2 == 0)
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned int), str));
	else if (flag_2 < 10)
		return (ft_itoa_base_unsigned((unsigned char)va_arg(ap, int), str));
	else if (flag_2 < 100)
		return (ft_itoa_base_unsigned((unsigned short)va_arg(ap, int), str));
	else if (flag_2 < 1000)
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned long int), str));
	else if (flag_2 < 10000)
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned long long), str));
	else if (flag_2 < 100000)
		return (ft_itoa_base_unsigned(va_arg(ap, uintmax_t), str));
	return (ft_itoa_base_unsigned(va_arg(ap, size_t), str));
}

static char	*ft_add_znak(char *n, t_flags flag, size_t *len)
{
	if (flag.f1_space == 1)
	{
		if (n[0] == '0' && n[1] != '\0' && (flag.prec != (ssize_t) * len))
			n[0] = ' ';
		else if (n[0] != '-' && (*len += 1))
			n = join_first(" ", n);
	}
	else if (flag.f1_plus == 1)
	{
		if (n[0] == '0' && n[1] != '\0' && (flag.prec != (ssize_t) * len))
			n[0] = '+';
		else if (n[0] != '-' && (*len += 1))
			n = join_first("+", n);
	}
	return (n);
}

static char	*add_zero_after_minus(char *n, char str, t_flags *flag, size_t *len)
{
	n[0] = '0';
	if (flag->prec != -1)
		flag->prec++;
	n = ft_add_zero(n, *flag, str, len);
	n[0] = '-';
	return (n);
}

void		ft_numbers(char *n, char str, t_flags flag, char **print_str)
{
	size_t	len;

	len = ft_strlen(n);
	if (flag.f1_hesh == 1 && n[0] == '0' && (str == 'o' || str == 'O')
		&& !(flag.f1_hesh = 0))
		flag.prec = -1;
	if (flag.f1_hesh == 1 && (str == 'o' || str == 'O') && len++)
		n = join_first("0", n);
	if (n[0] == '0' && flag.prec == 0)
		len--;
	if (n[0] != '-')
		n = ft_add_zero(n, flag, str, &len);
	else if (n[0] == '-')
		n = add_zero_after_minus(n, str, &flag, &len);
	if (str == 'd' || str == 'D' || str == 'i')
		n = ft_add_znak(n, flag, &len);
	if (!(flag.f1_minus == 1))
		while ((flag.width)-- > len)
			join_and_free(print_str, " ");
	if (len != 0)
		join_and_free(print_str, n);
	if (flag.f1_minus == 1)
		while ((flag.width)-- > len)
			join_and_free(print_str, " ");
	free(n);
}
