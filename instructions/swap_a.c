/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:53:03 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/19 13:53:05 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack *s, int flag)
{
	int	temp;

	if (s->i >= s->element_cnt - 1)
		return ;
	temp = s->a[s->i];
	s->a[s->i] = s->a[s->i + 1];
	s->a[s->i + 1] = temp;
	if (flag == 1)
	{
		s->instruction_cnt += 1;
		write(1, "sa\n", 3);
	}
}
