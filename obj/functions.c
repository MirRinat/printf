/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:54:43 by bantario          #+#    #+#             */
/*   Updated: 2019/11/28 19:23:41 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include "stdlib.h"
#include <stdarg.h>

//int	print_int(char *hu, va_list ap, t_node *list)
//{
//	int		dval;
//
//	if (*hu == 'd')
//	{
//		dval = va_arg(ap, int);
//
//		ft_putnbr(dval);
//		list->len = (list->len) + ft_strlen(ft_itoa(dval));
//	}
//    return (0);
//}



//int		ft_write_char(char c, t_flags *flags)
//{
//    return (ft_write(&c, 1, flags));
//}
//
//void	ft_putnbr_base_intmax_t_u(uintmax_t nbr, char *str,
//                                  uintmax_t str_length, t_flags *flags)
//{
//    if (nbr >= str_length)
//        ft_putnbr_base_intmax_t_u(nbr / str_length, str, str_length, flags);
//    ft_write_char(str[nbr % str_length], flags);
//}
//
//intmax_t	ft_get_nb(va_list args, t_flags flags)
//{
//    intmax_t	nbr;
//
//    nbr = va_arg(args, intmax_t);
//    if (flags.length_type == LENGTH_HH)
//        nbr = (char)nbr;
//    else if (flags.length_type == LENGTH_H)
//        nbr = (short int)nbr;
//    else if (flags.length_type == LENGTH_L)
//        nbr = (long int)nbr;
//    else if (flags.length_type == LENGTH_LL)
//        nbr = (long long int)nbr;
//    else if (flags.length_type == LENGTH_J)
//        nbr = (intmax_t)nbr;
//    else if (flags.length_type == LENGTH_Z)
//        nbr = (size_t)nbr;
//    else
//        nbr = (int)nbr;
//    return (nbr);
//}
//
//void		ft_display_sign(intmax_t nb, t_flags *flags)
//{
//    if (nb < 0)
//        ft_write("-", 1, flags);
//    if (flags->plus && nb >= 0)
//        ft_write("+", 1, flags);
//    else if (flags->space && nb >= 0)
//        ft_write(" ", 1, flags);
//}
//
//int			ft_display_d(t_flags *flags, int size, int precision, intmax_t nb) {
//    int width_size;
//    int width;
//
//    width = 0;
//    width_size = 0;
//    if (!flags->minus) {
//        if (flags->width && flags->zero)
//            ft_display_sign(nb, flags);
//        width_size = ft_pad(flags, size) - size;
//    }
//    if ((flags->width && (flags->minus || !flags->zero)) || !flags->width)
//        ft_display_sign(nb, flags);
//    while (width++ < precision)
//        ft_write("0", 1, flags);
//    if (size > 0)
//        ft_putnbr_base_intmax_t_u((uintmax_t) (nb < 0 ? -nb : nb), "0123456789",
//                                  10, flags);
//    return (size + width_size);
//}
////
//void	ft_get_number_size_u(uintmax_t nbr, uintmax_t str_length, int *size)
//{
//    *size += 1;
//    while (nbr >= str_length)
//    {
//        nbr /= str_length;
//        *size += 1;
//    }
//}
int	print_int(va_list ap, t_flags *flags, t_node *list)
{
    intmax_t		nb;
   // int     precision;
    int     size;

    size = 0;
    nb = va_arg(ap,int);
    list = (t_node *)malloc(sizeof(t_node));
    list->len = 0;
  //  nb = ft_get_nb(ap, *flags);
//    ft_get_number_size_u((uintmax_t)nb,10,&size);
//    precision = flags->precision - size;
//    size = (flags->precision > size) ? flags->precision : size;
//    size += (nb >= 0 && (flags->plus || flags->space));
//    size = ft_display_d(flags,size,precision,nb);

    size = (flags->minus) ? ft_pad(flags,size):size;
    ft_putnbr(nb);
    list->len = (list->len) + ft_strlen(ft_itoa(nb));
    return (size + list->len);
}

int	print_str( va_list ap, t_node *list)
{
	char	*str;

//	if (*hu == 's')
//	{
		str = va_arg(ap, char*);
		if (str == NULL)
		{
			ft_putstr("(null)");
			list->len = list->len + 6;
		} else 
		{
			ft_putstr(str);
			list->len = (list->len) + ft_strlen(str);
		}
	//}
    return (0);
}

int	print_symb(va_list ap, t_node *list)
{
	char	cval;

//	if (*hu == 'c')
//	{
		cval = va_arg(ap, int);
		ft_putchar(cval);
		list->len++; 
//	}
    return (0);
}

void	print_ld(char *hu, va_list ap, t_node *list)
{
	long long int lval;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'd')
		{
			lval = va_arg(ap, unsigned long long int);
			/*if (lval > 0)
				list->len--;
			else
				list->len++;*/
			ft_putnbr(lval);
			list->len = list->len + ft_strlen(ft_itoa(lval));
		}
	}
}

void	print_long_l(char *hu, va_list ap, t_node *list)
{
	unsigned long long int lval;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'l')
		{
			hu++;
			if (*hu == 'd')
			{
				lval = va_arg(ap, unsigned long long int);
				ft_putnbr_4(lval);
				list->len = list->len + ft_strlen(ft_itoa(lval));
			}
		}
	}
}

void	print_llu(char *hu, va_list ap, t_node *list)
{
	unsigned long long int llu;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'l')
		{
			hu++;
			if (*hu == 'u')
			{
				llu = va_arg(ap, unsigned long long int);
				ft_putnbr_2(llu);
				list->len = list->len + ft_strlen(ft_itoa(llu));
			}
		}
	}
}

int	print_i( va_list ap, t_node *list)
{
	signed int		chislo;
	char			*hex_to_numb;

//	if (*hu == 'i')
//	{
		chislo = va_arg(ap, signed int);
		hex_to_numb = ft_itoa(chislo);
		ft_putnbr(ft_atoi(hex_to_numb));
		list->len = list->len + ft_strlen(hex_to_numb);
//	}
    return (0);
}

void	Func(unsigned int n, t_node *list)
{
	if (n != 0)
	{
		Func(n / 8, list);
		list->len++;
	}
	else
		return;
	ft_putnbr(n % 8);
	return;
}

int	print_o(char *hu, va_list ap, t_node *list)
{
	int oo;

//	if (*hu == 'o')
//	{
		oo = va_arg(ap, unsigned int);
		if (oo == 0)
		{
			ft_putnbr(0);
			list->len++;
		}
		Func(oo, list);
//	}
    return (0);
}

int	print_u(char *hu, va_list ap, t_node *list)
{
	long long int	uu;

//	if (*hu == 'u')
//	{
		uu = va_arg(ap, long long int);
		if (uu < 0)
		{
			ft_putstr("4294967295");
			list->len = list->len + 10;
			return(0);
		}
		if (uu > 4294967295)
		{
			ft_putchar('0');
			list->len++;
			return(0);
		}
		ft_putnbr(uu);
		list->len = list->len + ft_strlen(ft_itoa(uu));
//	}
    return (0);
}

int	print_procent(va_list ap, t_node *list)
{
//	if (*hu == '%')
//	{
		list->len++;
		ft_putchar('%');
//	}
    return (0);
}

void	print_lu(char *hu, va_list ap, t_node *list)
{
	unsigned long long lu;
	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'u')
		{
			lu = va_arg(ap, unsigned long long);
			ft_putnbr_2(lu);
			list->len = list->len + ft_strlen(ft_itoa_2(lu));
		}
	}
}

void	print_hu(char *hu, va_list ap, t_node *list)
{
	int val;
	
	if (*hu == 'h')
	{
		hu++;
		if (*hu == 'u')
		{
			val = va_arg(ap, int);
			ft_putnbr(val);
			list->len = list->len + ft_strlen(ft_itoa(val));
		}
	}
}

void	print_hi(char *hu, va_list ap, t_node *list)
{
	signed short int val;

	if (*hu == 'h')
	{
		hu++;
		if (*hu == 'i')
		{
			val = va_arg(ap, int);
			ft_putnbr(val);
			list->len = list->len + ft_strlen(ft_itoa(val));
		}
	}
}

void	print_hd(char *hu, va_list ap, t_node *list)
{
	short int hd;

	if (*hu == 'h')
	{
		hu++;
		if (*hu == 'd')
		{
			hd = va_arg(ap, int);
			ft_putnbr(hd);
			list->len = list->len + ft_strlen(ft_itoa(hd));
		}
	}
}

void	print_lli(char *hu, va_list ap, t_node *list)
{
	signed long long int lli;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'l')
		{
			hu++;
			if (*hu == 'i')
			{
				lli = va_arg(ap, signed long long int);
				ft_putnbr(lli);
				list->len = list->len + ft_strlen(ft_itoa(lli));
			}
		}
	}
}

void	Func2_next(long long n, t_node *list)
{
	if ((n % 16) == 15)
		ft_putchar('f');
	else if ((n % 16) == 10)
		ft_putchar('a');
	else if ((n % 16) == 11)
		ft_putchar('b');
	else if ((n % 16) == 12)
		ft_putchar('c');
	else if ((n % 16) == 13)
		ft_putchar('d');
	else if ((n % 16) == 14)
		ft_putchar('e');
	else
		if (list->when_pr > 7)
			ft_putnbr(n % 16);
		else
			list->len--;
}

void	Func2(long long n, t_node *list)
{
	if (n != 0)
	{
		list->len++;
		Func2(n / 16, list);
		list->when_pr++;
	}
	else
		return;
	Func2_next(n, list);
}

void	Func3_next(long long int n, t_node *list)
{
	if ((n % 16) == 10)
		ft_putchar('A');
	else if ((n % 16) == 11)
		ft_putchar('B');
	else if ((n % 16) == 12)
		ft_putchar('C');
	else if ((n % 16) == 13)
		ft_putchar('D');
	else if ((n % 16) == 14)
		ft_putchar('E');
	else if ((n % 16) == 15)
		ft_putchar('F');
	else
		if (list->when_pr > 7)
			ft_putnbr(n % 16);
		else
			list->len--;
}


void    Func3(long long int n, t_node *list)
{
	if (n != 0)
	{
		list->len++;
		Func3(n / 16, list);
		list->when_pr++;
	}
	else
		return;
	Func3_next(n, list);
}

int	print_zero(t_node *list)
{
	ft_putchar('0');
	list->len++;
	return(0);
}

int	print_x(char *hu, va_list ap, t_node *list)
{
	long long int		dec;
	char	*str;

	dec = 0;
//	if (*hu == 'x')
//	{
		dec = va_arg(ap, int);
		str = ft_itoa(dec);
		if (str[0] == '-')
		{
			dec = (-1) * dec * 4294967295;
			list->when_pr = 1;
		} else
			list->when_pr = 8;
		if (dec == 0)
			print_zero(list);
		Func2(dec, list);
		free(str);
//	}
    return(0);

}

int	print_X(char *hu, va_list ap, t_node *list)
{
	long long int dec;
	char *str;

	dec = 0;
//	if (*hu == 'X')
//	{
		dec = va_arg(ap, int);
		str = ft_itoa(dec);
		if (str[0] == '-')
		{
			dec = (-1) * dec * 4294967295;
			list->when_pr = 1;
		} else
			list->when_pr = 8;
		if (dec == 0)
			print_zero(list);
		Func3(dec, list);
		free(str);
//	}
    return(0);

}

//void	print_float(char *hu, va_list ap)
//{
//	char *str;
//	double fl;
//
//	if (*hu == 'f')
//	{
//		str = (char *)malloc(sizeof(int) *1000);
//		fl = va_arg(ap, double);
//		float_to_str(fl, str, 6);
//	}
//}

void	one_proc(char *hu, t_node *list)
{
	if (*hu == '\0')
		list->len = 0;
}

void	cast_func(char *hu, va_list ap, func *mass, t_node *list)
{
	mass[1](hu, ap, list);
	mass[2](hu, ap, list);
	mass[3](hu, ap, list);
	mass[5](hu, ap, list);
	mass[6](hu, ap, list);
	mass[7](hu, ap, list);
	mass[8](hu, ap, list);
	mass[9](hu, ap, list);
	mass[10](hu, ap, list);
	mass[11](hu, list);
	mass[12](hu, ap, list);
	mass[13](hu, ap, list);
	mass[14](hu, ap, list);
	mass[15](hu, ap, list);
	mass[16](hu, ap, list);
	mass[17](hu, ap, list);
	mass[18](hu, ap, list);
	//mass[19](hu, ap);
	mass[20](hu, list);
}

void	fundament(func *mass)
{
	mass[1] = print_int;
	mass[2] = print_str;
	mass[3] = print_symb;
	//mass[4] = cast_func;
	//mass[5] = print_ld;
	//mass[6] = print_long_l;
	mass[7] = print_i;
	//mass[8] = print_llu;
	mass[9] = print_o;
	mass[10] = print_u;
	mass[11] = print_procent;
	//mass[12] = print_lu;
	//mass[13] = print_hu;
	//mass[14] = print_hi;
	//mass[15] = print_hd;
	//mass[16] = print_lli;
	mass[17] = print_x;
	mass[18] = print_X;
	//mass[19] = print_float;
	//mass[20] = one_proc;
}

//int			ft_printf(char *hu, ...)
//{
//	func *mass;
//	va_list ap;
//	t_node  *list;
//
//	list = (t_node *)malloc(sizeof(t_node));
//	list->len = 0;
//	mass = (void *) malloc(sizeof(void) * 250);
//	va_start(ap, hu);
//	mass[0] = fundament;
//	mass[0](mass);
//	while(*hu)
//	{
//		if (*hu != '%')
//		{
//			ft_putchar(*hu);
//			list->len++;
//		}
//		else if (*hu == '%')
//		{
//			//list->len++;
//			hu++;
//			mass[4](hu, ap, mass, list);
//			if (*hu == 'l' || *hu == 'h')
//			{
//				hu++;
//				if (*hu == 'u' || *hu == 'i')
//					hu--;
//				if (*hu != 'd')
//					hu++;
//			}
//		}
//		hu++;
//	}
//	free(mass);
//	va_end(ap);
//	return(list->len);
//}


/*int		main(int ac, char **av)
{
	int	f;
	//char a;
	//int	d;
	//long long int l;

	//a = 'r';
	//d = -343434453;
	//l = 9223372036854775807;
	//ll = −92233720368547;
	if (ac > 0)
	{
		av[0] = 0;
		f = printf("pr: %lu\n", 18446744073709551574);
		printf("1F: %d\n", f);
		f = ft_printf("ft: %lu\n", 18446744073709551574);
		printf("2F: %d\n", f);
	}
	return (0);
} */
