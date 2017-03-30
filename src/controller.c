/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:50:52 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/30 14:26:37 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		has_flag(t_arg *arg, char flag)
{
	if (ft_strchr(arg->flags, flag))
		return (1);
	return (0);
}

int		padding(t_buff *buffer, t_arg *arg)
{
	char		pad;
	long long	width;

	pad = ' ';
	width = arg->width;
	if (width == -1)
		return (0);
	if (arg->len > arg->width)
		return (0);
	if (has_flag(arg, '0') && !(has_flag(arg, '-'))
		&& (arg->precision == -1 || arg->precision > arg->width))
		pad = '0';
	while (--width >= arg->len)
		ft_putbuff(buffer, &pad, 1);
	return (arg->width - arg->len);
}

int		print(t_buff *buffer, t_arg *arg, int count)
{
//	printf("type: %c\n", arg->type);
	int		*n;
	if (arg->type == 0)
		return (0);
	if (arg->type == 'n')
	{
		n = (int *)arg->target;
		*n = count;
		return (0);
	}
	if (arg->type == 'p')
	{
		arg->length_flag = l;
		add_flag(arg, '#');
	}
	if (arg->type == 's')
		return (ft_printstr(buffer, arg));
	if (arg->type == 'c' || arg->type == '%')
		return (ft_printchar(buffer, arg));
	return (ft_printnbr(buffer, arg));
}
