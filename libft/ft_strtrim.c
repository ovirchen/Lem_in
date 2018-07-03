/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:48:43 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/29 16:48:46 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SPACE(x) x == '\t' || x == '\n' || x == ' '

static size_t	str_len(char *str)
{
	size_t i;
	size_t t;

	while (SPACE(*str) && str)
		str++;
	i = 0;
	while (str[i])
	{
		if (SPACE(str[i]))
		{
			t = i;
			while (SPACE(str[i]) && str[i])
				i++;
			if (str[i] == '\0')
				return (t);
		}
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*s2;
	size_t	i;
	size_t	len;

	if (s)
	{
		len = str_len((char*)s);
		s2 = (char*)malloc(sizeof(char) * (len + 1));
		if (s2)
		{
			while (SPACE(*s) && s)
				s++;
			i = 0;
			while (i < len)
			{
				s2[i] = s[i];
				i++;
			}
			s2[i] = '\0';
			return (s2);
		}
	}
	return (NULL);
}
