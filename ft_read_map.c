/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:58:58 by amounadi          #+#    #+#             */
/*   Updated: 2022/03/02 03:41:05 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_error(void)
{
	write(2, "error\n", 6);
	write(2, "error in map\n", ft_strlen("error in map\n"));
	exit(0);
}

static char	**take_str(char *map, int len, int *y)
{
	t_var_read	var;

	var.j = 0;
	var.str = (char **)malloc(sizeof(char *) * (len + 1));
	if (!var.str)
		return (NULL);
	var.fd = open(map, O_RDONLY);
	while (1)
	{
		var.tmp = get_next_line(var.fd);
		if (!var.tmp || var.tmp[0] == '\n')
			break ;
		*y = ft_strlen(var.tmp);
		var.str[var.j] = (char *)malloc(*y + 1);
		if (!var.str[var.j])
			return (NULL);
		var.i = -1;
		while (var.tmp[++var.i])
			var.str[var.j][var.i] = var.tmp[var.i];
		var.str[var.j++][var.i] = '\0';
		ft_free(&var.tmp);
	}
	close(var.fd);
	var.str[var.j] = 0;
	return (var.str);
}

static	void	ft_norm(char u, int *p, int *e, int *c)
{
	if (!(u == 'P' || u == '0' || u == '1' || u == 'E' || u == 'C'))
		ft_error();
	if (u == 'P')
		(*p)++;
	if (u == 'E')
		(*e)++;
	if (u == 'C')
		(*c)++;
}	

static int	check_map(char **str, int i, int j)
{
	t_var_read	var;

	var.i = 0;
	var.p = 0;
	var.c = 0;
	var.e = 0;
	while (str[var.i])
	{
		var.j = 0;
		while (str[var.i][var.j])
		{
			if (str[0][var.j] != '1' || str[i][var.j] != '1'
				|| str[var.i][0] != '1' || str[var.i][j] != '1')
				ft_error();
			ft_norm (str[var.i][var.j], &var.p, &var.e, &var.c);
			var.j++;
		}
		var.i++;
	}
	if (var.p == 1 && var.c >= 1 && var.e >= 1)
		return (1);
	return (0);
}

char	**read_map(char *map, int *x, int *y)
{
	t_var_read	var;

	var.i = 0;
	var.fd = open(map, O_RDONLY);
	while (1)
	{
		var.tmp = get_next_line(var.fd);
		if (!var.tmp)
			break ;
		if (var.tmp[0] == '\n')
			ft_error();
		var.i++;
		ft_free(&var.tmp);
	}
	close(var.fd);
	*x = var.i;
	var.str = take_str(map, var.i, y);
	if (!(check_map(var.str, var.i - 1, *y - 1)))
		ft_error();
	return (var.str);
}
