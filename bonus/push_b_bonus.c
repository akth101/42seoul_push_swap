/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:16:16 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/20 12:16:17 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b_bonus(t_stack *s)
{
	if (s->i == s->element_cnt)
		return ;
	s->j -= 1;
	s->b[s->j] = s->a[s->i];
	s->a[s->i] = 0;
	s->i += 1;
}
