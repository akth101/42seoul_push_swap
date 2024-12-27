/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:07:43 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/20 15:07:44 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a_bonus(t_stack *s)
{
	int	*temp_stack_a;
	int	temp_top_a;
	int	i;
	int	t;

	if (s->i >= s->element_cnt - 1)
		return ;
	temp_stack_a = ft_calloc_p(s->element_cnt - 1, sizeof(int));
	temp_top_a = s->a[s->i];
	t = 0;
	i = s->i + 1;
	while (i < s->element_cnt)
		temp_stack_a[t++] = s->a[i++];
	s->a[s->element_cnt - 1] = temp_top_a;
	i = s->i;
	t = 0;
	while (i < s->element_cnt - 1)
		s->a[i++] = temp_stack_a[t++];
	free(temp_stack_a);
}
