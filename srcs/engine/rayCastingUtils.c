/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCastingUtils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:42:07 by kaye              #+#    #+#             */
/*   Updated: 2021/11/24 18:14:26 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_hit(t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = 0;
			else if (ray->step_x == -1)
				ray->side = 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = 2;
			else if (ray->step_y == -1)
				ray->side = 3;
		}
		if (sglt()->map_info.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	projection_dist_calculate(void)
{
	t_player	ply;
	t_raycast	*ray;

	ply = sglt()->player;
	ray = &sglt()->raycast;
	if (ray->side == 0 || ray->side == 1)
		ray->perp_wall_dist = (ray->map_x - ply.pos_x
			+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - ply.pos_y
			+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

void	height_line_calculate(void)
{
	t_raycast	*ray;

	ray = &sglt()->raycast;
	ray->line_height = (int)(W_HEIGHT / ray->perp_wall_dist);
}

void	