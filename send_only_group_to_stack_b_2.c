/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_only_group_to_stack_b_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:32:00 by seongjko          #+#    #+#             */
/*   Updated: 2023/08/20 17:32:05 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_last(t_stack *s)
{
	int		i;
	int		flag;

	i = s->i;
	flag = 0;
	while (i < s->element_cnt)
	{
		if (s->pivot_ary[s->pivot_cnt - 1] < s->a[i])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		return (-1);
	return (i);
}

int	find_middle(t_stack *s, int g_cnt)
{
	int		i;
	int		flag;

	i = s->i;
	flag = 0;
	while (i < s->element_cnt)
	{
		if (s->pivot_ary[g_cnt - 1] < s->a[i] && s->a[i] < s->pivot_ary[g_cnt])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		return (-1);
	return (i);
}

int	find_first(t_stack *s)
{
	int		i;
	int		flag;

	i = s->i;
	flag = 0;
	while (i < s->element_cnt)
	{
		if (s->pivot_ary[0] > s->a[i])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		return (-1);
	return (i);
}

void	find_last_and_send_to_b(t_stack *s)
{
	int		last_group;
	int		last_i;

	while (1)
	{
		last_i = find_last(s);
		if (last_i == -1)
			break ;
		last_group = s->a[last_i];
		while (last_group != s->a[s->i])
		{	
			if (last_i <= s->i + (((s->element_cnt - 1) - s->i + 1) / 2))
				rotate_a(s, 1);
			else
				reverse_rotate_a(s, 1);
		}
		push_b(s);
	}
}

void	find_middle_and_send_to_b(t_stack *s)
{
	int	m_group;
	int	m_i;
	int	g_cnt;

	g_cnt = s->pivot_cnt - 1;
	while (g_cnt != 0)
	{
		while (find_middle(s, g_cnt) != -1)
		{
			m_i = find_middle(s, g_cnt);
			m_group = s->a[m_i];
			while (m_group != s->a[s->i])
			{	
				if (m_i <= s->i + (((s->element_cnt - 1) - s->i + 1) / 2))
					rotate_a(s, 1);
				else
					reverse_rotate_a(s, 1);
			}
			push_b(s);
		}
		g_cnt--;
	}
}
