/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drum.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:59:39 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 17:36:08 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	to_top(t_stack **s, int num, t_ps *my_s, char stack)
{
	int		count;
	int		len;
	t_stack	*tmp;

	count = 0;
	tmp = *s;
	len = stack == 'a' ? my_s->len_sa : my_s->len_sb;
	while (tmp && tmp->number != num)
		tmp = tmp->next;
	if (num <= (len / 2) + 1)
		while ((*s)->number != num)
		{
			my_s->funk_one[1](s);
			ft_printf("r%c\n", stack);
			count++;
		}
	else
	{
		while ((*s)->number != num)
		{
			my_s->funk_one[2](s);
			ft_printf("rr%c\n", stack);
			count++;
		}
	}
}

void	move_drum(t_stack **s, int num, t_ps *my_s, char stack)
{
	t_stack *tmp;

	tmp = *s;
	while (tmp->number != num)
		tmp = tmp->next;
	if (num <= my_s->len_sa / 2)
	{
		while (tmp->next != NULL)
		{
			my_s->funk_one[1](s);
			ft_printf("r%c\n", stack);
		}
	}
	else
	{
		while (tmp->next != NULL)
		{
			my_s->funk_one[2](s);
			ft_printf("rr%c\n", stack);
		}
	}
}

int		is_last_elem(t_stack *s_a, t_stack *s_b, int optimal)
{
	t_stack *beg;
	t_stack *tmp;

	beg = s_a;
	tmp = s_b;
	while (tmp && tmp->number != optimal)
		tmp = tmp->next;
	while (beg->next && beg->number != tmp->near_left)
		beg = beg->next;
	if (beg->next != NULL)
		return (0);
	else
		return (1);
}

void	check_double_moving(t_stack **a, t_stack **b, int num, t_ps *my_s)
{
	t_stack *tmp_b;
	t_stack *tmp_a;

	tmp_b = *b;
	tmp_a = *a;
	while (tmp_b->number != num)
		tmp_b = tmp_b->next;
	while (tmp_a->number != tmp_b->near_left)
		tmp_a = tmp_a->next;
	if (num <= my_s->len_sb / 2 && tmp_b->near_left <= my_s->len_sa / 2)
	{
		while ((*b)->number != num && tmp_a->next != NULL)
		{
			my_s->funk_two[2](a, b);
			ft_printf("rr\n");
		}
	}
	else if (num > my_s->len_sb / 2 && tmp_b->near_left > my_s->len_sa / 2)
	{
		while ((*b)->number != num && tmp_a->next != NULL)
		{
			my_s->funk_two[3](a, b);
			ft_printf("rrr\n");
		}
	}
}

char	*arr_to_str(char **av, int ac)
{
	char	*new;
	int		i;
	int		i1;
	int		i2;

	new = NULL;
	if (ac == 2)
		return (av[0]);
	i = -1;
	i1 = 0;
	i2 = 0;
	while (av[++i])
	{
		i1 = 0;
		while (av[i][i1++])
			i2 += i1;
	}
	new = ft_strnew(i2 + i);
	i2 = 0;
	while (i2 < i)
	{
		ft_strcat(new, av[i2++]);
		ft_strcat(new, " ");
	}
	return (new);
}
