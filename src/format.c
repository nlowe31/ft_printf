/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:15:50 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/20 22:05:45 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precision(const char *restrict format, t_arg *ret,
	va_list args, int *i)
{
	if (format[*i + 1] && format[*i + 1] == '*')
	{
		ret->precision = va_arg(args, long long);
		(*i)++;
	}
	else if (format[*i + 1] && ft_isdigit(format[*i + 1]))
	{
		(*i)++;
		ret->precision = atoi(&(format[*i]));
		while (ft_isdigit(format[*i]))
			(*i)++;
		(*i)--;
	}
	else
		ret->precision = 0;
}

void	check_width(const char *restrict format, t_arg *ret, int *i)
{
	ret->width = atoi(&format[*i]);
	while (ft_isdigit(format[*i]))
		(*i)++;
	(*i)--;
}

void	add_flag(t_arg *ret, char f)
{
	ret->flags[(ret->flag_count)++] = f;
}

void	add_length_flag(t_arg *ret, char f)
{
	if (!(ret->length_flag + f > 216))
		ret->length_flag = ret->length_flag + (int)f;
}

void	convert_caps(t_arg *ret)
{
	if (ret->type != 'X' && ret->type != 'O' &&
		ret->type >= 'A' && ret->type <= 'Z')
	{
		add_length_flag(ret, 'l');
		ret->type = ft_tolower(ret->type);
	}
}