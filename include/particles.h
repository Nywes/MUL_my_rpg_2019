/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particles
*/

#ifndef PARTICLES_H_
#define PARTICLES_H_

#define PARTICLES_NBR 65

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/System/Vector2.h>

#include "structure.h"

int verify_particles(particles_t **p, int p_ctr);
void part_reset(particles_t *p, sfVertex *v, sfVector2f em_pos, p_type type);
system_t *system_init(p_type type);
void system_update(system_t *system, sfTime elapsed, sfRenderWindow *window);
void system_destroy(system_t *system);
void system_setemitter(system_t *system);

#endif /* !PARTICLES_H_ */
