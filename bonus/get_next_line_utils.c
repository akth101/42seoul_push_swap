/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:25:50 by seongjko          #+#    #+#             */
/*   Updated: 2023/05/14 18:25:51 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strchr_g(const char *s, int c)
{
	int	cnt;

	cnt = 0;
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (-1);
		cnt++;
		s++;
	}
	return (cnt);
}

char	*ft_strndup_g(char *str, int len)
{
	int			i;
	char		*p;

	i = 0;
	p = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
		p[i++] = *str++;
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin_g(char *dest, char *append)
{
	char	*p;
	int		cnt1;
	int		cnt2;
	int		i;

	i = 0;
	cnt1 = ft_strlen_g(dest);
	cnt2 = ft_strlen_g(append);
	p = (char *)malloc(cnt1 + cnt2 + 1);
	while (*dest)
		p[i++] = *dest++;
	while (*append)
		p[i++] = *append++;
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen_g(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}
