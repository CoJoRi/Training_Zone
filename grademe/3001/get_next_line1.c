/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinaudo <jrinaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:15:27 by jrinaudo          #+#    #+#             */
/*   Updated: 2025/01/30 20:28:29 by jrinaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <unistd.h>
#include <fcntl.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <stdlib.h>

char *my_strcpy(char *str)
{
	int i = 0;
	char *cpy = NULL;

	while (str[i])
		i++;
	cpy = malloc(i + 1);
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
			index_buff = 0;
			if (nbchar <= 0)
				break;
		}
		line[index_line++] = buff[index_buff++];
		if (line[index_line - 1] == '\n' || line[index_line -1] == '\0')
			break ;
	}
		if (index_line == 0)
			return (0);
		return (my_strcpy(line));	
	}

/* #include <stdio.h>
int main(void)
{
	int fd = open("2", O_RDONLY);
	char *line = get_next_line(fd);

	while (line)
	{
		if (line)
		{
			printf("%s", line);
			free(line);			
		}
		line = get_next_line(fd);
	}
	return (0);
} */