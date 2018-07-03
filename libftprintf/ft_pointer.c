/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:39:15 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/22 15:39:17 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_pointer(char *n, t_flags flag, char **print_str)
{
	size_t	len;

	len = ft_strlen(n);
	len += 2;
	if (n[0] == '0' && flag.prec == 0)
		len--;
	n = ft_add_zero(n, flag, 'x', &len);
	while ((flag.prec)-- > (ssize_t)len - 2)
		n = join_first("0", n);
	if (!(flag.f1_minus == 1))
		while ((flag.width)-- > len)
			join_and_free(print_str, " ");
	if (len - 2 != 0)
	{
		n = join_first("0x", n);
		join_and_free(print_str, n);
	}
	else
		join_and_free(print_str, "0x");
	if (flag.f1_minus == 1)
		while ((flag.width)-- > len)
			join_and_free(print_str, " ");
	free(n);
}
