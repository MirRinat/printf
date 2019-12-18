/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:13:26 by bglinda           #+#    #+#             */
/*   Updated: 2019/12/15 18:13:28 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				hash_key(uintmax_t nb, t_flags *flags, int *size, char *key)
{
	int			precision;

	precision = 0;
	if (nb == 0 && flags->type != 'p')
		flags->hash_key = 0;
	if (flags->hash_key && (!flags->width || flags->minus || flags->zero ||
									(precision = flags->precision > *size)))
		display(key, (int)ft_strlen(key), flags);
	if (flags->hash_key && ((flags->width) && !precision) && flags->type != 'p')
		*size += (int)ft_strlen(key);
	return (precision);
}

int				print_o(va_list args, t_flags *flags)
{
	int			size;
	int			nb_size;
	uintmax_t	nb;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = type_nb_u(args, *flags);
	if (flags->precision >= 0 || nb > 0)
		number_size_u(nb, 8, &size);
	if (flags->hash_key && (nb > 0 || flags->precision < 0))
		size += 1;
	nb_size = size;
	size = (flags->precision > size) ? flags->precision : size;
	if (flags->width && !flags->minus)
		size = pad(flags, size);
	if (flags->hash_key && (nb > 0 || flags->precision < 0))
		display("0", 1, flags);
	while (nb_size++ < flags->precision)
		display("0", 1, flags);
	if (flags->precision >= 0 || nb > 0)
		putnbr_base_intmax_t_u(nb, "01234567", 8, flags);
	if (flags->width && flags->minus)
		size = pad(flags, size);
	return (size);
}
