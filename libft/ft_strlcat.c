/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:00:32 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/26 15:00:33 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t t_src;
	size_t t_dst;
	size_t t;
	size_t i;

	t_src = ft_strlen(src);
	t_dst = ft_strlen(dst);
	if (t_dst < size)
	{
		t = t_dst;
		i = 0;
		while (t < (size - 1))
			dst[t++] = src[i++];
		dst[t] = '\0';
		return (t_src + t_dst);
	}
	else
		return (t_src + size);
}
