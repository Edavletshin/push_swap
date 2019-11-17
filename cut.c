/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:59:24 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 17:41:12 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_three(t_stack *l, t_ps *my_s)
{
	int a;
	int b;
	int c;

	a = l->data;
	b = l->next->data;
	c = l->next->next->data;
	if ((a < b && a < c && b > c) ||
			(a > b && b < c && a < c) ||
			(a > b && b > c && a > c))
	{
		my_s->funk_one[0](&l);
		ft_printf("sa\n");
	}
}

void	cut_three(t_ps *my_s)
{
	t_stack *start;
	int		i;

	start = my_s->stacks[0];
	i = 3;
	while (i < my_s->len_sa)
	{
		my_s->funk_two[1](&((my_s->stacks)[1]), &start);
		ft_printf("pb\n");
		my_s->stacks[0] = start;
		i++;
	}
	if (my_s->len_sa >= 3)
		sort_three(my_s->stacks[0], my_s);
}

void	cut_seq(t_ps *my_s, int len, int start)
{
	t_stack *first;
	int		i;

	first = my_s->stacks[0];
	i = 0;
	while (i <= my_s->len_sa)
	{
		if (i == start)
		{
			while (i++ - start <= len)
			{
				my_s->funk_one[1](&(first));
				ft_printf("ra\n");
			}
			my_s->stacks[0] = first;
		}
		my_s->funk_two[1](&((my_s->stacks)[1]), &first);
		ft_printf("pb\n");
		my_s->stacks[0] = first;
		i++;
	}
}

void	find_sort_sequence(t_stack *s, int *a, int *len)
{
	int		count;
	t_stack *tmp_end;

	count = 0;
	tmp_end = NULL;
	while (s)
	{
		while (s->next && s->data < s->next->data)
		{
			count++;
			s = s->next;
			if (s->next == NULL || s->data > s->next->data)
			{
				tmp_end = count >= *len ? s : tmp_end;
				*len = count >= *len ? count : *len;
				count = 0;
			}
		}
		s = s->next;
	}
	if (tmp_end)
		*a = tmp_end->number - *len;
}

void	cut(t_ps *my_s)
{
	int start_seq;
	int len_seq;

	len_seq = 0;
	start_seq = 0;
	find_sort_sequence(my_s->stacks[0], &start_seq, &len_seq);
	if (len_seq > 3)
		cut_seq(my_s, len_seq, start_seq);
	else
		cut_three(my_s);
}
