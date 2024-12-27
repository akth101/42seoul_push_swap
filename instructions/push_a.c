/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:50:43 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/19 18:50:45 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack *s)
{
	if (s->j == s->element_cnt)
		return ;
	s->i -= 1;
	s->a[s->i] = s->b[s->j];
	s->b[s->j] = 0;
	s->j += 1;
	s->instruction_cnt += 1;
	write(1, "pa\n", 3);
}
