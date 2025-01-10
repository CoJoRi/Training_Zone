/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_1file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinaudo <jrinaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:49:23 by jrinaudo          #+#    #+#             */
/*   Updated: 2024/12/15 16:06:15 by jrinaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>

int		strsearch(const char *str, char c);
size_t	ft_strlen(const char *s);
char	*strnjoin(char const *s1, char const *s2, int n);
void	*ft_calloc(size_t n, size_t size);
void	ft_bzero(void *s, size_t n);
int		readfd(char **buffline, int fd);
char	*readbuff(char **buff, char *line);
char	*get_next_line(int fd);

int	strsearch(const char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n)
	{
		*str++ = '\0';
		n--;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*allocmem;
	size_t	len;

	if (n != 0 && (n * size) / n != size)
		return (NULL);
	len = n * size;
	allocmem = malloc (len);
	if (!allocmem)
		return (NULL);
	ft_bzero(allocmem, len);
	return (allocmem);
}

char	*strnjoin(char const *s1, char const *s2, int n)
{
	size_t	len;
	char	*joined;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + n;
	joined = ft_calloc((len + 1), sizeof(char));
	if (!joined)
		return (NULL);
	result = joined;
	while (*s1)
		*joined++ = *s1++;
	while (n-- > 0 && *s2)
		*joined++ = *s2++;
	*joined = '\0';
	return (result);
}
char	*readbuff(char **buff, char *line)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = strsearch(*buff, '\n');
	if (i >= 0)
	{
		line = strnjoin("", *buff, i + 1);
		if (!line)
			return (free(*buff), *buff = NULL, free(line), NULL);
		temp = strnjoin(&(*buff)[i + 1], "", 0);
		if (!temp)
			return (free(*buff), *buff = NULL, free(temp), NULL);
		free(*buff);
		*buff = temp;
	}
	else
	{
		line = strnjoin(*buff, "", 0);
		free(*buff);
		*buff = NULL;
		if (!line)
			return (free(line), NULL);
	}
	return (line);
}

int	readfd(char **buff, int fd)
{
	char	*temp;
	char	*temp2;
	int		nbchar;

	temp = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!temp)
		return (free(temp), temp = NULL, -1);
	temp2 = NULL;
	nbchar = read(fd, temp, BUFFER_SIZE);
	while (nbchar > 0)
	{
		temp2 = strnjoin(*buff, temp, nbchar);
		free(*buff);
		*buff = temp2;
		if (strsearch(*buff, '\n') >= 0)
			return (free(temp), temp = NULL, nbchar);
		nbchar = read(fd, temp, BUFFER_SIZE);
	}
	return (free(temp), temp = NULL, nbchar);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;
	int			nbchar;

	if (!buff)
		buff = ft_calloc(1, 1);
	if (fd < -1 || BUFFER_SIZE <= 0 || !buff)
		return (free(buff), buff = NULL, NULL);
	line = NULL;
	nbchar = readfd(&buff, fd);
	if (nbchar < 0 || (nbchar == 0 && *buff == 0))
		return (free(buff), buff = NULL, NULL);
	line = readbuff(&buff, line);
	if (!line)
		return (NULL);
	return (line);
}

int main(void)
{
	int fd = open("hp", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	char *line;
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}