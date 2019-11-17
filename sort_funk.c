/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:05:23 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 18:20:58 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&(arr[i]));
		i++;
	}
	free(arr);
	arr = NULL;
}

void	b_to_a(t_ps *my_s, int optim)
{
	t_stack *beg_a;
	t_stack *beg_b;

	beg_a = my_s->stacks[0];
	beg_b = my_s->stacks[1];
	if (beg_b->number != optim && !(is_last_elem(beg_a, beg_b, optim)))
		check_double_moving(&beg_a, &beg_b, optim, my_s);
	if (beg_b->number != optim)
		to_top(&beg_b, optim, my_s, 'b');
	if (!(is_last_elem(beg_a, beg_b, optim)))
		move_drum(&beg_a, beg_b->near_left, my_s, 'a');
	my_s->funk_two[1](&beg_a, &beg_b);
	ft_printf("pa\n");
	my_s->stacks[0] = beg_a;
	my_s->stacks[1] = beg_b;
}

void	check_drum_position(t_ps *my_s)
{
	int		min_elem;
	t_stack	*s;

	min_elem = (my_s->cpy_arg)[0][0];
	s = my_s->stacks[0];
	while (s->data != min_elem)
		s = s->next;
	if (s->number != 1)
		to_top(&(my_s->stacks[0]), s->number, my_s, 'a');
}

void	start_sorting(t_ps *my_s)
{
	int	optim;

	cut(my_s);
	my_s->len_sb = lstsize_test(my_s->stacks[1]);
	my_s->len_sa -= my_s->len_sb;
	while (my_s->stacks[1])
	{
		numeric_lst(&(my_s->stacks[0]));
		numeric_lst(&(my_s->stacks[1]));
		optim = find_optimal_way(my_s);
		b_to_a(my_s, optim);
		my_s->len_sa++;
		my_s->len_sb--;
	}
	numeric_lst(&(my_s->stacks[0]));
	check_drum_position(my_s);
}
