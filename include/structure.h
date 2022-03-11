/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** structure
*/


#ifndef STRUCTURE_H_
#define STRUCTURE_H_


#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>

#include <stdbool.h>

#define LVL_UP (100)
#define INV_SIZE (12)

typedef enum {
    rain,
    snow,
}p_type;

typedef struct {
    sfVector2f velocity;
    sfVector2f emitter;
    sfTime lifetime;
    p_type type;
}particles_t;

typedef struct {
    particles_t **particles;
    sfVertexArray *vertices;
    sfVector2f scr_ctr;
    sfTime lifetime;
    sfClock *clock;
} system_t;

typedef struct image_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f position;
    int sheet_len;
} image_t;

typedef struct stats_s
{
    int hp;
    int maxhp;
    int dmg;
    int armor;
    int xp;
    int lvl;
    sfClock *move_clock;
    sfClock *anim_clock;
} stats_t;

typedef struct gameobject_s
{
    image_t *image;
    char *tag;
    stats_t *stats;
    bool active;
    int (*on_collision)(void *ctx, struct gameobject_s *);
    struct gameobject_s *next;
    bool animated;
} gameobject_t;

typedef struct button_s
{
    sfRectangleShape *rect;
    sfVector2f position;
    sfTexture *normal;
    sfTexture *hover;
    sfTexture *click;
    char *tag;
    bool active;
    void (*callback)(void *);
    void (*hover_callback)(void *, void *);
} button_t;

typedef struct sounds_s
{
    sfMusic *bg_music;
    sfMusic *death;
} sounds_t;

typedef struct music_s {
    sfMusic *music;
    sfBool loop;
    bool played_on_creation;
} music_t;


typedef struct scene_s
{
    gameobject_t *gameobjects;
    button_t **buttons;
    music_t *music;
    system_t *particlesystem;
} scene_t;

typedef struct dialogue_s
{
    sfRectangleShape *box;
    sfVector2f box_offset;
    sfText *text;
    sfVector2f text_offset;
    sfFont *font;
    bool talking;
} dialogue_t;

typedef struct fighters_s
{
    gameobject_t *enemy;
    gameobject_t *player;
    bool player_win;
    bool player_turn;
    sfClock *delay;
    dialogue_t *text;
} fighters_t;

typedef struct battle_ui_s
{
    sfRectangleShape *hp_bg_p;
    sfRectangleShape *hp_bar_p;
    sfRectangleShape *hp_bg_e;
    sfRectangleShape *hp_bar_e;
} battle_ui_t;

typedef struct pause_menu_s
{
    sfRectangleShape *panel;
    sfVector2f panel_offset;
    button_t *menu;
    sfVector2f menu_offset;
    button_t *quit;
    sfVector2f quit_offset;
} pause_menu_t;

typedef struct stats_overlay_s
{
    sfText *dmg_text;
    sfVector2f dmg_offset;
    sfText *armor_text;
    sfVector2f armor_offset;
    sfText *hp_text;
    sfVector2f hp_offset;
    sfText *lvl_text;
    sfVector2f lvl_offset;
    sfText *exp_text;
    sfVector2f exp_offset;
    sfFont *font;
} stats_overlay_t;

typedef struct equipment_s
{
    gameobject_t *object;
    void (*on_pickup)(void *ctx, struct equipment_s *equip);
    void (*on_unequip)(void *ctx, struct equipment_s *equip);
    int power;
    bool unequipped;
    struct equipment_s *next;
} equipment_t;

typedef struct inv_slot_s
{
    button_t *slot_button;
    equipment_t *equipment;
    sfVector2f offset;
} inv_slot_t;

typedef struct inventory_s
{
    inv_slot_t **slots;
    equipment_t *loot;
} inv_t;

typedef struct ui_s
{
    bool paused;
    battle_ui_t *battle_ui;
    dialogue_t *dialogue_box;
    pause_menu_t *pause;
    stats_overlay_t *stats_ui;
    inv_t *inventory;
    void (**ui_overlay)(void *);
} ui_t;

typedef struct tooltip_s
{
    sfText *text;
    sfFont *font;
    sfVector2f position;
    char *tip;
} tooltip_t;

typedef struct option_s
{
    bool music;
    int volume;
    int framerate;
    sfText *music_text;
    sfText *volume_text;
    sfText *framerate_text;
    sfFont *font;
} option_t;

typedef struct context_s
{
    sfRenderWindow *window;
    sfView *view;
    sfEvent event;
    scene_t **scenes;
    int sceneindex;
    ui_t *ui;
    sfVector2f windowsize;
    fighters_t *fighters;
    tooltip_t *tool_tip;
    tooltip_t *quest;
    bool quest_active;
    option_t *opt;
} context_t;

typedef enum {
    menu,
    level_one,
    fight_scene,
    how_to_play,
    end_title,
    options_menu,
    win_title
} scenes_enum;

typedef enum {
    hp_buff,
    dmg_buff,
    armor_buff
} buff_types;

#endif /* !STRUCTURE_H_ */
