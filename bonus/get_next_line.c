/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:41:14 by seongjko          #+#    #+#             */
/*   Updated: 2023/05/12 19:41:15 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strrest(char *buff, int new_pos)
{
	char	*res;
	int		len;
	int		i;

	buff += new_pos;
	len = ft_strlen_g(buff);
	res = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len)
		res[i] = buff[i];
	res[i] = '\0';
	return (res);
}

char	*cut(char **rest, int new_pos, int i)
{
	char	*ans;
	char	*temp;

	if (new_pos != -1)
	{
		ans = ft_strndup_g(*rest, new_pos + 1);
		temp = *rest;
		*rest = ft_strrest(*rest, new_pos + 1);
		free(temp);
	}
	else
	{
		if (i == 0 && **rest == (char) NULL)
		{
			free(*rest);
			*rest = NULL;
			return (NULL);
		}
		ans = ft_strndup_g(*rest, ft_strlen_g(*rest));
		temp = *rest;
		*rest = ft_strndup_g("", 0);
		free(temp);
	}
	return (ans);
}

char	*line(char **rest, int fd)
{
	char		*ans;
	char		buff[4];
	char		*temp;
	int			i;

	while (1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			free(*rest);
			*rest = NULL;
			return (NULL);
		}
		buff[i] = '\0';
		temp = *rest;
		*rest = ft_strjoin_g(*rest, buff);
		free(temp);
		if (ft_strchr_g(*rest, '\n') != -1 || i < BUFFER_SIZE)
		{
			ans = cut(rest, ft_strchr_g(*rest, '\n'), i);
			break ;
		}
	}
	return (ans);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*ans;

	if (!rest)
		rest = ft_strndup_g("", 0);
	ans = line(&rest, fd);
	return (ans);
}
