/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:14:02 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/27 11:14:03 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *s_chr;

	s_chr = NULL;
	while (*s)
	{
		if (*s == c)
			s_chr = (char*)s;
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (s_chr);
}
