/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:40:31 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/27 17:40:32 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			t;
	unsigned char	*s_dst;
	unsigned char	*s_src;

	t = 0;
	s_src = (unsigned char*)src;
	s_dst = (unsigned char*)dst;
	while (t < n)
	{
		s_dst[t] = s_src[t];
		t++;
	}
	return (dst);
}
