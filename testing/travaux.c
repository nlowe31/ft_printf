/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:45:40 by nlowe             #+#    #+#             */
/*   Updated: 2017/04/05 16:35:33 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_arg(t_arg *arg)
{
	ft_putstr("flags: ");
	ft_putendl(arg->flags);
	ft_putstr("flag count: ");
	ft_putnbr(arg->flag_count);
	ft_putchar('\n');
	ft_putstr("length flags: ");
	ft_putnbr((int)(arg->length_flag));
	ft_putchar('\n');
	ft_putstr("width: ");
	ft_putnbr((arg->width));
	ft_putchar('\n');
	ft_putstr("precision: ");
	ft_putnbr((arg->precision));
	ft_putchar('\n');
	ft_putstr("type: ");
	ft_putchar((arg->type));
	ft_putchar('\n');
	printf("len: %d\n", arg->len);
}