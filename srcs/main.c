/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:32:49 by kaye              #+#    #+#             */
/*   Updated: 2021/11/22 18:53:07 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_parsing(char const *path)
{
	info_parsing(path);
	// path_parsing();
	// map_parsing(fd);
}

int main(int ac, char **av)
{
	(void)av;
	t_cub3d *ptr;

	if (2 != ac)
		exit_clean(USAGE);
	ptr = sglton();
	ft_bzero(ptr, sizeof(t_cub3d));

	_parsing(av[1]);
	t_list *tmp = ptr->config;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	// exit_clean("nothing");
	return (SUCCESSE);
}