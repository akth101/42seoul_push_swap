/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_only_group_to_stack_b.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:14:49 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/11 14:14:50 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_first_and_send_to_b(t_stack *s)
{
	int		first_group;
	int		first_i;

	while (1)
	{
		first_i = find_first(s);
		if (first_i == -1)
			break ;
		first_group = s->a[first_i];
		while (first_group != s->a[s->i])
		{	
			if (first_i <= s->i + (((s->element_cnt - 1) - s->i + 1) / 2))
				rotate_a(s, 1);
			else
				reverse_rotate_a(s, 1);
		}
		push_b(s);
	}
}

int	find_pivot_index(t_stack *s, int pivot)
{
	int	i;

	i = s->i;
	while (i < s->element_cnt)
	{
		if (pivot == s->a[i])
			return (i);
		i++;
	}
	return (0);
}

void	send_pivot_to_stack_b(t_stack *s, int index)
{
	int	pivot_2;
	int	pivot_index;

	pivot_2 = s->pivot_ary[index];
	pivot_index = find_pivot_index(s, pivot_2);
	while (pivot_2 != s->a[s->i])
	{	
		if (pivot_index <= s->i + (((s->element_cnt - 1) - s->i + 1) / 2))
			rotate_a(s, 1);
		else
			reverse_rotate_a(s, 1);
	}
	push_b(s);
}

void	send_groups_to_stack_b(t_stack *s)
{
	find_last_and_send_to_b(s);
	send_pivot_to_stack_b(s, 1);
	find_middle_and_send_to_b(s);
	send_pivot_to_stack_b(s, 0);
	find_first_and_send_to_b(s);
}
