/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:13:12 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/20 21:57:55 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 10000
# define FT_PRINTF_FLAGS "#0-+ $L'"
# define FT_PRINTF_TYPES "sSpdDioOuUxXcCnb"
# define FT_PRINTF_LENGTH "hljz"
# define HEX "0123456789ABCDEF"
# define SMALL_HEX "0123456789abcdef"
# define MAX_INT_SIZE 50

//pdDioOuUxXeEfFgGaAn

typedef enum		e_bool
{
	false = 0,
	true = 1
}					t_bool;

typedef enum		e_length
{
	none = 0,
	h = 104,
	j = 106,
	l = 108,
	z = 122,
	hh = 208,
	ll = 216
}					t_length;

typedef struct		s_arg
{
	char			flags[10];
	int				flag_count;
	t_length		length_flag;
	long long		width;
	long long		len;
	long long		precision;
	int				base;
	int				negative;
	char			type;
	void			*target;
}					t_arg;

typedef struct		s_buff
{
	unsigned char	contents[BUFF_SIZE];
	size_t			pos;
	int				fd;
}					t_buff;

int					ft_printf(const char *format, ...);
void				test_arg(t_arg *arg);
int					ft_putbuff(t_buff *buffer, void *contents, size_t len);
void				ft_flushbuff(t_buff *buffer);
int					print(t_buff *buffer, t_arg *arg, int count);
int					padding(t_buff *buffer, t_arg *arg);
int					has_flag(t_arg *arg, char flag);
void				add_flag(t_arg *ret, char f);
void				add_length_flag(t_arg *ret, char f);
t_arg				create_arg(void);
void				new_arg(const char* restrict format, va_list args,
	int *i, t_arg *current);

void				check_precision(const char * restrict format, t_arg *ret,
	va_list args, int *i);
void				check_width(const char* restrict format, t_arg *ret, int *i);
void				convert_caps(t_arg *ret);

unsigned long long	get_negative(t_arg *arg);
int					prefix_count(t_arg *arg);
long long			signed_convert(t_arg *arg);
unsigned long long	unsigned_convert(t_arg *arg);

int					ft_printstr(t_buff *buffer, t_arg *arg);
int					ft_printchar(t_buff *buffer, t_arg *arg);
int					ft_printwchar(t_buff *buffer, wchar_t c);
size_t				ft_wcslen(wchar_t *s);
int					ft_printwstr(t_buff *buffer, t_arg *arg);

int					ft_printnbr(t_buff *buffer, t_arg *arg);

int					ft_printptr(t_buff *buffer, t_arg *arg);

#endif