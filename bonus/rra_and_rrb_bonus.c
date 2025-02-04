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

void	rra_and_rrb_bonus(t_stack *s)
{
	reverse_rotate_a_bonus(s);
	reverse_rotate_b_bonus(s);
}
