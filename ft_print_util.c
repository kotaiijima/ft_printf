/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:29:05 by kiijima           #+#    #+#             */
/*   Updated: 2022/05/31 08:42:58 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_output(const char **bef, const char **fmt, va_list *ap, char spec)
{
	ssize_t	putlen;

	putlen = 0;
	if (spec == '\0')
		return (ft_out_non(bef, fmt));
	if (spec == 'c')
		putlen = ft_out_c((char)va_arg(*ap, int));
	else if (spec == 's')
		putlen = ft_out_s((char *)va_arg(*ap, char *));
	else if (spec == 'p')
		putlen = ft_out_p((unsigned long long)va_arg(*ap, void *));
	else if (spec == 'd' || spec == 'i')
		putlen = ft_out_d_i((int)va_arg(*ap, int));
	else if (spec == 'u' || spec == 'x' || spec == 'X')
		putlen = ft_out_u_x((unsigned int)va_arg(*ap, unsigned int), spec);
	else if (spec == '%')
	{
		ft_putchar_fd('%', 1);
		putlen = 1;
	}
	return (putlen);
}

char	ft_strchr_ex(const char *s, char c)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c)
			return (s[i]);
		i++;
	}
	return (0);
}

void	ft_input_perc(const char **bef, const char **fmt, va_list *ap, \
	ssize_t *byte)
{
	char	spec;

	(*fmt)++;
	spec = ft_strchr_ex("cspdiuxX%", *((*fmt)++));
	*byte += ft_output(bef, fmt, ap, spec);
}
