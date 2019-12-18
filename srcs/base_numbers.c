/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:31:56 by bglinda           #+#    #+#             */
/*   Updated: 2019/12/15 17:32:23 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				print_base(va_list args, t_flags *flags, char *base, char *key)
{
	int			size;
	uintmax_t	nb;
	int			precision;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = type_nb_u(args, *flags);
	number_size_u(nb, ft_strlen(base), &size);
	precision = hash_key(nb, flags, &size, key);
	if (flags->precision == -1 && nb == 0)
		size = 0;
	pad_nb(flags, nb, &size, base);
	if (flags->hash_key && flags->width && !flags->minus && !flags->zero &&
			!precision)
		display(key, (int)ft_strlen(key), flags);
	if ((!flags->width || !flags->minus) && size > 0)
		putnbr_base_intmax_t_u(nb, base, ft_strlen(base), flags);
	if (flags->hash_key && size > 0 && ((!flags->width || flags->minus) ||
											precision) && flags->type != 'p')
		size += (int)ft_strlen(key);
	if (size == 0 && flags->type == 'p')
		size = 2;
	return (flags->width - size > 0 ? flags->width : size);
}

int				print_u(va_list ap, t_flags *flags)
{
	return (print_base(ap, flags, "0123456789", NULL));
}

int				print_u_up(va_list ap, t_flags *flags)
{
	flags->length_type = TYPE_L;
	return (print_u(ap, flags));
}

int				print_x(va_list ap, t_flags *flags)
{
	return (print_base(ap, flags, "0123456789abcdef", "0x"));
}

int				print_x_up(va_list ap, t_flags *flags)
{
	return (print_base(ap, flags, "0123456789ABCDEF", "0X"));
}
