/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:27:49 by jmoucach          #+#    #+#             */
/*   Updated: 2020/02/26 12:49:25 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void				setup_param(t_pt pt_one, t_pt pt_two,
	t_line_param *line_param)
{
	line_param->diff.x = ft_abs(pt_two.x - pt_one.x);
	line_param->diff.y = ft_abs(pt_two.y - pt_one.y);
	line_param->off = line_param->diff.x - line_param->diff.y;
	line_param->inc.x = (pt_one.x < pt_two.x ? 1 : -1);
	line_param->inc.y = (pt_one.y < pt_two.y ? 1 : -1);
}

void				draw_line(t_pt pt_one, t_pt pt_two,
	Uint32 *pixels, int colour)
{
	t_pt			pt;
	t_line_param	line_param;
	Uint32			*pix;

	pix = pixels;
	setup_param(pt_one, pt_two, &line_param);
	pt = pt_one;
	while (pt.x != pt_two.x || pt.y != pt_two.y)
	{
		pix[pt.x + pt.y * WIDTH] = colour;
		if ((line_param.error = line_param.off * 2) > -line_param.diff.y)
		{
			line_param.off -= line_param.diff.y;
			pt.x += line_param.inc.x;
		}
		if (line_param.error <= line_param.diff.x)
		{
			line_param.off += line_param.diff.x;
			pt.y += line_param.inc.y;
		}
	}
	pix[pt.x + pt.y * WIDTH] = colour;
}

void	check_and_draw_line(t_pt start, t_pt end, t_fdf *img, int col)
{
	if (start.x < 0)
		start.x = 0;
	if (start.y < 0)
		start.y = 0;
	if (end.x < 0)
		end.x = 0;
	if (end.y < 0)
		end.y = 0;
	if (start.x > WIDTH)
		start.x = WIDTH;
	if (start.y > HEIGHT)
		start.y = HEIGHT;
	if (end.x > WIDTH)
		end.x = WIDTH;
	if (end.y > HEIGHT)
		end.y = HEIGHT;
	ft_putendl("\nstart.x");//DEBUG
	ft_putnbr(start.x);//DEBUG
	ft_putendl("\nstart.y");//DEBUG
	ft_putnbr(start.y);//DEBUG
	ft_putendl("\nend.x");//DEBUG
	ft_putnbr(end.x);//DEBUG
	ft_putendl("\nend.y");//DEBUG
	ft_putnbr(end.y);//DEBUG
	draw_line(start, end, img->pixels, col);
}

void			ft_trace_line(t_pt a, t_pt b, t_fdf *img, int col)
{
	//FUNCTION THAT WE SOULD USE BUT NOT WORKING
	/*t_pt			pt_one;
	t_pt			pt_two;

	pt_one.x = img->map->ox + a.x * img->map->base_gap;
	pt_one.y = img->map->oy + a.y * img->map->base_gap;
	pt_two.x = img->map->ox + b.x * img->map->base_gap;
	pt_two.y = img->map->oy + b.y * img->map->base_gap;
	check_and_draw_line(pt_one, pt_two, img, col);*/
	//draw_line(a, b, *img->pixels, col);
	
	//Function as it was with SDL_Render... not to be used but working
	int			gap;
	int			ox;
	int			oy;
	SDL_Color 	color;

	gap = img->map->base_gap;
	ox = img->map->ox;
	oy = img->map->oy;
	//color = ft_color_of_lower_element(a, b);
	color = ft_hexa_to_SDL(col);//fixed color until we adjust it
	SDL_SetRenderDrawColor(img->renderer, color.r, color.g, color.b,
			color.a);
	SDL_RenderDrawLine(img->renderer, ox + a.x * gap,
			oy + a.y * gap, ox + b.x * gap, oy + b.y * gap);
			
}