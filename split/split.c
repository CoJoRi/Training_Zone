/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinaudo <jrinaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:17:29 by jrinaudo          #+#    #+#             */
/*   Updated: 2024/12/15 19:45:02 by jrinaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

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
		*str++ = 0;
		n--;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*allocmem;

	if (n == 0 || size == 0)
		return (malloc(0));
	if ((n * size) > (size_t) - 1)
		return (NULL);
	allocmem = (void *)malloc(n * size);
	if (!allocmem)
		return (NULL);
	ft_bzero(allocmem, n * size);
	return (allocmem);
}

static int	countw(const char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != charset) && (i == 0 || (str[i - 1] == charset)))
			count++;
		i++;
	}
	return (count);
}

static char	*dupst(const char *src, char charset)
{
	int		i;
	int		j;
	char	*target;

	i = 0;
	j = 0;
	while ((src[i] != charset) && src[i])
		i++;
	target = ft_calloc((i + 1), sizeof(char));
	if (!target)
		return (NULL);
	while (j < i)
	{
		target[j] = src[j];
		j++;
	}
	target[j] = '\0';
	return (target);
}

void	freemem(char **str, int j)
{
	while (j >= 0)
		free(str[j--]);
	free(str);
}

char	**ft_split(const char *str, char charset)
{
	size_t	i;
	size_t	j;
	char	**splitted;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	splitted = ft_calloc((countw((char *)str, charset) + 1), sizeof(char *));
	if (!splitted)
		return (NULL);
	splitted[countw((char *)str, charset)] = 0;
	while (i < ft_strlen(str))
	{
		while (str[i] == charset)
			i++;
		if (str[i] && (str[i] != charset))
		{
			splitted[j] = dupst(&str[i], charset);
			if (!splitted[j])
				return (freemem(splitted, j), NULL);
			i += ft_strlen(splitted[j++]);
		}
	}
	return (splitted);
}

/*-------------------------------------------------------------------*\
|                        Argv 1 -> Chain to split                     |
|                             Argv 2 -> Sep                           |
\*-------------------------------------------------------------------*/
void	putst(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**split;
	int	i;

	split = ft_split(argv[1], argv[2][0]);
	i = 0;
	while (split[i])
	{
		printf("chaine Nb%d : [%s]\n",i + 1, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (argc);
}
