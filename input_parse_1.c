/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:49:56 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/23 17:49:57 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*first_ary(char **ary)
{
	char	*ans;
	char	*temp;
	int		i;
	int		cnt_ary;

	i = 0;
	ans = ft_strdup("");
	cnt_ary = cnt_second_ary(ary);
	while (ary[i])
	{
		temp = ans;
		ans = ft_strjoin(ans, ary[i]);
		free(temp);
		temp = ans;
		ans = ft_strjoin(ans, " ");
		free(temp);
		i++;
	}
	return (ans);
}

char	*make_ary(int argc, char **argv)
{
	char	**ary;
	char	*temp_ary;
	char	*ans;
	char	*temp_ans;
	int		i;

	i = 1;
	ans = ft_strdup("");
	while (i < argc)
	{
		ary = ft_split(argv[i], ' ');
		temp_ary = first_ary(ary);
		double_freedom(ary);
		temp_ans = ans;
		ans = ft_strjoin(ans, temp_ary);
		free(temp_ans);
		free(temp_ary);
		i++;
	}
	return (ans);
}

void	put_in_a(char **ary, t_stack *s)
{
	int	i;

	i = 0;
	s->a = (int *)malloc(cnt_second_ary(ary) * sizeof(int));
	s->element_cnt = cnt_second_ary(ary);
	while (ary[i])
	{
		s->a[i] = ft_atoi_p(ary[i]);
		i++;
	}
}

int	check_space(char *ary)
{
	while (*ary)
	{
		if (*ary != ' ')
			return (0);
	}
	return (1);
}

int	check_valid(int argc, char **argv, t_stack *s)
{
	char	*first_ary;
	char	**second_ary;

	first_ary = make_ary(argc, argv);
	if (ft_strcmp_p(first_ary, "") || check_space(first_ary))
	{
		free(first_ary);
		return (FAILURE);
	}
	second_ary = ft_split(first_ary, ' ');
	if (is_number(second_ary) == FAILURE
		|| is_dup(second_ary) == FAILURE)
	{
		double_freedom(second_ary);
		free(first_ary);
		return (FAILURE);
	}
	put_in_a(second_ary, s);
	double_freedom(second_ary);
	free(first_ary);
	return (SUCCESS);
}
