/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:00:08 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 18:21:14 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./ft_printf/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack	t_stack;

struct		s_stack
{
	int		data;
	int		number;
	int		way;
	int		near_left;
	t_stack	*next;
};

typedef struct s_ps		t_ps;

struct		s_ps
{
	void	(*funk_one[4])(t_stack **);
	void	(*funk_two[4])(t_stack **, t_stack **);
	t_stack	*stacks[2];
	int		len_sa;
	int		len_sb;
	int		d;
	int		**cpy_arg;
};

t_stack		*make_instance_of_struct(int data, int num);
t_ps		*make_struct(t_stack **s_a);
t_stack		*make_list(char **av, int ac);
t_stack		*valid_arg(char **av);
t_ps		*validation(char **av);
void		print_list_debug(t_stack *a, t_stack *b);
int			**cpy_list_ar(t_stack *list, int len);
int			lstsize_test(t_stack *begin_list);
void		numeric_lst(t_stack **lst);
void		cut(t_ps *my_s);
void		free_struct(t_ps *my_s);
void		free_lst(t_stack **s);
void		free_int_arr(int **arr, int len);
void		free_arr(char **arr);
void		error(t_ps *my_s);
char		*arr_to_str(char **av, int ac);
int			get_next_line(const int fd, char **line);

/*
**                   find optimal way and move drum
*/

void		to_top(t_stack **s, int num, t_ps *my_s, char stack);
void		move_drum(t_stack **s, int num, t_ps *my_s, char stack);
int			is_last_elem(t_stack *s_a, t_stack *s_b, int optimal);
void		check_double_moving(t_stack **a, t_stack **b, int num,
			t_ps *my_s);
int			find_optimal_way(t_ps *my_s);

/*
**                              sorting
*/
int			is_sort(t_stack *list);
void		sort_list(t_stack *list);
void		sort_int_arr(int	***arr, int len);
void		start_sorting(t_ps *my_s);
void		cut_three(t_ps *my_s);
void		b_to_a(t_ps *my_s, int optim);
void		check_drum_position(t_ps *my_s);
int			find_min(t_stack *s);
t_stack		*find_max(t_stack *s);
/*
**                              commands
*/

void		swap_swap(t_stack **a, t_stack **b);
void		swap_stack(t_stack **s);
void		push(t_stack **add, t_stack **take);
void		rev_rotate(t_stack **s);
void		rev_rotate_twice(t_stack **a, t_stack **b);
void		rotate(t_stack **s);
void		rotate_twice(t_stack **a, t_stack **b);
int			check_command(char *line, t_ps *my_s);
void		apply_com(t_ps *my_s, char *buff);

#endif
