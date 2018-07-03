/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:50:20 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/28 18:50:22 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned char	*s2;

	if (s && f)
	{
		i = 0;
		s2 = (unsigned char*)malloc(sizeof(unsigned char) *
			(ft_strlen((char*)s) + 1));
		if (s2)
		{
			while (s[i])
			{
				s2[i] = (unsigned char)(*f)(i, s[i]);
				i++;
			}
			s2[i] = '\0';
		}
	}
	else
		s2 = NULL;
	return ((char*)s2);
}
