/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include "structure.h"

#define OK (0)
#define ERR (84)

#define P_IDLE_START (0)
#define P_IDLE_END (48)

#define P_WIDTH (16)
#define P_RUN_START (64)
#define P_RUN_END (128)

#define DOWN sfKeyS
#define UP sfKeyZ
#define LEFT sfKeyQ
#define RIGHT sfKeyD

#define SCENE_TOTAL (7)

int start_game(void);
context_t *init_context(void);

int init_dialogue_box(ui_t *);
void init_dialogue_text(dialogue_t *, int);
void set_box_texture(dialogue_t *, int, int);

scene_t **init_scenes(void);

scene_t *init_main_menu(void);

button_t *create_button(sfVector2f position, sfVector2f size, char *path);

music_t *create_music(sfBool loop, bool played, char *path);
void free_music(music_t *music);

image_t *create_image(char *filepath, sfIntRect rect, sfVector2f pos, int len);

int add_gameobject(gameobject_t **head, gameobject_t *new);
gameobject_t *create_gameobject(image_t *image, char *tag, stats_t *stats);

void load_scene(context_t *context);

void load_gameobjects(context_t *context, scene_t *scene);

void load_buttons(context_t *context, scene_t *scene);
void set_hover_texture(button_t *button, context_t *context);
bool is_mouse_over(button_t *button, sfVector2i click_pos, context_t *ctx);
void set_click_texture(context_t *context);
void mouse_released(context_t *context);

void cycle_callbacks(sfVector2i click, button_t **buttons, context_t *ctx);

void quit_game(void *context);
void back_to_menu(void *context);
void load_level_one(void *context);
void load_htp(void *context);
void get_back_to_lvl_one(void *context);

void load_opt(void *context);

scene_t *init_htp_scene(void);

int init_ctx_opt(context_t *context);

stats_t *init_stats(int hp, int dmg, int armour);

gameobject_t *init_player(void);
gameobject_t *init_enemy(sfVector2f pos);
gameobject_t *init_npc(sfVector2f pos);
gameobject_t *init_bat(sfVector2f pos);

scene_t *init_level_one(void);

scene_t *init_options_menu(void);

scene_t *init_fight_scene(void);

void animate_gameobject(gameobject_t *object, context_t *context);

bool move_player(gameobject_t *player, context_t *ctx);
bool raycast_future_pos(gameobject_t *player, \
sfVector2f nextpos, context_t *ctx);

void pause_game(context_t *ctx);

void free_context(context_t *ctx);
void free_gameobject(gameobject_t *obj);
void free_button(button_t *button);
void free_stats_overlay(stats_overlay_t *stats);

int verify_context(context_t *ctx);
int verify_scenes(scene_t **scenes, int total);
int verify_buttons(button_t **buttons, int total);
int verify_gameobjects(gameobject_t *objs, int total);

void make_snow(context_t *ctx);

bool check_collision(scene_t *scene, context_t *context);
bool check_col(sfIntRect p_rect, context_t *ctx, gameobject_t *enemy);
bool check_can_talk(context_t *ctx);

int prepare_fight(void *_ctx, gameobject_t *enemy);

void print_opt_values(context_t *context);

void gain_exp(int amount, gameobject_t *player);
gameobject_t *find_player(context_t *ctx);
void take_damage(gameobject_t *obj, int amount, context_t *ctx);
int end_fight(context_t *ctx);

void attack_button(void *context);
void potion_button(void *context);
void respawn(void *_ctx);

void load_ui(context_t *ctx);
void init_ui_pointers(context_t *ctx);

void fight_ui(void *context);

gameobject_t *add_scientist();

int init_battle_ui(ui_t *ui);

void enemy_turn(context_t *ctx);

int dialogue_1(void *_ctx, gameobject_t *npc);
int dialogue_2(void *_ctx, gameobject_t *npc);
int dialogue_3(void *_ctx, gameobject_t *npc);

int init_dialogue_box(ui_t *ui);

void show_dialogue(context_t *ctx);

int init_pause_menu(ui_t *ui);

void show_pause(context_t *ctx);
void hide_pause(context_t *ctx);
void assign_pause_buttons(context_t *ctx);

int init_stats_overlay(ui_t *ui);
char *get_stat_string(int stat, char *stat_str);

void inventory_ui(void *_ctx);
void hide_inventory_ui(context_t *ctx);

void show_stats_ui(context_t *ctx);
void assign_stat_text_values(context_t *ctx);
void reset_stat_text(context_t *ctx);
bool check_stat_text_empty(context_t *ctx);

int init_inventory(ui_t *ui);

int init_loot(inv_t *inventory);

void load_loot(context_t *context);
int pick_up(void *_ctx, equipment_t *pick_up);
void check_slot_clicked(context_t *ctx);

void apply_atk_boost(void *_ctx, equipment_t *equipment);
void remove_atk_boost(void *_ctx, equipment_t *equipment);
void drink_hp_potion(void *_ctx, equipment_t *equipment);

void slot_callback(equipment_t *equipment, context_t *ctx);
void unequip(context_t *ctx, inv_slot_t *slot);
void check_hovering_slots(inv_slot_t *slot, context_t *ctx);

void turn_on_music(void *context);
void turn_off_music(void *context);
void increase_volume(void *context);
void decrease_volume(void *context);
void increase_framerate(void *context);
void decrease_framerate(void *context);

void assign_stat_text_values(context_t *ctx);

int init_obstacles(gameobject_t *head);

int stop_player_move(void *_ctx, gameobject_t *obj);

scene_t *init_death_scene(void);

void free_ui(ui_t *ui);
void free_inventory(inv_t *inv);
void free_fighters(fighters_t *fighters);

tooltip_t *init_tooltip(context_t *ctx);

void show_item_info(void *_ctx, void *_slot);

void show_quest(context_t *ctx);

scene_t *init_win_scene(void);

bool check_defeated_game(context_t *ctx);

int borned_rand(int lo, int hi);

gameobject_t *get_player_effigy(void);
gameobject_t *get_enemy_effigy(void);
gameobject_t *get_fight_platforms(void);

#endif /* !MY_RPG_H_ */
