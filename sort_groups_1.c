/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_groups.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:30:21 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/13 15:30:22 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cost_a(t_stack *s, int j, int *min_i)
{
	*min_i = find_min_pos_among_bigger_than_b(s, j);
	if (*min_i <= s->i + (((s->element_cnt - 1) - s->i + 1) / 2))
		return (*min_i - s->i);
	else
		return ((s->element_cnt - *min_i) * -1);
	return (-1);
}

int	find_cost_b(t_stack *s, int j, int *min_j)
{
	*min_j = j;
	if (j <= s->j + (((s->element_cnt - 1) - s->j + 1) / 2))
		return (j - s->j);
	else
		return ((s->element_cnt - j) * -1);
	return (-1);
}

int	find_min_pos_among_bigger_than_b(t_stack *s, int j)
{
	int	min;
	int	min_i;
	int	i;

	min = 2147483647;
	i = s->i;
	while (i < s->element_cnt)
	{
		if (s->b[j] < s->a[i] && s->a[i] < min)
		{
			min = s->a[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

int	abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}
