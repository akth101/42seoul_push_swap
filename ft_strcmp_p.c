/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:50:08 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/19 13:50:09 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp_p(char *s1, char *s2)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (1)
	{
		if (*temp1 == '\0' && *temp2 == '\0')
			return (1);
		if (*temp1 != *temp2)
			return (0);
		temp1++;
		temp2++;
	}
	return (1);
}
