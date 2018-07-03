/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:48:14 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/27 21:48:15 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_s1;
	unsigned char	*s_s2;
	size_t			t;

	s_s1 = (unsigned char*)s1;
	s_s2 = (unsigned char*)s2;
	t = 0;
	while (t < n)
	{
		if (s_s1[t] != s_s2[t])
			return (s_s1[t] - s_s2[t]);
		t++;
	}
	return (0);
}
