/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 22:37:09 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/27 22:37:10 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char	*s;
	size_t			t;

	s = (unsigned char*)malloc(sizeof(unsigned char) * (size + 1));
	if (!s)
		return (NULL);
	t = 0;
	while (t < (size + 1))
		s[t++] = '\0';
	return ((char*)s);
}
