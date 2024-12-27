/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:50:14 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/22 21:50:15 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_in_a(t_stack *s)
{
	int	i;
	int	max;
	int	max_i;

	i = s->i;
	max = -2147483648;
	while (i < s->element_cnt)
	{
		if (s->a[i] > max)
		{
			max_i = i;
			max = s->a[i];
		}
		i++;
	}
	return (max_i);
}

void	send_max_to_stack_b(t_stack *s)
{
	int	max_i;
	int	max;

	max_i = find_max_in_a(s);
	max = s->a[max_i];
	while (max != s->a[s->i])
	{	
		if (max_i <= s->i + (((s->element_cnt - 1) - s->i + 1) / 2))
			rotate_a(s, 1);
		else
			reverse_rotate_a(s, 1);
	}
	push_b(s);
}

void	element_four(t_stack *s)
{
	send_max_to_stack_b(s);
	element_three(s);
	push_a(s);
	rotate_a(s, 1);
}
