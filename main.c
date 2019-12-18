<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:54:43 by bantario          #+#    #+#             */
/*   Updated: 2019/12/02 17:01:55 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include "stdlib.h"
#include <stdarg.h>

void	print_int(char *hu, va_list ap, t_node *list)
{
	int		dval;

	if (*hu == 'd')
	{
		dval = va_arg(ap, int);
		ft_putnbr(dval);
		list->len = (list->len) + ft_strlen(ft_itoa(dval));
	}
}

void	print_str(char *hu, va_list ap, t_node *list)
{
	char	*str;

	if (*hu == 's')
	{
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
	}
}

void	print_symb(char *hu, va_list ap, t_node *list)
{
	char	cval;

	if (*hu == 'c')
	{
		cval = va_arg(ap, int);
		ft_putchar(cval);
		list->len++; 
	}
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

void	print_i(char *hu, va_list ap, t_node *list)
{
	signed int		chislo;
	char			*hex_to_numb;

	if (*hu == 'i')
	{
		chislo = va_arg(ap, signed int);
		hex_to_numb = ft_itoa(chislo);
		ft_putnbr(ft_atoi(hex_to_numb));
		list->len = list->len + ft_strlen(hex_to_numb);
	}
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

void	print_o(char *hu, va_list ap, t_node *list)
{
	int oo;

	if (*hu == 'o')
	{
		oo = va_arg(ap, unsigned int);
		if (oo == 0)
		{
			ft_putnbr(0);
			list->len++;
		}
		Func(oo, list);
	}
}

void	print_u(char *hu, va_list ap, t_node *list)
{
	long long int	uu;

	if (*hu == 'u')
	{
		uu = va_arg(ap, long long int);
		if (uu < 0)
		{
			ft_putstr("4294967295");
			list->len = list->len + 10;
			return;
		}
		if (uu > 4294967295)
		{
			ft_putchar('0');
			list->len++;
			return;
		}
		ft_putnbr(uu);
		list->len = list->len + ft_strlen(ft_itoa(uu));
	}
}

void	print_procent(char *hu, t_node *list)
{
	if (*hu == '%')
	{
		list->len++;
		ft_putchar('%');
	}
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

void	print_zero(t_node *list)
{
	ft_putchar('0');
	list->len++;
	return;
}

void	print_x(char *hu, va_list ap, t_node *list)
{
	long long int		dec;
	char	*str;

	dec = 0;
	if (*hu == 'x')
	{
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
	}
}

void	print_X(char *hu, va_list ap, t_node *list)
{
	long long int dec;
	char *str;

	dec = 0;
	if (*hu == 'X')
	{
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
	}
}

void	print_float(char *hu, va_list ap)
{
	char *str;
	double fl;

	if (*hu == 'f')
	{
		str = (char *)malloc(sizeof(int) *1000);
		fl = va_arg(ap, double);
		float_to_str(fl, str, 6);
	}
}

void	one_proc(char *hu, t_node *list)
{
	if (*hu == '\0')
		list->len = 0;
}

void	print_l_x(char *hu, va_list ap, t_node *list)
{
	long long int	dec;
	char			*str;

	if (*hu == 'l' && *++hu == 'x')
	{
		dec = va_arg(ap, long long int);
		str = ft_itoa(dec);
		if (str[0] == '-')
		{
			dec = (-1) * dec * 4294967295;
			list->when_pr = 1;
		}
		else
			list->when_pr = 8;
		if (dec == 0)
			print_zero(list);
		Func2(dec, list);
		free(str);
	}
}

void	print_l_l_x(char *hu, va_list ap, t_node *list)
{
	long long int	dec;
	char			*str;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'l' && *++hu == 'x')
		{
			dec = va_arg(ap, long long int);
			str = ft_itoa(dec);
			if (str[0] == '-')
			{
				dec = (-1) * dec * 4294967295;
				list->when_pr = 1;
			}
			else
				list->when_pr = 8;
			if (dec == 0)
				print_zero(list);
			Func2(dec, list);
			free(str);
		}
	}
}

void	print_l_l_X(char *hu, va_list ap, t_node *list)
{
	long long int	dec;
	char			*str;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'l' && *++hu == 'X')
		{
			dec = va_arg(ap, long long int);
			str = ft_itoa(dec);
			if (str[0] == '-')
			{
				dec = (-1) * dec * 4294967295;
				list->when_pr = 1;
			}
			else
				list->when_pr = 8;
			if (dec == 0)
				print_zero(list);
			Func3(dec, list);
			free(str);
		}
	}
}

void	Func4_next(long long int n, t_node *list)
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

void	Func4(long long int n, t_node *list)
{
	if (n > 4294967295)
	{
		ft_putchar('0');
		return;
	}
	if (n != 0)
	{
		list->len++;
		Func4(n / 16, list);
		list->when_pr++;
	}
	else
		return;
	Func4_next(n, list);
}

void	print_h_x(char *hu, va_list ap, t_node *list)
{
	unsigned short			dec;
	char					*str;

	if (*hu == 'h' && *++hu == 'x')
	{
		dec = va_arg(ap, int);
		str = ft_itoa(dec);
		if (str[0] == '-')
		{
			dec = (-1) * dec * 4294967295;
			list->when_pr = 1;
		}
		else
			list->when_pr = 8;
		if (dec == 0)
			print_zero(list);
		Func4(dec, list);
		free(str);
	}
}

void	Func5_next(long long int n, t_node *list)
{
	if ((n % 16) == 15)
		ft_putchar('F');
	else if ((n % 16) == 10)
		ft_putchar('A');
	else if ((n % 16) == 11)
		ft_putchar('B');
	else if ((n % 16) == 12)
		ft_putchar('C');
	else if ((n % 16) == 13)
		ft_putchar('D');
	else if ((n % 16) == 14)
		ft_putchar('E');
	else
		if (list->when_pr > 7)
			ft_putnbr(n % 16);
		else
			list->len--;
}

void	Func5(long long int n, t_node *list)
{
	if (n > 4294967295)
	{
		ft_putchar('0');
		return;
	}
	if (n != 0)
	{
		list->len++;
		Func5(n / 16, list);
		list->when_pr++;
	}
	else
		return;
	Func5_next(n, list);
}

void	print_h_h_X(char *hu, va_list ap, t_node *list)
{
	unsigned char	dec;
	char			*str;

	if (*hu == 'h')
	{
		hu++;
		if (*hu == 'h' && *++hu == 'X')
		{
			dec = va_arg(ap, int);
			str = ft_itoa(dec);
			if (str[0] == '-')
			{
				dec = (-1) * dec * 4294967295;
				list->when_pr = 1;
			}
			else
				list->when_pr = 8;
			if (dec == 0)
				print_zero(list);
			Func5(dec, list);
			free(str);
		}
	}
}

void	print_hhd(char *hu, va_list ap, t_node *list)
{
	signed char		val;

	if	(*hu == 'h')
	{
		hu++;
		if (*hu == 'h' && *++hu == 'd')
		{
			val = va_arg(ap, int);
			ft_putnbr(val);
			list->len = list->len + ft_strlen(ft_itoa(val));
		}
	}
}

void    print_h_h_x(char *hu, va_list ap, t_node *list)
{
        unsigned char   dec;
        char                    *str;

        if (*hu == 'h')
        {
                hu++;
                if (*hu == 'h' && *++hu == 'x')
                {
                        dec = va_arg(ap, int);
                        str = ft_itoa(dec);
                        if (str[0] == '-')
                        {
                                dec = (-1) * dec * 4294967295;
                                list->when_pr = 1;
                        }
                        else
                                list->when_pr = 8;
                        if (dec == 0)
                                print_zero(list);
                        Func4(dec, list);
                        free(str);
                }
        }
}

void    print_h_X(char *hu, va_list ap, t_node *list)
{
        unsigned short                  dec;
        char                                    *str;

        if (*hu == 'h' && *++hu == 'X')
        {
                dec = va_arg(ap, int);
                str = ft_itoa(dec);
                if (str[0] == '-')
                {
                        dec = (-1) * dec * 4294967295;
                        list->when_pr = 1;
                }
                else
                        list->when_pr = 8;
                if (dec == 0)
                        print_zero(list);
                Func5(dec, list);
                free(str);
        }
}

void    print_l_X(char *hu, va_list ap, t_node *list)
{
        long long int   dec;
        char                    *str;

        if (*hu == 'l' && *++hu == 'X')
        {
                dec = va_arg(ap, long long int);
                str = ft_itoa(dec);
                if (str[0] == '-')
                {
                        dec = (-1) * dec * 4294967295;
                        list->when_pr = 1;
                }
                else
                        list->when_pr = 8;
                if (dec == 0)
                        print_zero(list);
                Func3(dec, list);
                free(str);
        }
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
	mass[19](hu, ap);
	mass[20](hu, list);
	mass[21](hu, ap, list);
	mass[22](hu, ap, list);
	mass[23](hu, ap, list);
	mass[24](hu, ap, list);
	mass[25](hu, ap, list);
	mass[26](hu, ap, list);
	mass[27](hu, ap, list);
	mass[28](hu, ap, list);
	mass[29](hu, ap, list);
}

void	fundament(func *mass)
{
	mass[1] = print_int;
	mass[2] = print_str;
	mass[3] = print_symb;
	mass[4] = cast_func;
	mass[5] = print_ld;
	mass[6] = print_long_l;
	mass[7] = print_i;
	mass[8] = print_llu;
	mass[9] = print_o;
	mass[10] = print_u;
	mass[11] = print_procent;
	mass[12] = print_lu;
	mass[13] = print_hu;
	mass[14] = print_hi;
	mass[15] = print_hd;
	mass[16] = print_lli;
	mass[17] = print_x;
	mass[18] = print_X;
	mass[19] = print_float;
	mass[20] = one_proc;
	mass[21] = print_l_x;
	mass[22] = print_l_l_x;
	mass[23] = print_l_l_X;
	mass[24] = print_h_x;
	mass[25] = print_h_h_X;
	mass[26] = print_hhd;
	mass[27] = print_h_h_x;
	mass[28] = print_h_X;
	mass[29] = print_l_X;
}

int			ft_printf(char *hu, ...)
{
	func *mass;
	va_list ap;
	t_node  *list;

	list = (t_node *)malloc(sizeof(t_node));
	list->len = 0;
	mass = (void *) malloc(sizeof(void) * 250);
	va_start(ap, hu);
	mass[0] = fundament;
	mass[0](mass);
	while(*hu)
	{
		if (*hu != '%')
		{
			ft_putchar(*hu);
			list->len++;
		}
		else if (*hu == '%')
		{
			hu++;
			mass[4](hu, ap, mass, list);
			if (*hu == 'l' || *hu == 'h')
			{
				hu++;
				if (*hu == 'u' || *hu == 'i' || *hu == 'x' || *hu == 'X')
					hu--;
				if (*hu != 'd')
					hu++;
			}
		}
		hu++;
	}
	free(mass);
	va_end(ap);
	return(list->len);
}

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
		f = printf("pr: %lX\n", 4294967295);
		printf("1F: %d\n", f);
		f = ft_printf("ft: %lX\n", 4294967295);
		printf("2F: %d\n", f);
	}
	return (0);
} */
=======
#include "./includes/ft_printf.h"


int main()
{
	ft_printf("str: %32s\n",NULL);
	printf("str: %32s \n",NULL);
	return (0);
}
>>>>>>> mrr
