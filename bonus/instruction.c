/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:23:10 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/10 16:23:11 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	read_instruction(t_stack *s)
{
	char	*ins;

	while (1)
	{
		ins = get_next_line(0);
		if (ins == (void *)0)
			break ;
		if (check_instruction(ins) == 0)
			return (0);
		execute_instruction(ins, s);
		free(ins);
	}
	return (1);
}

void	execute_instruction(char *ins, t_stack *s)
{
	if (ft_strcmp_p(ins, "sa\n"))
		swap_a_bonus(s);
	if (ft_strcmp_p(ins, "sb\n"))
		swap_b_bonus(s);
	if (ft_strcmp_p(ins, "ss\n"))
		sa_and_sb_bonus(s);
	if (ft_strcmp_p(ins, "pa\n"))
		push_a_bonus(s);
	if (ft_strcmp_p(ins, "pb\n"))
		push_b_bonus(s);
	if (ft_strcmp_p(ins, "ra\n"))
		rotate_a_bonus(s);
	if (ft_strcmp_p(ins, "rb\n"))
		rotate_b_bonus(s);
	if (ft_strcmp_p(ins, "rr\n"))
		ra_and_rb_bonus(s);
	if (ft_strcmp_p(ins, "rra\n"))
		reverse_rotate_a_bonus(s);
	if (ft_strcmp_p(ins, "rrb\n"))
		reverse_rotate_b_bonus(s);
	if (ft_strcmp_p(ins, "rrr\n"))
		rra_and_rrb_bonus(s);
}

int	check_instruction(char	*ins)
{
	if (ft_strcmp_p(ins, "sa\n") == 0 && ft_strcmp_p(ins, "sb\n") == 0 \
		&& ft_strcmp_p(ins, "ss\n") == 0 && ft_strcmp_p(ins, "pa\n") == 0 \
		&& ft_strcmp_p(ins, "pb\n") == 0 && ft_strcmp_p(ins, "ra\n") == 0 \
		&& ft_strcmp_p(ins, "rb\n") == 0 && ft_strcmp_p(ins, "rr\n") == 0 \
		&& ft_strcmp_p(ins, "rra\n") == 0 && ft_strcmp_p(ins, "rrb\n") == 0 \
		&& ft_strcmp_p(ins, "rrr\n") == 0)
		return (0);
	return (1);
}

int	is_it_sorted(t_stack *s)
{
	int	i;
	int	j;

	if (s->i == s->element_cnt || s->j != s->element_cnt)
		return (FAILURE);
	i = 0;
	while (i < s->element_cnt)
	{
		j = i + 1;
		while (j < s->element_cnt)
		{
			if (s->a[i] > s->a[j])
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
