/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:16:06 by seongjko          #+#    #+#             */
/*   Updated: 2023/07/23 19:16:07 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc_p(size_t count, size_t size)
{
	void	*p;
	size_t	n;

	n = count * size;
	p = malloc(n);
	if (p == (void *)0)
		return (0);
	return (p);
}
