/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinaudo <jrinaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:15:03 by zeph              #+#    #+#             */
/*   Updated: 2025/01/31 12:36:45 by jrinaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

//	char    hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void    puthex(unsigned int nb, ssize_t *len)
{
	char	c;
	char    hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	if (nb > 15)
		puthex(nb / 16, len);
	c = hex[nb % 16];
	*len += write(1, &c, 1);
}

void putnbr(int n, ssize_t *len)
{
	long    nb = n;
	char    c;

	if (nb < 0)
		*len += write (1, "-", 1);
	nb = (-(nb < 0) * nb) + ((nb > 0) * nb);
	if (nb >= 10)
		putnbr(nb / 10, len);
	c = (nb % 10) + '0';
	*len += write(1, &c, 1);
}

void putstr(char *str, ssize_t *len)
{
	int	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	*len += write(1, str, i);
}

int	is_form(char c)
{
	if (c == 'd' || c == 's' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return(0);
}

int ft_printf(const char *str, ... )
{
	ssize_t	len;
	va_list	args;
	int	i = 0;

	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && is_form(str[i + 1]))
		{
			i++;
			if (str[i] == 's')
				putstr(va_arg(args, char *), &len);
			else if (str[i] == 'd')
				putnbr(va_arg(args, int), &len);
			else if (str[i] == 'x' || str[i] == 'X')
				puthex(va_arg(args, unsigned int), &len);
			else
				len += write(1, &str[i], 1);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return ((int)len);
}
/* 
int	main (void)
{
	int n = -2147483648;
	char *str = NULL;
	int hex = 15;

	printf("\nnbchar: %d",printf("\ttest de printf %%:\n deci:%d\nhexa: %x\nstring:%s\n et voila!!! \n\n",n, hex, str));
	printf("\nnbchar: %d",ft_printf("\ttest de printf %%:\n deci:%d\nhexa: %x\nstring:%s\n et voila!!! \n\n",n, hex, str));
	printf("\nnbchar: %d",ft_printf("%d", n));
	return (0);

} */