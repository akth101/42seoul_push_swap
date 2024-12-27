/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:23:17 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/23 20:23:18 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char **ary)
{
	int	i;
	int	j;

	i = -1;
	while (ary[++i])
	{
		j = -1;
		while (ary[i][++j])
		{
			if (!(ft_isdigit(ary[i][j])))
			{
				if (!(j == 0 && (ary[i][j] == '-' || ary[i][j] == '+')))
					return (1);
				if ((j == 0 && (ary[i][j] == '-' || ary[i][j] == '+'))
					&& !(ft_isdigit(ary[i][j + 1])))
					return (1);
			}
		}
	}
	return (0);
}

int	is_dup(char **ary)
{
	int	i;
	int	j;

	i = 0;
	while (ary[i])
	{
		j = i + 1;
		if (ft_atoi_p(ary[i]) < INT_MIN || ft_atoi_p(ary[i]) > INT_MAX)
			return (1);
		while (ary[j])
		{
			if (ft_atoi_p(ary[j]) < INT_MIN || ft_atoi_p(ary[j]) > INT_MAX)
				return (1);
			if (ft_atoi_p(ary[i]) == ft_atoi_p(ary[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	double_freedom(char **ary)
{
	int	i;

	i = 0;
	while (ary[i])
	{
		free(ary[i]);
		ary[i] = NULL;
		i++;
	}
	free(ary);
	ary = NULL;
}

int	cnt_second_ary(char **ary)
{
	int	i;

	i = 0;
	while (ary[i])
		i++;
	return (i);
}

int	check_stack_a_sorted(t_stack *s)
{
	int	i;
	int	j;

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
