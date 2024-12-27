/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:12:25 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/20 16:12:26 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a_bonus(t_stack *s)
{
	int	*temp_stack_a;
	int	temp_bottom_a;
	int	i;
	int	t;

	if (s->i >= s->element_cnt - 1)
		return ;
	temp_stack_a = ft_calloc_p(s->element_cnt - 1, sizeof(int));
	temp_bottom_a = s->a[s->element_cnt - 1];
	i = s->i;
	t = 0;
	while (i < s->element_cnt - 1)
		temp_stack_a[t++] = s->a[i++];
	s->a[s->i] = temp_bottom_a;
	i = s->i + 1;
	t = 0;
	while (i < s->element_cnt)
		s->a[i++] = temp_stack_a[t++];
	free(temp_stack_a);
}
