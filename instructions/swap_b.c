/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:26:11 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/19 14:26:14 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_b(t_stack *s, int flag)
{
	int	temp;

	if (s->j >= s->element_cnt - 1)
		return ;
	temp = s->b[s->j];
	s->b[s->j] = s->b[s->j + 1];
	s->b[s->j + 1] = temp;
	if (flag == 1)
	{
		s->instruction_cnt += 1;
		write(1, "sb\n", 3);
	}
}
