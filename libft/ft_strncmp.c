/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:42:34 by ovirchen          #+#    #+#             */
/*   Updated: 2017/09/26 10:42:36 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	if (!*s1)
		return (-(unsigned char)(s2[i]));
	while (s1[i] == s2[i] && s1[i] && s2[i] && n)
	{
		i++;
		n--;
	}
	if (n == 0)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
