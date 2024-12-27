/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:17:44 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/19 16:17:45 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	letsgo_atoi(const char *str)
{
	long long	num;

	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num);
}

long long	ft_atoi_p(const char *str)
{
	long long	ans;
	int			sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	ans = letsgo_atoi(str);
	return (ans * sign);
}
