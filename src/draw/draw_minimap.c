/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:15:41 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 15:42:56 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void		draw_minimap(t_data *data)
{
	int		x;
	int		y;
	int		colour;
	t_point	l;

	l.x = (0.2 * SCREEN_WIDTH) / data->msize.x;
	l.y = (0.2 * SCREEN_HEIGHT) / data->msize.y;
	y = 0;
	while (y < data->msize.y)
	{
		x = 0;
		while (x < data->msize.x)
		{
			if (data->map[y][x] >= 1)
				colour = data->map[y][x] == 7 ? 0x6b1ad6 : 0x8B;
			else
				colour = 0xA9A9A9;
			draw_rect_to_sdl((t_point){x * l.x, y * l.y},
			(t_point){x * l.x + l.x, y * l.y + l.y}, data, colour);
			x++;
		}
		y++;
	}
	show_enemies(data, l);
	show_player(data, l);
}
