/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:18:44 by nloutfi           #+#    #+#             */
/*   Updated: 2022/02/16 15:41:36 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (str);
}

void	ft_extraction(char **line, char **stock, char **temp)
{
	*line = ft_substr(*stock, 0, ft_strchr(*stock, '\n') + 1);
	*temp = *stock;
	*stock = ft_substr(*stock, ft_strchr(*stock, '\n') + 1, ft_strlen(*stock));
	ft_free(*temp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*stock;
	char		*temp;
	int			rd;
	char		*line;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (ft_strchr(stock, '\n') == -1)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1 || rd == 0)
		{
			if (stock && stock[0] == '\0')
				return (ft_free(stock));
			temp = stock;
			stock = NULL;
			return (temp);
		}
		buff[rd] = '\0';
		temp = stock;
		stock = ft_strjoin(stock, buff);
		ft_free(temp);
	}
	ft_free(buff);
	ft_extraction(&line, &stock, &temp);
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *s;
// 	int i = 0;
	
// 	fd = open("najlio.txt", O_RDONLY);
// 	//s = get_next_line(fd);
// 	while ( i < 8)
// 	{
// 		printf("%s", get_next_line(fd));
// 		i++;
// 	}
// 	system("leaks a.out");
// }
