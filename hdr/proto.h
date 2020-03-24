/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:03:28 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:55:19 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "doom_nukem.h"

/*
** INIT
*/

void			create_renderer_texture_and_pixels(t_data *data);
void			nullify_surfaces(t_data *data);
void			init(t_data *data);
void			set_values(t_data *data, int argc);
void			get_hud_text_1(t_data *data);
void			set_raycast_values(t_raycast *value, t_player player, int x);
t_sprite		create_sprites(char *path, t_d_point scale, t_data *data);

/*
** Draw
*/

void			draw_rect_to_sdl(t_point pt_one, t_point pt_two,
	t_data *data, int colour);
void			setup_param(t_point pt_one, t_point pt_two,
	t_line_param *line_param);
void			drawline(t_point pt_one, t_point pt_two,
	t_data *data, int colour);

/*
** Main
*/

short				name_parser(char *file_name);
void			free_maps(t_data *data);

/*
** New map
*/

char			*join_strings(char *s1, char *s2);
void			allocate_map(t_data *data, short id);
char			*read_map(int fd);
void			new_map(t_data *data, char *title, short id);

/*
** Fill map
*/

void			print_map(t_map map);
int				copy_cur_map(t_data *data);
void			delete_cur_map(t_data *data);
void			fill_raw_map(t_data *data, char *str, short id);
void			fill_map(t_data *data, t_map map);

/*
** Draw map box
*/

void			draw_minimap(t_data *data);

/*
** Event loop
*/

void			handle_input2(t_data *data, const Uint8 *state);
void			handle_input(t_data *data, const Uint8 *state);
void			handle_menu_input(t_data *data, const Uint8 *state);
void			game_loop(t_data *data);

/*
** Show player
*/

void			show_player(t_data *data, t_point length);
void			show_enemies(t_data *data, t_point length);

/*
** Raycasting
*/

void			give_draw_values(t_raycast *values, t_data *data);
void			get_texturing_values(t_raycast *values, t_data *data);
void			set_dist_and_step(t_raycast *values);
void			hit_wall(t_raycast *values, t_data *data);
void			raycasting(t_data *data);

/*
** Load image
*/

void			load_media_hud_1(t_data *data);
SDL_Texture		*loadimage_hud(t_data *data, char *path);
Uint32			get_pixel(SDL_Surface *s, int x, int y);
SDL_Surface		*loadimage(char *path);
void			loadmedia(t_data *data);

/*
** Parsing
*/

short			count_lines_and_col(t_data *data, char *str, short id);
void			parse_boudaries(char *str, t_data *data, short id);
void			parse_map(t_data *data, char *str, short id);
short			parse_char(char *str);

/*
** Floor caster
*/

void			floor_side(t_floorcast *f, t_raycast *r);
void			roofcaster(t_data *data, t_raycast *r, int x);
void			floorcaster(t_data *data, t_raycast *r, int x);

/*
** movement
*/

void			strafe(t_data *data, int strafe, int sprint);
void			walk(t_data *data, int walkdir, int sprint);
void			rotate(t_data *data);
void			look_up_down(t_data *data);

/*
** skybox
*/

void			print_skybox(t_data *data);

/*
** HUD
*/
void prepare_hud(t_data *data);
void display_hud(t_data *data);
void display_health(t_data *data);
void display_ammo_side(t_data *data);
void	display_hud_keys(t_data *data);

/*
** Weapon
*/
short use_weapon(t_data *data, short id);
short use_knuckle(t_data *data, short is_firing);
short use_shotgun(t_data *data, short is_firing);
short use_plasma(t_data *data, short is_firing);
short use_chainsaw(t_data *data, short is_firing);
short use_handgun(t_data *data, short is_firing);
short use_bfg(t_data *data, short is_firing);
short use_minigun(t_data *data, short is_firing);

/*
** Combat
*/

void	combat(t_data *data);
void	hits_dealt(t_data *data);
void	red_hit_screen(t_data *data);
void	green_hp_screen(t_data *data);
void	blue_hp_screen(t_data *data);

/*
** Object list
*/

void remove_object(t_object **head, int key);
void rollback_object(t_object **head);
void addback_object(t_object **head, t_object *new);
t_object *new_object(int id, int type, t_d_point pos);
void swap_objects(t_object **head, t_object *obj1, t_object *obj2);

//
void pathfind(t_data *data, t_object *obj);

/*
** Object caster
*/

void sort_objects(t_data *data);
void objectcaster(t_data *data, t_object *obj);
void set_objcast_values(t_data *data, t_objcast *val, t_object *iterator, t_sprite sprite);
int get_movescreen_value(t_data *data, t_objcast o, int pos);
void		get_dist_to_player(t_data *data);

/*
** Items
*/

void	item_pickup(t_data *data);
short	cell_pickup(t_data *data, t_object **obj);
short	shell_pickup(t_data *data, t_object **obj);
short	bullet_pickup(t_data *data, t_object **obj);

/*
** Doors
*/

void	check_doors(t_data *data);

/*
** Get obj data
*/

void			get_obj_data_0(t_object **obj);
void			get_obj_data_1(t_object **obj);
void			get_obj_data_2(t_object **obj);

/*
** Nullify
*/

void nullify_mallocs(t_data *data);
void nullify_tab(void **tab, int size);
void nullify_sprites(t_sprite *sprites, int size);

/*
** Clean exit
*/

void clean_exit(t_data *data, char *err);
void	free_objects(t_data *data);

/*
** Shading
*/

Uint32			shaded_color(t_data *data, Uint32 color, double dist, t_object *o);

/*
** State machine
*/

void	hits_taken(t_data *data, t_object *obj);
void state_machine(t_data *data);

/*
** Menu
*/

void	menu(t_data *data);
void	menu_selection(t_data *data);
void	get_map_values(t_data *data, short selected);

#endif
