/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:18:44 by nloutfi           #+#    #+#             */
/*   Updated: 2022/04/10 00:00:14 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <strings.h>

void	ft_extraction(char **line, char **stock)
{
	int		i;
	char	*temp;

	i = ft_strchr(*stock, '\n') + 1;
	*line = ft_join_n(0, *stock, i);
	temp = *stock;
	*stock = ft_join_n(0, &temp[i], ft_strlen(&temp[i]));
	ft_free(temp);
}

char	*read_fail(char **stock, char **buff, char **line)
{
	if (*stock && (*stock)[0] == '\0')
	{
		ft_free(*buff);
		ft_free(*stock);
		return (0);
	}
	ft_free(*buff);
	*line = ft_join_n(*stock, 0, 0);
	*stock = NULL;
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*stock;
	int			rd;
	char		*line;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (ft_strchr(stock, '\n') == -1)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 1)
			return (read_fail(&stock, &buff, &line));
		buff[rd] = '\0';
		stock = ft_join_n(stock, buff, rd);
	}
	ft_free(buff);
	ft_extraction(&line, &stock);
	return (line);
}

// int main()
// {
// 	int fd;
// 	int i = 0;

// 	fd = 1;
// 	char *s ;
// 	while (fd < 2) 
// 	{
// 		s = get_next_line(fd);
// 		printf("--------\n");
// 		printf("%s\n", s);
// 		printf("---------\n");
// 		ft_free(s);
// 		i++;
// 	}
// 	//system("leaks a.out");
// }
