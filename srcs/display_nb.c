/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:40:45 by bglinda           #+#    #+#             */
/*   Updated: 2019/12/15 18:43:33 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			display_sign(intmax_t nb, t_flags *flags)
{
	if (nb < 0)
		display("-", 1, flags);
	if (flags->plus && nb >= 0)
		display("+", 1, flags);
	else if (flags->space && nb >= 0)
		display(" ", 1, flags);
}

void			putnbr_base_intmax_t_u(uintmax_t nbr, char *str,
					uintmax_t str_length, t_flags *flags)
{
	if (nbr >= str_length)
		putnbr_base_intmax_t_u(nbr / str_length, str, str_length, flags);
	display(&str[nbr % str_length], 1, flags);
}

int				display_d(t_flags *flags, int size, int precision, intmax_t nb)
{
	int			width_size;
	int			width;

	width = 0;
	width_size = 0;
	if (!flags->minus)
	{
		if (flags->width && flags->zero)
			display_sign(nb, flags);
		width_size = pad(flags, size) - size;
	}
	if ((flags->width && (flags->minus || !flags->zero)) || !flags->width)
		display_sign(nb, flags);
	while (width++ < precision)
		display("0", 1, flags);
	if (size > 0)
		putnbr_base_intmax_t_u((uintmax_t)(nb < 0 ? -nb : nb), "0123456789",
				10, flags);
	return (size + width_size);
}

int				print_d(va_list ap, t_flags *flags)
{
	intmax_t	nb;
	int			precision;
	int			size;

	size = 0;
	if (flags->precision != 0)
		flags->zero = 0;
	nb = type_nb(ap, *flags);
	number_size_u((uintmax_t)(nb < 0 ? -nb : nb), 10, &size);
	precision = flags->precision - size;
	size = (flags->precision > size) ? flags->precision : size;
	size = (flags->precision == -1 && nb == 0) ? 0 : size;
	size += (nb >= 0 && (flags->plus || flags->space));
	if (nb < 0)
		size += 1;
	size = display_d(flags, size, precision, nb);
	size = (flags->minus) ? pad(flags, size) : size;
	return (size);
}
