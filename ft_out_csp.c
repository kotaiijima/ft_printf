/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:56:03 by kiijima           #+#    #+#             */
/*   Updated: 2022/05/31 08:34:16 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_out_c(char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_out_s(char *s)
{
	ssize_t	len;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	return (write(1, s, len));
}

ssize_t	ft_out_non(const char **bef, const char **fmt)
{
	ssize_t	putlen;

	if (*fmt == NULL)
		return (-1);
	putlen = *fmt - *bef;
	write(1, *bef, putlen);
	return (putlen);
}
