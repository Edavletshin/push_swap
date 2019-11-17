/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:07:42 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 18:21:09 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	check_sorted(t_stack *s, t_ps *my_s)
{
	if (!(is_sort(s)))
		ft_printf("KO\n");
	else if (lstsize_test(my_s->stacks[1]))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_struct(my_s);
}

int		find_flag(char **av)
{
	int		i;
	char	*str;

	i = 0;
	str = *av;
	while (str[i])
	{
		if (i > 0 && str[i] == 'v')
		{
			str[i] = ' ';
			str[i - 1] = str[i - 1] == '-' ? ' ' : str[i - 1];
			return (1);
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_ps	*my_s;
	char	*buffer;
	int		flag;
	char	*s;

	flag = 0;
	s = NULL;
	buffer = NULL;
	if (ac != 1)
	{
		s = arr_to_str(&(av[1]), ac);
		flag = find_flag(&s);
		my_s = validation(&s);
		if (!(my_s) || !(my_s->stacks[0]))
			error(my_s);
		my_s->d = flag;
		apply_com(my_s, buffer);
		check_sorted(my_s->stacks[0], my_s);
		if (ac != 2)
			ft_strdel(&s);
	}
	else
		ft_printf("usage: ./checker [numeric arguments]\n");
	return (0);
}
