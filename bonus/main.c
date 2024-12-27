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

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	s;

	if (check_valid(argc, argv, &s) == FAILURE)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	s.b = ft_calloc_p(s.element_cnt, sizeof(int));
	s.i = 0;
	s.j = s.element_cnt;
	if (!(read_instruction(&s)))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!(is_it_sorted(&s)))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(s.a);
	free(s.b);
	return (0);
}
