/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:58:11 by amounadi          #+#    #+#             */
/*   Updated: 2022/03/02 03:40:54 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right(int key, t_var *var, int *c, int *steps)
{
	if ((key == 2 || key == 124) && var->str[var->pos_i][var->pos_j + 1] != '1'
		&& (var->str[var->pos_i][var->pos_j + 1] != 'E' || var->o == 1))
	{
		if (var->str[var->pos_i][var->pos_j + 1] == 'E')
		{
			write(1, "YOU WIN\n", 8);
			mlx_destroy_window(var->mlx_ptr, var->win_ptr);
			exit(0);
		}
		if (var->str[var->pos_i][var->pos_j + 1] == 'C')
			(*c)++;
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[0], var->pos_j * 40, var->pos_i * 40);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[0], (var->pos_j + 1) * 40, var->pos_i * 40);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[1], (var->pos_j + 1) * 40, var->pos_i * 40);
		var->str[var->pos_i][var->pos_j + 1] = var->str[var->pos_i][var->pos_j];
		var->str[var->pos_i][var->pos_j] = '0';
		var->pos_j++;
		(*steps)++;
		write(1, "steps : ", 8);
		ft_putnbr(*steps);
		write(1, "\n", 1);
	}
}

void	ft_left(int key, t_var *var, int *c, int *steps)
{
	if ((key == 0 || key == 123) && var->str[var->pos_i][var->pos_j - 1] != '1'
		&& (var->str[var->pos_i][var->pos_j - 1] != 'E' || var->o == 1))
	{
		if (var->str[var->pos_i][var->pos_j - 1] == 'E')
		{
			write(1, "YOU WIN\n", 8);
			mlx_destroy_window(var->mlx_ptr, var->win_ptr);
			exit(0);
		}
		if (var->str[var->pos_i][var->pos_j - 1] == 'C')
			(*c)++;
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[0], var->pos_j * 40, var->pos_i * 40);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[0], (var->pos_j - 1) * 40, var->pos_i * 40);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[1], (var->pos_j - 1) * 40, var->pos_i * 40);
		var->str[var->pos_i][var->pos_j - 1] = var->str[var->pos_i][var->pos_j];
		var->str[var->pos_i][var->pos_j] = '0';
		var->pos_j--;
		(*steps)++;
		write(1, "steps : ", 8);
		ft_putnbr(*steps);
		write(1, "\n", 1);
	}
}

void	ft_up(int key, t_var *var, int *c, int *steps)
{
	if ((key == 1 || key == 125) && var->str[var->pos_i + 1][var->pos_j] != '1'
		&& (var->str[var->pos_i + 1][var->pos_j] != 'E' || var->o == 1))
	{
		if (var->str[var->pos_i + 1][var->pos_j] == 'E')
		{
			write(1, "YOU WIN\n", 8);
			mlx_destroy_window(var->mlx_ptr, var->win_ptr);
			exit(0);
		}
		if (var->str[var->pos_i + 1][var->pos_j] == 'C')
			(*c)++;
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[0], var->pos_j * 40, var->pos_i * 40);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[0], (var->pos_j) * 40, (var->pos_i + 1) * 40);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[1], (var->pos_j) * 40, (var->pos_i + 1) * 40);
		var->str[var->pos_i + 1][var->pos_j] = var->str[var->pos_i][var->pos_j];
		var->str[var->pos_i][var->pos_j] = '0';
		var->pos_i++;
		(*steps)++;
		write(1, "steps : ", 8);
		ft_putnbr(*steps);
		write(1, "\n", 1);
	}
}

void	ft_down(int key, t_var *var, int *c, int *steps)
{
	if ((key == 13 || key == 126) && var->str[var->pos_i - 1][var->pos_j] != '1'
		&& (var->str[var->pos_i - 1][var->pos_j] != 'E' || var->o == 1))
	{
		if (var->str[var->pos_i - 1][var->pos_j] == 'E')
		{
			write(1, "YOU WIN\n", 8);
			mlx_destroy_window(var->mlx_ptr, var->win_ptr);
			exit(0);
		}
		if (var->str[var->pos_i - 1][var->pos_j] == 'C')
			(*c)++;
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[0], var->pos_j * 40, var->pos_i * 40);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[0], (var->pos_j) * 40, (var->pos_i - 1) * 40);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[1], (var->pos_j) * 40, (var->pos_i - 1) * 40);
		var->str[var->pos_i - 1][var->pos_j] = var->str[var->pos_i][var->pos_j];
		var->str[var->pos_i][var->pos_j] = '0';
		var->pos_i--;
		(*steps)++;
		write(1, "steps : ", 8);
		ft_putnbr(*steps);
		write(1, "\n", 1);
	}
}

int	ft_move(int key, t_var *var)
{
	static int	steps = 0;
	static int	c = 0;

	if (key == 53)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		exit(0);
	}
	ft_right(key, var, &c, &steps);
	ft_left(key, var, &c, &steps);
	ft_up(key, var, &c, &steps);
	ft_down(key, var, &c, &steps);
	if (c == var->c)
	{
		while (--var->d >= 0)
		{
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->img[0], var->e_j[var->d] * 40, var->e_i[var->d] * 40);
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->img[7], var->e_j[var->d] * 40, var->e_i[var->d] * 40);
		}
		var->o = 1;
	}
	return (0);
}
