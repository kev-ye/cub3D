/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:52:51 by kaye              #+#    #+#             */
/*   Updated: 2021/11/29 22:18:51 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_map_clean(void)
{
	t_cub3d	*ptr;
	int		i;

	ptr = sglt();
	if (NULL != ptr->map_info.map)
	{
		free(ptr->map_info.map);
		ptr->map_info.map = NULL;
	}
	i = 0;
	while (i < PATHMAX)
	{
		if (NULL != ptr->map_info.path[i])
			free_clean((void **)&(ptr->map_info.path[i]));
		++i;
	}
}

void	_clean(void)
{
	t_cub3d	*ptr;
	int		i;

	i = 0;
	ptr = sglt();
	if (NULL != ptr)
	{
		if (ptr->config)
		{
			while (NULL != ptr->config[i])
				free_clean((void **)&ptr->config[i++]);
			free(ptr->config);
			ptr->config = NULL;
		}
		_map_clean();
		mlx_clean();
		free_clean((void **)&ptr);
	}
}

// void		exit_clean(char *msg)
void	exit_clean(char *msg, char *file, int line)
{
	if (NULL != msg)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		printf("-> [%s] - [%d]\n", file, line);
	}
	_clean();
	// system("leaks cub3D");
	exit(EXIT_FAILURE);
}