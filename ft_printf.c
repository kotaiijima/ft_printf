/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:08:08 by kiijima           #+#    #+#             */
/*   Updated: 2022/05/31 08:43:29 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(const char **bef, const char **fmt, ssize_t *byte)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *bef, (*fmt - *bef));
	*byte += (*fmt - *bef);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	ssize_t		byte;
	const char	*bef;

	byte = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		byte = -1;
	while (byte >= 0 && *fmt != '\0')
	{
		bef = fmt;
		if (*bef != '%')
			ft_print_str(&bef, &fmt, &byte);
		else
			ft_input_perc(&bef, &fmt, &ap, &byte);
		if (byte >= INT_MAX)
			return (-1);
	}
	va_end(ap);
	return (byte);
}

// int main()
// {
// 	   printf("or:%d\n",    printf("or;%X\n",100));
// 	   printf("ft:%d\n", ft_printf("ft;%X\n",100));
// }
