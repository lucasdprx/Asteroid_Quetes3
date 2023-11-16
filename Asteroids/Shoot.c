#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "Shoot.h"
#include "Asteroid.h"
#include "character.h"
#include "Score.h"

int colisionShoot_small(struct Shoot* bullet, struct Small_Asteroid list_small_asteroid[])
{
    for (int i = 0; i < nb_asteroid * 4; i++) {
        if (abs(bullet->x - list_small_asteroid[i].x) < 25 && abs(bullet->y - list_small_asteroid[i].y) < 25 && list_small_asteroid[i].speed != 0) {
            list_small_asteroid[i].speed = 0;
            bullet->tire = 0;
            score += 100;
            bullet->timer = 0;
        }
    }
}

int Shoot(struct Player* player, struct Shoot* bullet) {
    if (sfKeyboard_isKeyPressed(sfKeySpace) && bullet->timer == 0) {
        bullet->x = player->x;
        bullet->y = player->y;
        bullet->directionX = cosf(player->angle * 3.1415 / 180);
        bullet->directionY = sinf(player->angle * 3.1415 / 180);
        bullet->tire = 1;
        bullet->timer = 1;
    }
    if (bullet->tire == 1) {
        bullet->x += bullet->directionX * 20;
        bullet->y += bullet->directionY * 20;
    }
    if (bullet->timer == 60) {
        bullet->tire = 0;
        bullet->timer = 0;
    }
    else if (bullet->timer > 0) {
        bullet->timer += 1;
    }

    if (bullet->timer == 0) {
        bullet->x = 2500;
        bullet->y = 2500;
    }

}