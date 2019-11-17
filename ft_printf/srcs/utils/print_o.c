/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:18:37 by galiza            #+#    #+#             */
/*   Updated: 2019/07/14 19:05:47 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int	if_n(t_flags flags, va_list ap)
{
	unsigned long long int		n;

	if (flags.flags & LL)
		n = va_arg(ap, unsigned long long int);
	else if (flags.flags & L)
		n = va_arg(ap, unsigned long long int);
	else if (flags.flags & H && !(flags.flags & HH))
		n = (short unsigned int)va_arg(ap, int);
	else if (flags.flags & HH)
		n = (unsigned char)va_arg(ap, int);
	else
		n = va_arg(ap, unsigned int);
	return (n);
}

static int						if_minus(t_flags flags, int len, int s,
		unsigned long long int n)
{
	len += ft_print_keys(flags, s);
	if (flags.h_tag && n)
	{
		ft_putchar('0');
		len++;
	}
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putun_nbr_base(ABS(n), 8, "01234567");
	len += ft_print_spaces(flags, s);
	return (len);
}

static int						if_zero(t_flags flags, int len, int s,
		unsigned long long int n)
{
	len += ft_print_keys(flags, s);
	len += ft_print_spaces(flags, s);
	if (flags.h_tag && n)
	{
		ft_putchar('0');
		len++;
	}
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putun_nbr_base(ABS(n), 8, "01234567");
	return (len);
}

static int						if_else(t_flags flags, int len, int s,
		unsigned long long int n)
{
	len += ft_print_spaces(flags, s);
	len += ft_print_keys(flags, s);
	if (flags.h_tag && n && flags.t_dot < 1)
	{
		ft_putchar('0');
		len++;
	}
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putun_nbr_base(ABS(n), 8, "01234567");
	if (flags.dot && !n && flags.h_tag)
	{
		ft_putchar('0');
		len++;
	}
	return (len);
}

int								ft_print_o(const char *fmt, va_list ap,
						int curr_chr, int len)
{
	t_flags					flags;
	int						s;
	unsigned long long int	n;

	ft_get_keys(fmt, curr_chr, &flags);
	flags.base = 8;
	n = if_n(flags, ap);
	if (flags.t_dot < 0)
	{
		len = print_o_norminnet(flags, len, n);
		return (ft_printf_aux(fmt, ap, curr_chr + flags.len +
		1, len));
	}
	s = print_o_norm(&flags, 0, n);
	if (flags.h_tag && n)
		s++;
	if (if_long(fmt, curr_chr, flags) && !flags.dot)
		flags.zero = 1;
	if (flags.minus)
		len = if_minus(flags, len, s, n);
	else if (flags.zero)
		len = if_zero(flags, len, s, n);
	else
		len = if_else(flags, len, s, n);
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}
