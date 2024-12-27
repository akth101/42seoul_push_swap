/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:24:34 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/20 16:24:35 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_b_bonus(t_stack *s)
{
	int		*temp_stack_b;
	int		temp_bottom_b;
	int		j;
	int		t;

	if (s->j >= s->element_cnt - 1)
		return ;
	temp_stack_b = ft_calloc_p(s->element_cnt - 1, sizeof(int));
	temp_bottom_b = s->b[s->element_cnt - 1];
	j = s->j;
	t = 0;
	while (j < s->element_cnt - 1)
		temp_stack_b[t++] = s->b[j++];
	s->b[s->j] = temp_bottom_b;
	j = s->j + 1;
	t = 0;
	while (j < s->element_cnt)
		s->b[j++] = temp_stack_b[t++];
	free(temp_stack_b);
}
