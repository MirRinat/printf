/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:53:10 by bglinda           #+#    #+#             */
/*   Updated: 2019/12/15 17:53:17 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			number_size_u(uintmax_t nbr, uintmax_t str_length, int *size)
{
	*size += 1;
	while (nbr >= str_length)
	{
		nbr /= str_length;
		*size += 1;
	}
}

intmax_t		type_nb(va_list args, t_flags flags)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	if (flags.length_type == TYPE_HH)
		nbr = (char)nbr;
	else if (flags.length_type == TYPE_H)
		nbr = (short int)nbr;
	else if (flags.length_type == TYPE_L)
		nbr = (long int)nbr;
	else if (flags.length_type == TYPE_LL)
		nbr = (long long int)nbr;
	else if (flags.length_type == TYPE_J)
		nbr = (intmax_t)nbr;
	else if (flags.length_type == TYPE_Z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t		type_nb_u(va_list args, t_flags flags)
{
	uintmax_t	nbr;

	nbr = va_arg(args, uintmax_t);
	if (flags.length_type == TYPE_HH)
		nbr = (unsigned char)nbr;
	else if (flags.length_type == TYPE_H)
		nbr = (unsigned short int)nbr;
	else if (flags.length_type == TYPE_L)
		nbr = (unsigned long int)nbr;
	else if (flags.length_type == TYPE_LL)
		nbr = (unsigned long long int)nbr;
	else if (flags.length_type == TYPE_J)
		nbr = (uintmax_t)nbr;
	else if (flags.length_type == TYPE_Z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
