/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:38:44 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/27 21:38:45 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			t;
	unsigned char	*s_str;

	t = 0;
	s_str = (unsigned char*)s;
	while (t < n)
	{
		if (s_str[t] == (unsigned char)c)
			return ((char*)s);
		s++;
		t++;
	}
	return (NULL);
}
