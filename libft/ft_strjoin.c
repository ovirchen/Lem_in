/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:03:30 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/29 15:03:33 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup((char*)s2));
	if (s2 == NULL && s1 != NULL)
		return (ft_strdup((char*)s1));
	if (s1 && s2)
	{
		s3 = (char*)malloc(sizeof(char) * (ft_strlen((char*)s1) +
			ft_strlen((char*)s2) + 1));
		if (s3)
		{
			ft_strcpy(s3, s1);
			ft_strcat(s3, s2);
			return (s3);
		}
	}
	return (NULL);
}
