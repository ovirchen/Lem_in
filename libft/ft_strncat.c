/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:14:21 by ovirchen          #+#    #+#             */
/*   Updated: 2017/09/26 15:14:23 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t d;

	i = 0;
	if (s1)
		d = ft_strlen(s1);
	else
		d = 0;
	while (i < n && s2[i])
	{
		s1[d + i] = s2[i];
		i++;
	}
	s1[d + i] = '\0';
	return (s1);
}
