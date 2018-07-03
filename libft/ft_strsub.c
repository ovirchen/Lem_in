/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:04:27 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/29 14:04:28 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (s && (start <= ft_strlen((char*)s)) &&
		(len <= (ft_strlen((char*)s) - start)))
	{
		s2 = (char *)malloc(sizeof(char) * (len + 1));
		if (s2)
		{
			i = 0;
			while (i < len && s[start])
				s2[i++] = s[start++];
			s2[i] = '\0';
			return ((char*)s2);
		}
	}
	return (NULL);
}
