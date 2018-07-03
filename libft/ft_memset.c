/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:46:39 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/27 12:46:41 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	t;
	char	*b_str;

	t = 0;
	b_str = (char*)b;
	while (t < len)
	{
		b_str[t] = (unsigned char)c;
		t++;
	}
	return (b);
}
