/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_put_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:03:25 by kiijima           #+#    #+#             */
/*   Updated: 2022/05/30 15:38:34 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	count_digits(int n)
{
	ssize_t	i;
	int		j;

	i = 0;
	if (n <= 0)
		i++;
	j = n;
	while (j)
	{
		i++;
		j /= 10;
	}
	return (i);
}

void	ft_putnbr_di_fd(int n)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = num * -1;
	}
	if (num > 9)
		ft_putnbr_di_fd(num / 10);
	ft_putchar_fd((num % 10) + '0', 1);
}

ssize_t	count_digits_u(unsigned long long n, int num)
{
	ssize_t				i;
	unsigned long long	j;

	i = 0;
	if (n == 0)
		return (1);
	j = n;
	while (j)
	{
		i++;
		j /= num;
	}
	return (i);
}

void	ft_putnbr_u_fd(unsigned long long n, unsigned long long nb, char *s)
{
	if (n > (nb - 1))
	{
		ft_putnbr_u_fd(n / nb, nb, s);
	}
	ft_putchar_fd(s[n % nb], 1);
}
