/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:21:24 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/22 20:21:25 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_coding(t_stack *s)
{
	if (s->element_cnt == 2)
		element_two(s);
	if (s->element_cnt == 3)
		element_three(s);
	if (s->element_cnt == 4)
		element_four(s);
	if (s->element_cnt == 5)
		element_five(s);
}
