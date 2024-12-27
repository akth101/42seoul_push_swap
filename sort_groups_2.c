/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_groups_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:34:30 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/20 17:34:31 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_cost_combi(t_stack *s)
{
	int	min_cost_a;
	int	min_cost_b;
	int	min_i;
	int	min_j;
	int	min_cost_all;

	min_cost_a = 2147483647;
	min_cost_b = 2147483647;
	min_cost_all = 2147483647;
	s->temp = s->j - 1;
	while (++(s->temp) < s->element_cnt)
	{
		min_cost_b = find_cost_b(s, s->temp, &min_j);
		min_cost_a = find_cost_a(s, s->temp, &min_i);
		if (abs(min_cost_a) + abs(min_cost_b) < min_cost_all)
		{
			s->min_cost_a = min_cost_a;
			s->min_cost_b = min_cost_b;
			s->min_i = min_i;
			s->min_j = min_j;
			min_cost_all = abs(min_cost_a) + abs(min_cost_b);
		}
	}
}

void	min_cost_value_to_top_a(t_stack *s)
{
	int	min;

	min = s->a[s->min_i];
	if (s->min_cost_a == 0)
		return ;
	if (s->min_cost_a > 0)
	{
		while (min != s->a[s->i])
			rotate_a(s, 1);
	}
	if (s->min_cost_a < 0)
	{
		while (min != s->a[s->i])
			reverse_rotate_a(s, 1);
	}
}

void	min_cost_value_to_top_b(t_stack *s)
{
	int	min;

	min = s->b[s->min_j];
	if (s->min_cost_b == 0)
		return ;
	if (s->min_cost_b > 0)
	{
		while (min != s->b[s->j])
			rotate_b(s, 1);
	}
	if (s->min_cost_b < 0)
	{
		while (min != s->b[s->j])
			reverse_rotate_b(s, 1);
	}
}

int	find_min_value_index_in_a(t_stack *s)
{
	int	i;
	int	min;
	int	min_i;

	min = 2147483647;
	min_i = 2147483647;
	i = s->i;
	while (i < s-> element_cnt)
	{
		if (min > s->a[i])
		{
			min = s->a[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}
