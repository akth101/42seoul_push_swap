/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:52:41 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/22 20:52:43 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	third_first_second(t_stack *s)
{
	rotate_a(s, 1);
}

void	third_second_first(t_stack *s)
{
	swap_a(s, 1);
	reverse_rotate_a(s, 1);
}

void	element_three(t_stack *s)
{
	if ((s->a[s->i] < s->a[s->i + 1] && s->a[s->i] < s->a[s->i + 2])
		&& (s->a[s->i + 1] > s->a[s->i] && s->a[s->i + 1] > s->a[s->i + 2])
		&& (s->a[s->i + 2] < s->a[s->i + 1] && s->a[s->i + 2] > s->a[s->i]))
		first_third_second(s);
	if ((s->a[s->i] > s->a[s->i + 1] && s->a[s->i] < s->a[s->i + 2])
		&& (s->a[s->i + 1] < s->a[s->i] && s->a[s->i + 1] < s->a[s->i +2])
		&& (s->a[s->i + 2] > s->a[s->i] && s->a[s->i + 2] > s->a[s->i + 1]))
		second_first_third(s);
	if ((s->a[s->i] < s->a[s->i + 1] && s->a[s->i] > s->a[s->i + 2])
		&& (s->a[s->i + 1] > s->a[s->i] && s->a[s->i + 1] > s->a[s->i + 2])
		&& (s->a[s->i + 2] < s->a[s->i] && s->a[s->i + 2] < s->a[s->i +1]))
		second_third_first(s);
	if ((s->a[s->i] > s->a[s->i + 1] && s->a[s->i] > s->a[s->i + 2])
		&& (s->a[s->i + 1] < s->a[s->i] && s->a[s->i + 1] < s->a[s->i + 2])
		&& (s->a[s->i + 2] < s->a[s->i] && s->a[s->i + 2] > s->a[s->i + 1]))
		third_first_second(s);
	if (s->a[s->i] > s->a[s->i + 1] && s->a[s->i + 1] > s->a[s->i + 2])
		third_second_first(s);
}
