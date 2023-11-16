#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "Asteroid.h"
#include "Shoot.h"
#include "Window.h"
#include "Score.h"

int positionAsteroid(struct Big_Asteroid list_big_asteroid[]) {
    for (int i = 0; i < nb_asteroid; i++) {
        list_big_asteroid[i].directionAX = (rand() % 10 + 1);
        list_big_asteroid[i].directionAY = (rand() % 10 + 1);
        if (rand() % 2 == 0) {
            if (rand() % 2 == 0) {
                list_big_asteroid[i].x = (rand() % 20) * 100;
                list_big_asteroid[i].y = (rand() % 3 - 3) * 100;
            }
            else
                list_big_asteroid[i].x = (rand() % 20) * 100;
                list_big_asteroid[i].y = ((rand() % 3) + 20) * 100;     // Permet de faire apparaitre un asteroid sur les cotés de l'écran
        }
        else 
            if (rand() % 2 == 0) {
                list_big_asteroid[i].x = (rand() % 3 - 3) * 100;
                list_big_asteroid[i].y = (rand() % 20) * 100;
            }
            else
                list_big_asteroid[i].x = ((rand() % 3) + 20) * 100;
                list_big_asteroid[i].y = (rand() % 20) * 100;
                list_big_asteroid[i].speed = (rand() % 3 + 2) * (1.3 * (level + 1));
        }
}

int positionAsteroid_medium(struct Shoot* bullet, struct Big_Asteroid list_big_asteroid[], struct Medium_Asteroid list_medium_asteroid[]) {
    for (int i = 0; i < nb_asteroid; i++) {
        if (abs(bullet->x - list_big_asteroid[i].x) < 100 && abs(bullet->y - list_big_asteroid[i].y) < 100 && list_big_asteroid[i].speed) {
            list_medium_asteroid[i].x = list_big_asteroid[i].x;
            list_medium_asteroid[i + 6].x = list_big_asteroid[i].x;
            list_medium_asteroid[i].y = list_big_asteroid[i].y;
            list_medium_asteroid[i + 6].y = list_big_asteroid[i].y;
            list_medium_asteroid[i].speed = (rand() % 3) + 3;
            list_medium_asteroid[i + 6].speed = (rand() % 3 + 2) * (1.3 * (level + 1));
            list_medium_asteroid[i].directionAX = (rand() % 10) + 1;
            list_medium_asteroid[i + 6].directionAX = (rand() % 10) + 1;
            list_medium_asteroid[i].directionAY = (rand() % 10) + 1;
            list_medium_asteroid[i + 6].directionAY = (rand() % 10) + 1;
            list_big_asteroid[i].speed = 0;
            score += 25;
            bullet->timer = 0;
            bullet->tire = 0;
        }

    }
}

int positionAsteroid_small(struct Shoot* bullet, struct Medium_Asteroid list_medium_asteroid[], struct Small_Asteroid list_small_asteroid[]) {
    for (int i = 0; i < nb_asteroid * 2; i++) {
        if (abs(bullet->x - list_medium_asteroid[i].x) < 50 && abs(bullet->y - list_medium_asteroid[i].y) < 50 && list_medium_asteroid[i].speed != 0) {
            list_small_asteroid[i].x = list_medium_asteroid[i].x;
            list_small_asteroid[i + 12].x = list_medium_asteroid[i].x;
            list_small_asteroid[i].y = list_medium_asteroid[i].y;
            list_small_asteroid[i + 12].y = list_medium_asteroid[i].y;
            list_small_asteroid[i].speed = (rand() % 3) + 3;
            list_small_asteroid[i + 12].speed = (rand() % 3 + 2) * (1.3 * (level + 1));
            list_small_asteroid[i].directionAX = (rand() % 10) + 1;
            list_small_asteroid[i + 12].directionAX = (rand() % 10) + 1;
            list_small_asteroid[i].directionAY = (rand() % 10) + 1;
            list_small_asteroid[i + 12].directionAY = (rand() % 10) + 1;
            list_medium_asteroid[i].speed = 0;
            score += 50;
            bullet->timer = 0;
            bullet->tire = 0;
        }
    }
}

int mouv_asteroid(struct Big_Asteroid list_big_asteroid[]) {
    for (int i = 0; i < nb_asteroid; i++) {
        if (list_big_asteroid[i].directionAX <= 5) {
            list_big_asteroid[i].x += -list_big_asteroid[i].speed * (list_big_asteroid[i].directionAX / 10);
        }
        else
            list_big_asteroid[i].x += list_big_asteroid[i].speed * (list_big_asteroid[i].directionAX / 10);
        if (list_big_asteroid[i].directionAY <= 5) {
            list_big_asteroid[i].y += -list_big_asteroid[i].speed * (list_big_asteroid[i].directionAY / 10);
        }
        else
            list_big_asteroid[i].y += list_big_asteroid[i].speed * (list_big_asteroid[i].directionAY / 10);

    }
}

int mouv_asteroid_medium(struct Medium_Asteroid list_medium_asteroid[]) {
    for (int i = 0; i < nb_asteroid * 2; i++) {
        if (list_medium_asteroid[i].directionAX <= 5 && list_medium_asteroid[i].directionAX != 0) {
            list_medium_asteroid[i].x += -list_medium_asteroid[i].speed * (list_medium_asteroid[i].directionAX / 10);
        }
        else if (list_medium_asteroid[i].directionAX != 0) {
            list_medium_asteroid[i].x += list_medium_asteroid[i].speed * (list_medium_asteroid[i].directionAX / 10);
        }
        if (list_medium_asteroid[i].directionAY <= 5 && list_medium_asteroid[i].directionAY != 0) {
            list_medium_asteroid[i].y += -list_medium_asteroid[i].speed * (list_medium_asteroid[i].directionAY / 10);
        }
        else if (list_medium_asteroid[i].directionAY != 0) {
            list_medium_asteroid[i].y += list_medium_asteroid[i].speed * (list_medium_asteroid[i].directionAY / 10);
        }
    }
}

int mouv_asteroid_small(struct Small_Asteroid list_small_asteroid[]) {
    for (int i = 0; i < nb_asteroid * 4; i++) {
        if (list_small_asteroid[i].directionAX <= 5 && list_small_asteroid[i].directionAX != 0) {
            list_small_asteroid[i].x += -list_small_asteroid[i].speed * (list_small_asteroid[i].directionAX / 10);
        }
        else if (list_small_asteroid[i].directionAX != 0) {
            list_small_asteroid[i].x += list_small_asteroid[i].speed * (list_small_asteroid[i].directionAX / 10);
        }
        if (list_small_asteroid[i].directionAY <= 5 && list_small_asteroid[i].directionAX != 0) {
            list_small_asteroid[i].y += -list_small_asteroid[i].speed * (list_small_asteroid[i].directionAY / 10);
        }
        else if (list_small_asteroid[i].directionAY != 0) {
            list_small_asteroid[i].y += list_small_asteroid[i].speed * (list_small_asteroid[i].directionAY / 10);
        }
    }
}

int drawAsteroid(struct Big_Asteroid list_big_asteroid[], struct Medium_Asteroid list_medium_asteroid[], struct Small_Asteroid list_small_asteroid[]) {
    for (int k = 0; k < nb_asteroid * 4; k++) {
        if (list_big_asteroid[k].speed != 0 && k < 6) {
            sfRectangleShape_setPosition(list_big_asteroid[k].shape, (sfVector2f) { list_big_asteroid[k].x, list_big_asteroid[k].y });
            sfRenderWindow_drawRectangleShape(window, list_big_asteroid[k].shape, NULL);
        }
        if (list_medium_asteroid[k].speed != 0 && k < 12) {
            sfRectangleShape_setPosition(list_medium_asteroid[k].shape, (sfVector2f) { list_medium_asteroid[k].x, list_medium_asteroid[k].y });
            sfRenderWindow_drawRectangleShape(window, list_medium_asteroid[k].shape, NULL);
        }
        if (list_small_asteroid[k].speed != 0) {
            sfRectangleShape_setPosition(list_small_asteroid[k].shape, (sfVector2f) { list_small_asteroid[k].x, list_small_asteroid[k].y });
            sfRenderWindow_drawRectangleShape(window, list_small_asteroid[k].shape, NULL);
        }
    }
}

int respawn_asteroid(struct Big_Asteroid list_big_asteroid[]) {
    if (list_big_asteroid[0].speed == 0) {
        if (score % (25 * nb_asteroid + 50 * nb_asteroid * 2 + 100 * nb_asteroid * 4) == 0 && score != 0) {
            positionAsteroid(list_big_asteroid);
            level += 1;
        }
    }
}

int nbasteroid() {
    nb_asteroid = 6;
}