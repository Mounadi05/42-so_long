/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:52:25 by amounadi          #+#    #+#             */
/*   Updated: 2022/03/02 03:44:10 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef enum e_enum
{
	grass,
	player,
	tree,
	berry,
	apple,
	melon,
	cherr,
	door,
	c_door,
}t_enum;

typedef struct s_var
{
	t_enum	obj;
	void	*win_ptr;
	void	*mlx_ptr;
	int		pos_i;
	int		pos_j;
	int		e_i[1024];
	int		e_j[1024];
	int		c;
	int		o;
	char	**str;
	void	*img[9];
	char	*path[9];
	int		i;
	int		j;
	int		x;
	int		y;
	int		n;
	int		d;
}t_var;

typedef struct s_var_read
{
	char	**str;
	char	*tmp;
	int		i;
	int		j;
	int		fd;
	int		p;
	int		c;
	int		e;

}t_var_read;

char	*ft_strdup(const char *s1);
void	ft_free(char **str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	**read_map(char *map, int *x, int *y);
int		ft_move(int key, t_var *var);
void	ft_assign(t_var *var);
void	ft_putnbr(int nb);
int		ft_check_arg(char *str);
void	ft_print_error(int ac);
int		ft_close(t_var *var);
#endif
