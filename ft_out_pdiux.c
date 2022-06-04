/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_pdiux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:55:30 by kiijima           #+#    #+#             */
/*   Updated: 2022/05/31 08:43:17 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_out_u_x(unsigned int un, char spec)
{
	ssize_t	len;

	if (spec == 'u')
	{
		len = count_digits_u((unsigned long long)un, 10);
		ft_putnbr_u_fd((unsigned long long)un, 10, "0123456789");
	}
	else
	{
		len = count_digits_u((unsigned long long)un, 16);
		if (spec == 'x')
			ft_putnbr_u_fd((unsigned long long)un, 16, "0123456789abcdef");
		else if (spec == 'X')
			ft_putnbr_u_fd((unsigned long long)un, 16, "0123456789ABCDEF");
	}
	return (len);
}

ssize_t	ft_out_p(unsigned long long llu)
{
	write(1, "0x", 2);
	ft_putnbr_u_fd(llu, 16, "0123456789abcdef");
	return (count_digits_u(llu, 16) + 2);
}

ssize_t	ft_out_d_i(int n)
{
	ft_putnbr_di_fd(n);
	return (count_digits(n));
}
