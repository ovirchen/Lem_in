/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:23:45 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/29 18:23:47 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	if ((n >= 0 && n <= 9) || (n < 0 && n >= -9))
		return (1);
	else if ((n > 9) || (n < -9))
		return (ft_nbrlen(n / 10) + 1);
	else
		return (0);
}

static char	*putstr_n(int n, char *s, int len, int sign)
{
	int		i;

	i = len - 1;
	while (i > 0)
	{
		s[i] = (n % 10) * sign + 48;
		n = n / 10;
		i--;
	}
	if (sign != -1)
		s[0] = (n % 10) * sign + 48;
	s[len] = '\0';
	return (s);
}

char		*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*s;

	len = ft_nbrlen(n);
	if (n < 0)
		len++;
	s = (char*)malloc(sizeof(char) * (len + 1));
	if (s)
	{
		sign = 1;
		if (n < 0)
		{
			s[0] = '-';
			sign = -1;
		}
		if (n == 0)
			s[0] = '0';
		s = putstr_n(n, s, len, sign);
		return (s);
	}
	return (NULL);
}
