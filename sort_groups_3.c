/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_groups_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:39:56 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/20 17:40:00 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_i_b(t_stack *s)
{
	int	j;
	int	max;
	int	max_j;

	j = s->j;
	max = -2147483648;
	while (j < s->element_cnt)
	{
		if (max < s->b[j])
		{
			max = s->b[j];
			max_j = j;
		}
		j++;
	}
	return (max_j);
}

void	send_b_max_to_a_top(t_stack *s)
{
	int	max;
	int	max_j;

	max_j = find_max_i_b(s);
	max = s->b[max_j];
	while (max != s->b[s->j])
	{	
		if (max_j <= s->j + (((s->element_cnt - 1) - s->j + 1) / 2))
			rotate_b(s, 1);
		else
			reverse_rotate_b(s, 1);
	}
	push_a(s);
}

void	sort_ascending(t_stack *s)
{
	int	min;
	int	min_i;

	min_i = find_min_value_index_in_a(s);
	min = s->a[min_i];
	while (min != s->a[s->i])
	{	
		if (min_i <= s->i + (((s->element_cnt - 1) - s->i + 1) / 2))
			rotate_a(s, 1);
		else
			reverse_rotate_a(s, 1);
	}
}

void	sort_groups(t_stack *s)
{
	while (s->j != s->element_cnt)
	{
		find_min_cost_combi(s);
		min_cost_value_to_top_a(s);
		min_cost_value_to_top_b(s);
		push_a(s);
	}
	sort_ascending(s);
}
