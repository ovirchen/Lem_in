/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:07:29 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/27 18:07:30 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s_dst;
	unsigned char	*s_src;
	size_t			t;

	s_dst = (unsigned char*)dst;
	s_src = (unsigned char*)src;
	t = 0;
	while (t < n)
	{
		s_dst[t] = s_src[t];
		if (s_src[t] == (unsigned char)c)
			return (++dst);
		t++;
		dst++;
	}
	return (NULL);
}
