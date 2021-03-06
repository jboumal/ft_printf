/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  write_hexa_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:32:56 by jboumal           #+#    #+#             */
/*   Updated: 2022/01/27 13:03:48 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	rec_write_hex(unsigned int n, t_flags *flags, char *base)
{
	if (n != 0)
	{
		flags->printed ++;
		rec_write_hex(n / 16, flags, base);
		ft_putchar_fd (base[n % 16], 1);
	}
	else
	{
		if (flags->number_sign)
			flags->printed += 2;
		precision(flags);
		field_width(flags);
		if (flags->number_sign)
		{
			if (base[10] == 'a')
				ft_putstr_fd("0x", 1);
			else
				ft_putstr_fd("0X", 1);
		}
	}
}

void	write_x(unsigned int n, t_flags *flags)
{
	if (n == 0 && flags->dot != 0)
	{
		flags->printed = 1;
		precision(flags);
		field_width(flags);
		ft_putchar_fd('0', 1);
	}
	else
		rec_write_hex(n, flags, "0123456789abcdefg");
}

void	write_upper_x(unsigned int n, t_flags *flags)
{
	if (n == 0 && flags->dot != 0)
	{
		flags->printed = 1;
		precision(flags);
		field_width(flags);
		ft_putchar_fd('0', 1);
	}
	else
		rec_write_hex(n, flags, "0123456789ABCDEFG");
}
