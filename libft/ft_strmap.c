/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:27:26 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/28 13:27:27 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				s2[i] = (unsigned char)(*f)(s[i]);
				i++;
			}
			s2[i] = '\0';
		}
	}
	else
		s2 = NULL;
	return ((char*)s2);
}
