/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:42:30 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/10 15:42:31 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack_b(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->element_cnt)
	{
		s->b[i] = 0;
		i++;
	}
}

void	initialize_struct(t_stack *s)
{
	s->b = ft_calloc_p(s->element_cnt, sizeof(int));
	initialize_stack_b(s);
	s->i = 0;
	s->j = s->element_cnt;
	s->instruction_cnt = 0;
	s->pivot_cnt = 2;
	s->min_cost_a = 2147483647;
	s->min_cost_b = 2147483647;
}

void	freedom(t_stack *s)
{
	free(s->a);
	free(s->b);
	free(s->pivot_ary);
}

void	start_sorting(t_stack *s)
{
	find_pivot(s, s->pivot_cnt);
	send_groups_to_stack_b(s);
	send_max_to_stack_a(s);
	sort_groups(s);
	freedom(s);
}

int	main(int argc, char *argv[])
{
	t_stack	s;

	if (check_valid(argc, argv, &s) == FAILURE)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (check_stack_a_sorted(&s) == SUCCESS)
	{
		free(s.a);
		return (0);
	}
	initialize_struct(&s);
	if (s.element_cnt < 6)
	{
		hard_coding(&s);
		freedom(&s);
		return (0);
	}
	else
		start_sorting(&s);
	return (0);
}
