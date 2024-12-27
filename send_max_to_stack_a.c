/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_max_to_stack_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:55:39 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/17 19:55:40 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *s)
{
	int	j;
	int	max;
	int	max_j;

	j = s->j;
	max_j = -2147483648;
	while (j < s->element_cnt)
	{
		if (s->b[j] > max)
		{
			max_j = j;
			max = s->b[j];
		}
		j++;
	}
	return (max_j);
}

void	send_max_to_stack_a(t_stack *s)
{
	int	max_j;
	int	max;

	max_j = find_max(s);
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
