/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:06:07 by kiijima           #+#    #+#             */
/*   Updated: 2022/05/31 08:48:54 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<limits.h>
# include	<stdarg.h>
# include	<stdlib.h>
# include	<unistd.h>
// #include	<stdio.h>
// #include	<string.h>

int		ft_printf(const char *format, ...);
void	ft_input_perc(const char **bef, const char **fmt, va_list *ap, \
	ssize_t *byte);
ssize_t	ft_out_d_i(int n);
ssize_t	ft_out_u_x(unsigned int un, char spec);
ssize_t	ft_out_p(unsigned long long lln);
ssize_t	ft_out_c(char c);
ssize_t	ft_out_s(char *s);
ssize_t	ft_out_non(const char **bef, const char **fmt);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_u_fd(unsigned long long n, unsigned long long nb, char *s);
void	ft_putnbr_di_fd(int n);
ssize_t	count_digits_u(unsigned long long n, int num);
ssize_t	count_digits(int n);

#endif
