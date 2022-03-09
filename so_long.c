/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 03:41:59 by amounadi          #+#    #+#             */
/*   Updated: 2022/03/02 03:42:02 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_assignment_img(t_var *var)
{
	var->path[0] = "img/grass.xpm";
	var->path[1] = "img/player.xpm";
	var->path[2] = "img/tree.xpm";
	var->path[3] = "img/berry.xpm";
	var->path[4] = "img/apple.xpm";
	var->path[5] = "img/melon.xpm";
	var->path[6] = "img/cherr.xpm";
	var->path[7] = "img/door.xpm";
	var->path[8] = "img/c_door.xpm";
}

void	ft_assignment(t_var *var, int x, int y)
{
	int	img_width;
	int	img_height;

	var->mlx_ptr = mlx_init();
	var->win_ptr = mlx_new_window(var->mlx_ptr, y * 40, x * 40, "so_long");
	ft_assignment_img(var);
	var->img[0] = mlx_xpm_file_to_image (var->mlx_ptr,
			var->path[0], &img_width, &img_height);
	var->img[1] = mlx_xpm_file_to_image (var->mlx_ptr,
			var->path[1], &img_width, &img_height);
	var->img[2] = mlx_xpm_file_to_image (var->mlx_ptr,
			var->path[2], &img_width, &img_height);
	var->img[3] = mlx_xpm_file_to_image (var->mlx_ptr,
			var->path[3], &img_width, &img_height);
	var->img[4] = mlx_xpm_file_to_image (var->mlx_ptr,
			var->path[4], &img_width, &img_height);
	var->img[5] = mlx_xpm_file_to_image (var->mlx_ptr,
			var->path[5], &img_width, &img_height);
	var->img[6] = mlx_xpm_file_to_image (var->mlx_ptr,
			var->path[6], &img_width, &img_height);
	var->img[7] = mlx_xpm_file_to_image (var->mlx_ptr,
			var->path[7], &img_width, &img_height);
	var->img[8] = mlx_xpm_file_to_image (var->mlx_ptr,
			var->path[8], &img_width, &img_height);
}

void	ft_norm_plus(t_var *var)
{
	if (var->str[var->i][var->j] == 'C' && var->n == 0 && ++var->c)
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[5], var->j * 40, var->i * 40);
	else if (var->str[var->i][var->j] == 'C' && var->n == 1 && ++var->c)
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[6], var->j * 40, var->i * 40);
	else if (var->str[var->i][var->j] == 'C' && var->n == 2 && ++var->c)
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[4], var->j * 40, var->i * 40);
	else if (var->str[var->i][var->j] == 'C' && var->n == 3 && ++var->c)
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[3], var->j * 40, var->i * 40);
	else if (var->str[var->i][var->j] == 'E')
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[7], var->j * 40, var->i * 40);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[8], var->j * 40, var->i * 40);
		var->e_i[var->d] = var->i;
		var->e_j[var->d] = var->j;
		var->d++;
	}
}

void	ft_norm(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img[0], var->j * 40, var->i * 40);
	if (var->str[var->i][var->j] == '1')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[2], var->j * 40, var->i * 40);
	if (var->str[var->i][var->j] == 'P')
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img[1], var->j * 40, var->i * 40);
		var->pos_i = var->i;
		var->pos_j = var->j;
	}
	else
		ft_norm_plus(var);
}

int	main(int ac, char **av)
{
	t_var	var;

	if (ac != 2)
		ft_print_error(ac);
	ft_assign(&var);
	if (!(ft_check_arg(av[1])))
		ft_print_error(0);
	var.str = read_map(av[1], &var.x, &var.y);
	ft_assignment(&var, var.x, var.y);
	while (var.str[var.i])
	{
		var.j = 0;
		while (var.str[var.i][var.j])
		{
			ft_norm(&var);
			var.j++;
			var.n++;
			if (var.n == 4)
				var.n = 0;
		}
		var.i++;
	}
	mlx_hook(var.win_ptr, 2, 0, ft_move, &var);
	mlx_hook(var.win_ptr, 17, 0, ft_close, &var);
	mlx_loop(var.mlx_ptr);
}
