/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:36:21 by bantario          #+#    #+#             */
/*   Updated: 2019/10/18 15:00:20 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

# define BUFF_SIZE 1024
# define TYPE_HH 1
# define TYPE_H 2
# define TYPE_LL 4
# define TYPE_L 3
# define TYPE_J 6
# define TYPE_Z 5
# define TYPE_L_UP 7

typedef struct	s_flags
{
	int			hash_key;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			length_type;
	char		type;
	char		buffer[BUFF_SIZE];
	int			bytes;
}				t_flags;

typedef struct	s_types
{
	char		type;
	int			(*f)();
}				t_types;

typedef struct	s_node
{
	int len;
	int	when_pr;
	int w_p2;
}				t_node;

double			part_int_ten(double n, int *size);
void			int_part(double *n, char **str, double mod, int *i);
void			float_part(double n, char **str, int *i, int rigor);
int				float_to_str(double n, char **s, int rigor);
int				print_f(va_list args, t_flags *flags);

int				display(void *s, int size, t_flags *flags);
int				pad(t_flags *flags, int size);
int				display_no_precent(char **format, t_flags *flags);
void			pad_nb(t_flags *flags, uintmax_t nb, int *size, char *base);
int				pad_str(t_flags *flags, int size, void *s);

void			init_flags(t_flags *flags);
int				define_flags(char **str, t_flags *flags);
int				define_width(char **str, t_flags *flags, va_list args);
int				define_precision(char **str, t_flags *flags, va_list args);
void			edit_type(char **str, t_flags *flags, int flag_type, int size);
int				define_length(char **str, t_flags *flags);
int				parser(char **str, va_list args, t_flags *flags);
int				call_type(char **str, va_list args, t_flags *flags);
int				ft_printf(char *format, ...);
intmax_t		type_nb(va_list args, t_flags flags);
uintmax_t		type_nb_u(va_list args, t_flags flags);

void			putnbr_base_intmax_t_u(uintmax_t nbr, char *str,
				uintmax_t str_length, t_flags *flags);
void			number_size_u(uintmax_t nbr, uintmax_t str_length, int *size);
int				hash_key(uintmax_t nb, t_flags *flags, int *size,
					char *hash_key_content);
void			display_sign(intmax_t nb, t_flags *flags);
int				display_d(t_flags *flags, int size, int precision, intmax_t nb);
int				print_base(va_list args, t_flags *flags, char *base, char *key);

int				print_d(va_list ap, t_flags *flags);
int				print_str(va_list ap, t_flags *flags);
int				print_symb(va_list args, t_flags *flags);
int				print_o(va_list ap, t_flags *flags);
int				print_u(va_list ap, t_flags *flags);
int				print_x(va_list ap, t_flags *flags);
int				print_procent(va_list args, t_flags *flags);
int				print_x_up(va_list ap, t_flags *flags);
int				print_u_up(va_list ap, t_flags *flags);
int				print_p(va_list args, t_flags *flags);

void			print_ld(char *hu, va_list ap, t_node *list);
void			print_long_l(char *hu, va_list ap, t_node *list);
void			print_llu(char *hu, va_list ap, t_node *list);
void			print_lu(char *hu, va_list ap, t_node *list);
void			print_hu(char *hu, va_list ap, t_node *list);
void			print_hi(char *hu, va_list ap, t_node *list);
void			print_hd(char *hu, va_list ap, t_node *list);
void			print_lli(char *hu, va_list ap, t_node *list);
void			func2_next(long long n, t_node *list);
void			func2(long long n, t_node *list);
void			func3_next(long long int n, t_node *list);
void			func3(long long int n, t_node *list);
void			one_proc(char *hu, t_node *list);

#endif
