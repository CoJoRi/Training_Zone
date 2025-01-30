/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinaudo <jrinaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 07:29:40 by zeph              #+#    #+#             */
/*   Updated: 2025/01/30 15:18:00 by jrinaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd)
{
	char	*buff = malloc(10000000);
	char	c;
	int		nbchar;
	int		readed;

	if (!buff || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nbchar = 1;
	readed = 0;
	while (nbchar)
	{
		nbchar = read(fd, &c, 1);
		if (nbchar <= 0)
			return (free(buff), buff = NULL, NULL);	
		buff[readed] = c;
		readed++;
		if (c == '\n')
			break;
	}
	buff[readed] = '\0';
	return (buff);
}

#include <stdio.h>
int main(void)
{
	char *line;
	int fd = open("test.txt", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	close(fd);
}