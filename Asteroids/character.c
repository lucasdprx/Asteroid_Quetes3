#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "character.h"
#include "Asteroid.h"
#include "Health.h"

int mouv(struct Player *player) {
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (player->speed < 15) {
            player->speed += 0.125;
        }
        player->directionX = cosf(player->angle * 3.1415 / 180);
        player->directionY = sinf(player->angle * 3.1415 / 180);
        player->y += player->directionY * player->speed;
        player->x += player->directionX * player->speed;
    }
    else if (player->speed != 0) {
        player->speed *= 0.98;
        player->y += player->directionY * player->speed;
        player->x += player->directionX * player->speed;
    }

    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        player->angle += 5;
    }
    else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        player->angle -= 5;
    }
}

int colisionShip(struct Player *player, struct Big_Asteroid list_big_asteroid[])
 {
    for (int i = 0; i < 6; i++) {
        if (abs(player->x - list_big_asteroid[i].x) < 130 && abs(player->y - list_big_asteroid[i].y) < 130 && list_big_asteroid[i].speed != 0 && timer_life <= 0) {
            player->x = 1920 / 2;
            player->y = 1080 / 2;
            player->speed = 0;
            nb_life -= 1;
            timer_life += 1;

        }
    }
    if (timer_life > 0) {
        timer_life += 1;
    }
    if (timer_life == 120) {
        timer_life = 0;
    }
}

int colisionShip_medium(struct Player* player, struct Medium_Asteroid list_medium_asteroid[]) {
    for (int i = 0; i < 12; i++) {
        if (abs(player->x - list_medium_asteroid[i].x) < 80 && abs(player->y - list_medium_asteroid[i].y) < 80 && list_medium_asteroid[i].speed != 0 && timer_life == 0) {
            player->x = 1920 / 2;
            player->y = 1080 / 2;
            player->speed = 0;
            nb_life -= 1;
            timer_life += 1;
        }
    }
}

int colisionShip_small(struct Player* player, struct Small_Asteroid list_small_asteroid[]) {
    for (int i = 0; i < 24; i++) {
        if (abs(player->x - list_small_asteroid[i].x) < 55 && abs(player->y - list_small_asteroid[i].y) < 55 && list_small_asteroid[i].speed != 0 && timer_life == 0) {
            player->x = 1920 / 2;
            player->y = 1080 / 2;
            player->speed = 0;
            nb_life -= 1;
            timer_life += 1;
        }
    }
}
