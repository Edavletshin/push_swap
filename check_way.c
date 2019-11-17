/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:54:13 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 18:12:11 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		check_smallest_elem(t_stack *s, int cur_elem)
{
	t_stack *start;

	start = s;
	while (start->next)
	{
		if (start->data < cur_elem)
			return (0);
		start = start->next;
	}
	if (start->data < cur_elem)
		return (0);
	return (start->number);
}

int		find_place(t_stack *s, t_stack *cur_elem, int *way)
{
	t_stack		*start;
	int			near_int;

	start = s;
	near_int = -2147483648;
	while (start)
	{
		if (cur_elem->data > start->data && near_int < start->data)
		{
			near_int = start->data;
			cur_elem->near_left = start->number;
			*way = start->number;
		}
		start = start->next;
	}
	if (*way == -1)
	{
		start = find_max(s);
		cur_elem->near_left = start->number;
		if (start->next != NULL)
			*way = start->number;
	}
	if (*way == 0)
		*way = check_smallest_elem(s, cur_elem->data);
	return (*way);
}

int		best_way(int top_a, int top_b, int bot_a, int bot_b)
{
	int way[4];
	int i;
	int min;

	i = 0;
	way[0] = top_a > top_b ? top_a : top_b;
	way[1] = top_a + bot_b;
	way[2] = bot_a > bot_b ? bot_a : bot_b;
	way[3] = bot_a + top_b;
	min = way[0];
	while (i < 4)
	{
		if (min > way[i])
			min = way[i];
		i++;
	}
	return (min);
}

void	calculate_way(t_ps *my_s, t_stack *cur)
{
	int top_a;
	int top_b;
	int bot_a;
	int bot_b;

	top_a = -1;
	top_b = 0;
	bot_a = 0;
	bot_b = 0;
	find_place(my_s->stacks[0], cur, &top_a);
	bot_a = my_s->len_sa - top_a;
	bot_b = my_s->len_sb - cur->number + 1;
	top_b = my_s->len_sb - bot_b;
	cur->way = best_way(top_a, top_b, bot_a, bot_b);
}

int		find_optimal_way(t_ps *my_s)
{
	t_stack		*start;
	int			num;

	start = my_s->stacks[1];
	while (start)
	{
		calculate_way(my_s, start);
		start = start->next;
	}
	num = find_min(my_s->stacks[1]);
	return (num);
}
