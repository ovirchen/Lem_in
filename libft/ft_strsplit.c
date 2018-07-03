/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:15:08 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/29 17:15:10 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *str, char c)
{
	int word_count;
	int i;
	int has_word;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		has_word = 0;
		while (c == str[i] && str[i])
			i++;
		while (c != str[i] && str[i])
		{
			has_word = 1;
			i++;
		}
		if (has_word == 1)
			word_count++;
	}
	return (word_count);
}

static int		ft_word_size(char const *str, char c)
{
	int i;

	i = 0;
	while (c == str[i] && str[i])
		str++;
	while (c != str[i] && str[i])
		i++;
	return (i);
}

static char		*create_word(char const *s, char c)
{
	char	*word;
	int		i;

	word = (char*)malloc(sizeof(char) * (ft_word_size(s, c) + 1));
	if (word)
	{
		i = 0;
		while (c == *s && *s)
			s++;
		while (c != *s && *s)
			word[i++] = *s++;
		word[i] = '\0';
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	int		word_count;
	int		j;
	char	**words;

	j = 0;
	if (s)
	{
		word_count = ft_word_count(s, c);
		words = (char**)malloc(sizeof(char*) * (word_count + 1));
		if (words)
		{
			while (j < word_count)
			{
				while (c == *s && *s)
					s++;
				words[j] = create_word(s, c);
				while (c != *s && *s)
					s++;
				j++;
			}
			words[j] = 0;
			return (words);
		}
	}
	return (NULL);
}
