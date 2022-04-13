/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:21:49 by nloutfi           #+#    #+#             */
/*   Updated: 2022/04/07 19:46:40 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	// if (str[i] == '\0' || c == '\0')
	// 	return (-1);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
char	*ft_strdup(const char *src)
{
	int		i;
	size_t	len;
	char	*copy;

	i = 0;
	len = ft_strlen(src);
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// if (!s1 || !s2)
	// 	return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i++] = s2[j++];
	}
	res[i] = '\0';
	return (res);
	
}

// char	*ft_substr(const char *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	i = start;
// 	j = 0;
// 	if (!s)
// 		return (0);
// 	else if (ft_strlen(s) <= start + len)
// 		str = ft_strdup(*(s + start));
// 	else
// 		str = malloc(sizeof(char) * (len));
// 	if (!str)
// 		return (0);
// 	if (start < ft_strlen(s))
// 	{
// 		while (s[i] && j < len)
// 			str[j++] = s[i++];
// 	}
// 	str[j] = '\0';
// 	return (str);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start || len == 0)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if (j < len && i >= start)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
