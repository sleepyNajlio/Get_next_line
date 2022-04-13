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

void	ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
}

void	ft_extraction(char **line, char **stock)
{
	int i;
	char *temp;

	i = ft_strchr(*stock, '\n') + 1;
	*line = ft_substr(*stock, 0, i);
	temp = *stock;
	*stock = ft_strdup(&(*stock)[i]);
	ft_free(temp);
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
		// if (rd == -1 || rd == 0)
		// {
		// 	if (stock && stock[0] == '\0')
		// 		return (ft_free(stock));
		// 	temp = stock;
		// 	stock = NULL;
		// 	return (temp);
		// }
		if (rd == -1)
		{
			ft_free(stock);
			ft_free(buff);
			return (NULL);
		}
		if (rd == 0)
		{
			if (stock && stock[0] == '\0')
				ft_free(stock);
			temp = stock;
			stock = NULL;
			ft_free(buff);
			return (temp);
		}
		
		buff[rd] = '\0';
		temp = stock;
		stock = ft_strjoin(stock, buff);
		ft_free(temp);
	}
	ft_free(buff);
	ft_extraction(&line, &stock);
	return (line);
}

int main()
{
	int fd;
	int i = 0;
	
	fd = open("najlio.txt", O_RDONLY);
	//s = get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	//system("leaks a.out");
	check_leaks();
}
