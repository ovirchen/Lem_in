/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:08:36 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/07 13:09:15 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	add_width(char **str, t_flags *flag, va_list ap)
{
	char	*s;
	int		wid;

	flag->width = 0;
	s = *str;
	while (((*s >= '0' && *s <= '9') || *s == '*') && *s)
	{
		if (*s == '*' && s++)
		{
			wid = va_arg(ap, int);
			if (wid < 0 && (flag->f1_minus = 1))
				wid = -wid;
			flag->width = wid;
		}
		else if (*s >= '0' && *s <= '9')
		{
			flag->width = 0;
			while (*s >= '0' && *s <= '9')
				flag->width = flag->width * 10 + (*s++ - 48);
		}
		else if (*s == ' ')
			s++;
	}
	*str = s;
}

static void	add_precision(char **str, t_flags *flag, va_list ap)
{
	char	*s;
	int		pr;

	flag->prec = -1;
	s = *str;
	if (*s == '.' && s++ && !(flag->prec = 0))
	{
		if (*s == '*' && s++)
		{
			pr = va_arg(ap, int);
			if (pr < 0)
				flag->prec = -1;
			else
				flag->prec = pr;
		}
		else if (*s >= '0' && *s <= '9')
		{
			flag->prec = 0;
			while (*s >= '0' && *s <= '9')
				flag->prec = flag->prec * 10 + (*s++ - 48);
		}
	}
	*str = s;
}

static char	*ft_printf_continue(char *str, t_flags flag, va_list ap,
	char **print_str)
{
	ft_flag_1((char**)&str, &flag);
	add_width((char**)&str, &flag, ap);
	add_precision((char**)&str, &flag, ap);
	flag.flag_2 = ft_flag_2((char**)&str);
	if (((*str == 's' && (flag.flag_2 < 99 || flag.flag_2 > 1000))
		|| (*str == 'S' && MB_CUR_MAX != 4)) && str++)
		ft_strings(va_arg(ap, char *), flag, print_str);
	else if ((*str == 'S' || (*str == 's' && flag.flag_2 > 99 &&
		flag.flag_2 < 1000)) && str++)
		ft_strings_uni(va_arg(ap, unsigned int*), flag, print_str);
	else if (*str == 'c' && str++)
		ft_chars(va_arg(ap, unsigned int), flag, print_str);
	else if (*str == 'C' && str++)
		ft_chars_uni(va_arg(ap, unsigned int), flag, print_str);
	else if ((*str == 'x' || *str == 'X' || *str == 'o' || *str == 'O' ||
	*str == 'd' || *str == 'D' || *str == 'i' || *str == 'u' || *str == 'U')
		&& str++)
		ft_numbers(get_number(ap, flag.flag_2, *(str - 1)), *(str - 1),
			flag, print_str);
	else if (*str == 'p' && str++)
		ft_pointer(ft_itoa_base_unsigned((size_t)va_arg(ap, void*), 'x'),
			flag, print_str);
	else if (*str && str++)
		ft_chars(*(str - 1), flag, print_str);
	return (str);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flags	flag;
	char	*print_str;
	size_t	len;

	va_start(ap, str);
	print_str = ft_strnew(0);
	while (*str)
	{
		if (*str == '%' && str++)
		{
			ft_bzero(&flag, sizeof(flag));
			str = ft_printf_continue((char*)str, flag, ap, &print_str);
		}
		else
			join_char(&print_str, *(str++));
	}
	va_end(ap);
	len = ft_strlen(print_str);
	check_zero_char(&print_str);
	write(1, print_str, len);
	free(print_str);
	return (len);
}
