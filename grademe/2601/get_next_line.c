/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeph <zeph@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:58:39 by zeph              #+#    #+#             */
/*   Updated: 2025/01/27 08:03:03 by zeph             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* void raz_buff(char *buff)
{
	int	i = 0;

	while (i < 10000000)
	{
		buff[i] = '\0';
		i++;
	}
} */

char	*get_next_line(int fd)
{
	char	*buff = malloc(10000000);
	char	c;
	int		readed;
	int		nbchar;

	if (BUFFER_SIZE < 1)
		return (free(buff), buff = NULL, NULL);
	nbchar = read(fd, &c, 1);
	if (nbchar <= 0)
		return (free(buff), buff = NULL, NULL);
	readed = 0;
	while (nbchar > 0)
	{
		buff[readed] = c;
		readed++;
		if (c == '\n')
			break;
		nbchar = read(fd, &c, 1);
		if (nbchar <= 0)
			return (free(buff), buff = NULL, NULL);
	}
	buff[readed] = '\0';
	return (buff);
}

#include <stdio.h>
int	main(void)
{
	char	*file = "test.txt";
	int		fd = open(file, O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("line :%s",line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (0);
}