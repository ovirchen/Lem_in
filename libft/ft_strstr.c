/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:27:08 by ovirchen          #+#    #+#             */
/*   Updated: 2017/09/25 17:27:10 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_to_find(const char *str, const char *to_find)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	while (t < ft_strlen((char*)to_find))
	{
		if (str[t] == to_find[t])
			i++;
		t++;
	}
	return (i);
}

char			*ft_strstr(const char *big, const char *little)
{
	size_t	i;

	i = 0;
	if (!*little)
		return ((char*)big);
	if (ft_strlen((char*)little) <= ft_strlen((char*)big))
	{
		while (*big)
		{
			if (*big == little[0])
			{
				if (find_to_find(big, little) == ft_strlen((char*)little))
					return ((char*)big);
			}
			big++;
			i++;
		}
	}
	return (NULL);
}
