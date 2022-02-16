/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 06:28:04 by nloutfi           #+#    #+#             */
/*   Updated: 2022/01/06 06:33:51 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (str);
}

void	ft_extraction(char **line, char **stock, char **temp)
{
	*line = ft_substr(*stock, 0, ft_strchr(stock, '\n' + 1));
	*temp = *stock;
	*stock = ft_substr(*stock, ft_strchr(stock, '\n'), ft_strlen(stock));
	ft_free(*temp);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stock[1024];
	char		*temp;
	int			rd;
	char		*line;

	while (ft_strchr(stock[fd], '\n') == -1)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1 || rd == 0)
		{
			if (stock[fd] && stock[fd][0] == '\0')
				return (ft_free(stock[fd]));
			temp = stock[fd];
			stock[fd] = NULL;
			return (temp);
		}
		buff[BUFFER_SIZE] = '\0';
		temp = stock[fd];
		stock[fd] = ft_strjoin(stock[fd], buff);
	}
	ft_free(buff);
	ft_extraction(line, stock[fd], temp);
	return (line);
}
