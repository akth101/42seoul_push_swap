/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:28:56 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/30 15:28:58 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stackdup(int *stack_a, int element_cnt)
{
	int		*res;
	int		i;

	res = (int *)malloc(element_cnt * sizeof(int));
	i = -1;
	while (++i < element_cnt)
		res[i] = stack_a[i];
	return (res);
}

void	sort(int *stack_a_copy, int element_cnt)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < element_cnt)
	{
		j = i + 1;
		while (j < element_cnt)
		{
			if (stack_a_copy[i] > stack_a_copy[j])
			{
				temp = stack_a_copy[i];
				stack_a_copy[i] = stack_a_copy[j];
				stack_a_copy[j] = temp;
			}
			j++;
		}
		i++;
	}	
}

void	find_pivot(t_stack *s, int p_cnt)
{
	int		*a_copy;
	int		i;

	a_copy = stackdup(s->a, s->element_cnt);
	sort(a_copy, s->element_cnt);
	s->pivot_ary = (int *)malloc(p_cnt * sizeof(int));
	i = 0;
	while (i < p_cnt)
	{
		s->pivot_ary[i] = a_copy[((s->element_cnt / (p_cnt + 1))) * (i + 1)];
		i++;
	}
	free(a_copy);
}
