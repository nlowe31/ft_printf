/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:51:25 by nlowe             #+#    #+#             */
/*   Updated: 2017/02/22 17:09:13 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
/*
void	print_args(int ac, ...)
{
	va_list		args;
	int			i;

	va_start(args, ac);
	i = 0;
	while (i < ac)
	{
		ft_putstr(va_arg(args, char *));
		ft_putchar('\n');
		i++;
	}
	va_end(args);
}
*/
int		main(int ac, char **av)
{
	t_buff	buffer;

	if (ac != 2)
		return (0);
	buffer.pos = 0;
	ft_bzero(buffer.contents, BUFF_SIZE);
	printf("chars to buff = %d\n", ft_putbuff(&buffer, av[1], ft_strlen(av[1]), 1));
	printf("chars to stdout = %d\n", ft_flushbuff(&buffer, 1));
	//ft_printf("%l43s%hh82s", "testing", "test");

	return (0);
}
