/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinaudo <jrinaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:01:14 by jrinaudo          #+#    #+#             */
/*   Updated: 2025/01/31 09:52:37 by jrinaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *dupli(char *str)
{
	int i = 0;
	char *cpy;

	if (!str)
		return (NULL);
	while (str[i])
		i++;
	cpy = malloc (i + 1);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE +1];
	static int	index_buff = 0;
	static int	nbchar = 0;
	char		line[1000000] = {'\0'};
	int			index_line = 0;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		if (index_buff >= nbchar)
		{
			index_buff = 0;
			nbchar = read (fd, buff, BUFFER_SIZE);
			if (nbchar <= 0)
				break;
		}
		line[index_line++] = buff[index_buff++];
		if (line[index_line - 1] == '\n')
			break;
	}
	if (index_line == 0)
		return (NULL);
	if (nbchar < 0)
		return (NULL);
	return (dupli(line));
}

/* #include <stdio.h>
int main(void)
{
	char *line;
	int fd = open("5", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	close(fd);
} */
/* 
line[index_line-1]
buff[index_buff-1]
 */