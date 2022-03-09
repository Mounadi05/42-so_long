/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:13:39 by amounadi          #+#    #+#             */
/*   Updated: 2022/03/02 03:41:12 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int		n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_print_error(int ac)
{
	write(2, "Error\n", 6);
	if (ac == 0)
		write(2, "invalid extension\n", ft_strlen("invalid extension\n"));
	else if (ac > 2)
		write(2, "too many arguments\n", ft_strlen("too many arguments\n"));
	else
		write(2, "you should enter two arguments\n",
			ft_strlen("you should enter two arguments\n"));
	exit(0);
}

int	ft_check_arg(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 4 && str[len - 1] == 'r' && str[len - 2] == 'e'
		&& str[len - 3] == 'b' && str[len - 4] == '.')
		return (1);
	return (0);
}

void	ft_assign(t_var *var)
{
	var->n = 0;
	var->x = 0;
	var->y = 0;
	var->o = 0;
	var->i = 0;
	var->c = 0;
	var->d = 0;
}
