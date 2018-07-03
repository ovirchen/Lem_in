/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:45:53 by ovirchen          #+#    #+#             */
/*   Updated: 2017/09/25 12:45:55 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_tab(char *str)
{
	if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' ||
		*str == '\f' || *str == '\v')
		return (1);
	return (0);
}

static int		ft_check_digit(char *str)
{
	if (*str <= '9' && *str >= '0')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	nbr;
	int					i;

	if (!(i = 0) && str == NULL)
		return (-1);
	while (ft_check_tab((char*)str) && *str != '\0')
		str++;
	if ((sign = 1) && *str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	nbr = 0;
	while (ft_check_digit((char*)str) && *str != '\0')
	{
		nbr = nbr * 10 + (*str - 48);
		str++;
		i++;
	}
	if (i > 19 || nbr >= 9223372036854775808ULL)
		return (sign == 1 ? -1 : 0);
	return (nbr * sign);
}
