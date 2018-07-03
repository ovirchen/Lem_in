/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:37:35 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/27 11:37:36 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char*)big);
	while (*big && len)
	{
		if (*big == *little)
		{
			i = 0;
			while (*(big + i) == *(little + i) && len - i)
			{
				i++;
				if (*(little + i) == '\0')
					return ((char *)big);
			}
		}
		len--;
		big++;
	}
	return (NULL);
}
