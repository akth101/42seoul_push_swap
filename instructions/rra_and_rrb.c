/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_and_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:25:59 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/20 16:26:01 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_and_rrb(t_stack *s)
{
	reverse_rotate_a(s, 0);
	reverse_rotate_b(s, 0);
	s->instruction_cnt += 1;
	write(1, "rrr\n", 4);
}
