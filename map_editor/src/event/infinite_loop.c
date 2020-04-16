/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:10:12 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/06 14:54:12 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			ft_infinite_loop(t_fdf *img, t_mouse *mous, t_key *key)
{
	int			isquit;
	SDL_Event	event;

	isquit = 0;
	if (!(img->grid = SDL_CreateTexture(img->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH,
		HEIGHT)))
		ft_clean_exit(img, (char *)SDL_GetError());
	while (isquit == 0)
	{
		//while (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_KEYDOWN)
		SDL_PollEvent(&event);
//		while (SDL_PollEvent(&event))
//		{
			if (event.type == SDL_QUIT)
				exit (0);
			ft_menu_event( mous, event);
			//ft_print_pressed_button(img, mous->loop);
			ft_clear_and_render(img, mous->loop);
			ft_keys_event(img, event, key);
			ft_mouse_event(img, mous, event);
//		}
	}
}

void		ft_fdf(t_map *map, char *map_name)
{
	t_fdf	*img;
	t_mouse	mous;
	t_key	key;

	if (!(img = ft_ptr_init(map_name)))
		//return ;
		ft_clean_exit(img, "Problems during main structure creation");//NEWLY ADDED
	if (!(ft_mouse_init(&mous)) || !(ft_key_init(&key)))
		//return ;
		ft_clean_exit(img, "Problems during mouse or key initilization");//NEWLY ADDED
	img->map = map;
	ft_clear_and_render(img, mous.loop);
	ft_infinite_loop(img, &mous, &key);
}
