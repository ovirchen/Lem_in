/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:44:15 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/24 14:44:16 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen_uni(const unsigned int *s)
{
	size_t len;
	size_t i;

	if (!s)
		return (0);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] <= 0x7F)
			len++;
		else if (s[i] <= 0x3FF)
			len += 2;
		else if (s[i] <= 0xFFFF)
			len += 3;
		else if (s[i] <= 0x801FFFFF)
			len += 4;
		i++;
	}
	return (len);
}

int		ft_size_char(const unsigned int c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x3FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else
		return (4);
}
