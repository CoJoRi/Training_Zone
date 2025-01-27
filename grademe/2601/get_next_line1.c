/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeph <zeph@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:19:14 by zeph              #+#    #+#             */
/*   Updated: 2025/01/26 21:49:13 by zeph             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

void	raz_buff(char *buff)
{
	int	i = 0;

	while (i < 10000000)
	{
		buff[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	c;
	int		nbchar;
	int		readed;

	if (BUFFER_SIZE <= 0)
	 	return (NULL);
	buff = malloc(sizeof(char) * 10000000);
	if (!buff)
		return (NULL);
	raz_buff(buff);
	nbchar = read(fd, &c, 1);
	if (nbchar <= 0)
		return (free(buff), buff = NULL, NULL);
	readed = 0;
	while (nbchar > 0)
	{
		buff[readed] = c;
		readed++;
		if (c == '\n' || c == '\0')
			break;
		nbchar = read(fd, &c, 1);
		if (nbchar < 0)
			return (free(buff), buff = NULL);
	}
	return (buff);
}

/* #include <stdio.h>
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
} */