/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:05:37 by galiza            #+#    #+#             */
/*   Updated: 2019/12/01 19:48:06 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		main(int ac, char **av)
{
	t_ps	*my_s;
	char	*s;

	s = NULL;
	if (ac != 1)
	{
		s = arr_to_str(&(av[1]), ac);
		my_s = validation(&s);
		if (!(my_s && my_s->stacks[0]) || is_sort(my_s->stacks[0]))
		{
			if (!(my_s && my_s->stacks[0]))
				error(my_s);
			else
				free_struct(my_s);
		}
		else
		{
			start_sorting(my_s);
			free_struct(my_s);
		}
		if (ac != 2)
			ft_strdel(&s);
	}
	return (0);
}
