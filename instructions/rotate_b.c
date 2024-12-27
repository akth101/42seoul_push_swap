/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:06:13 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/20 16:06:14 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_b(t_stack *s, int flag)
{
	int		*temp_stack_b;
	int		temp_top_b;
	int		j;
	int		t;

	if (s->j >= s->element_cnt - 1)
		return ;
	temp_stack_b = ft_calloc_p(s->element_cnt - 1, sizeof(int));
	temp_top_b = s->b[s->j];
	t = 0;
	j = s->j + 1;
	while (j < s->element_cnt)
		temp_stack_b[t++] = s->b[j++];
	s->b[s->element_cnt - 1] = temp_top_b;
	j = s->j;
	t = 0;
	while (j < s->element_cnt - 1)
		s->b[j++] = temp_stack_b[t++];
	if (flag == 1)
	{
		s->instruction_cnt += 1;
		write(1, "rb\n", 3);
	}
	free(temp_stack_b);
}
