/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_three_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:09:23 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/22 22:09:26 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_third_second(t_stack *s)
{
	push_b(s);
	swap_a(s, 1);
	push_a(s);
}

void	second_first_third(t_stack *s)
{
	swap_a(s, 1);
}

void	second_third_first(t_stack *s)
{
	reverse_rotate_a(s, 1);
}
