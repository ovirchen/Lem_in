/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:45:08 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/25 12:45:09 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flags
{
	ssize_t	prec;
	size_t	width;
	int		f1_minus;
	int		f1_plus;
	int		f1_space;
	int		f1_hesh;
	int		f1_zero;
	int		flag_2;
}				t_flags;

size_t			ft_strlen_uni(const unsigned int *s);
void			check_zero_char(char **s1);
int				ft_size_char(const unsigned int c);
char			*ft_itoa_base(long long int val, char x);
char			*ft_itoa_base_unsigned(size_t value, char x);
int				ft_printf(const char *str, ...);
void			ft_pointer(char *n, t_flags flag, char **print_str);
void			ft_strings(char *n, t_flags flag, char **print_str);
void			ft_strings_uni(unsigned int *n, t_flags flag, char **print_str);
char			*get_number(va_list ap, int flag_2, char str);
void			ft_numbers(char *n, char str, t_flags flag, char **print_str);
void			ft_chars(unsigned int c, t_flags flag, char **print_str);
void			ft_chars_uni(unsigned int c, t_flags flag, char **print_str);
void			ft_flag_1(char **str, t_flags *flag);
int				ft_flag_2(char **str);
char			*ft_add_zero(char *n, t_flags flag, char str, size_t *len);
void			join_and_free(char **s1, char *s2);
void			join_char(char **s1, unsigned int c);
char			*join_first(char *s1, char *n);

#endif
