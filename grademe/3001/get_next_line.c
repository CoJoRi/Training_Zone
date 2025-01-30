/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinaudo <jrinaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:15:27 by jrinaudo          #+#    #+#             */
/*   Updated: 2025/01/30 18:14:51 by jrinaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <fcntl.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <stdlib.h>

char *my_strcpy(char *str)
{
	int i=0;
	char *cpy = NULL;
	while (str[i])
		i++;
	cpy = malloc(i);
	if (!cpy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char    *get_next_line(int  fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		line[100000] = {0};
	int			index_line = 0;
	static int	index_buff = 0;
	static int	nbchar = 0;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	while (1)
	{
		if (index_buff >= nbchar)
		{
			nbchar = read(fd, buff, BUFFER_SIZE);
			if (nbchar < 0)
				return (NULL);
			index_buff = 0;
		}
		line[index_line] = buff[index_buff];
		if (line[index_line] == '\n' || line[index_line] == '\0')
			return (index_buff++, my_strcpy(line));
		index_buff++;
		index_line++;
		}
		return (my_strcpy(line));	
	}

#include <stdio.h>
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line = line = get_next_line(fd);

	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}