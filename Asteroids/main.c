#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "character.h"
#include "Asteroid.h"
#include "Shoot.h"
#include "Health.h"
#include "Window.h"
#include "Score.h"
#include "Destroy.h"
#include "Menu.h"
#include "Game_Over.h"
#include "Timer.h"

struct Player player = {.x = 1920/2, .y = 1080/2, .directionX = 0, .directionY = 0, .speed = 0, .angle = -90};

struct Health life[3];

struct Score posScore = { .x = 10, .x = 10 };

struct Shoot bullet = { .x = 2500, .y = 2500, .directionX = 0, .directionY = 0, .timer = 0, .tire = 0 };

struct Big_Asteroid list_big_asteroid[6];

struct Medium_Asteroid list_medium_asteroid[12];

struct Small_Asteroid list_small_asteroid[24];

int create_texture() {
    textureasteroid = sfTexture_createFromFile("AsteroidSprite.png", NULL);
    for (int i = 0; i < nb_asteroid; i++) {
        list_big_asteroid[i].shape = sfRectangleShape_create();
        sfRectangleShape_setSize(list_big_asteroid[i].shape, (sfVector2f) { 200, 200 });
        sfRectangleShape_setTexture(list_big_asteroid[i].shape, textureasteroid, NULL);
        sfRectangleShape_setOrigin(list_big_asteroid[i].shape, (sfVector2f) { 100, 100 });
    }
    for (int i = 0; i < (nb_asteroid * 2); i++) {
        list_medium_asteroid[i].shape = sfRectangleShape_create();
        sfRectangleShape_setSize(list_medium_asteroid[i].shape, (sfVector2f) { 100, 100 });
        sfRectangleShape_setTexture(list_medium_asteroid[i].shape, textureasteroid, NULL);
        sfRectangleShape_setOrigin(list_medium_asteroid[i].shape, (sfVector2f) { 50, 50 });
    }
    for (int i = 0; i < (nb_asteroid * 4); i++) {
        list_small_asteroid[i].shape = sfRectangleShape_create();
        sfRectangleShape_setSize(list_small_asteroid[i].shape, (sfVector2f) { 50, 50 });
        sfRectangleShape_setTexture(list_small_asteroid[i].shape, textureasteroid, NULL);
        sfRectangleShape_setOrigin(list_small_asteroid[i].shape, (sfVector2f) { 25, 25 });
    }

    heart = sfTexture_createFromFile("Coeur.png", NULL);
    for (int i = 0; i < 3; i++) {
        life[i].shape = sfRectangleShape_create();
        sfRectangleShape_setSize(life[i].shape, (sfVector2f) { 50, 50 });
        sfRectangleShape_setTexture(life[i].shape, heart, NULL);
        sfRectangleShape_setPosition(life[i].shape, (sfVector2f) { 1850 - 60 * i, 0 });
    }
    texturevaisseau = sfTexture_createFromFile("Vaisseau.png", NULL);
    shape = sfCircleShape_create();
    sfCircleShape_setRadius(shape, 50);
    sfRectangleShape_setTexture(shape, texturevaisseau, NULL);
    sfCircleShape_setOrigin(shape, (sfVector2f) { 50, 50 });

    shape2 = sfRectangleShape_create();
    sfRectangleShape_setSize(shape2, (sfVector2f) { 10, 10 });
    sfRectangleShape_setFillColor(shape2, sfWhite);
    sfRectangleShape_setOrigin(shape2, (sfVector2f) { 5, 5 });
}

int bord(float* X,float* Y) {
    if (*X < -200) {
        *X += 2200;
    }
    if (*X> 2200) {
        *X -= 2400;
    }
    if (*Y < -200) {
       *Y += 1400;
    }
    if (*Y > 1200) {
        *Y -= 1400;
    }
    
}

int main() {

    srand(time());
    create_window();
    create_menu();
    nbasteroid();
    create_score();
    create_timer();
    create_game_over();
    create_texture();    
    positionAsteroid(list_big_asteroid);
    nblife();

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        if (!sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        };

        if (gameover == 1) {
            Button_Game_Over(bullet, list_big_asteroid, list_medium_asteroid, list_small_asteroid);
        }

        if (game == 0) {
            Button();
        }
        if (game == 1) {
            posScore.x = 10;
            posScore.y = 10;
            for (int i = 0; i < nb_asteroid; i++) {
                bord(&list_big_asteroid[i].x, &list_big_asteroid[i].y);
            }
            bord(&player.x, &player.y);
            bord(&bullet.x, &bullet.y);
            for (int i = 0; i < nb_asteroid * 2; i++) {
                bord(&list_medium_asteroid[i].x, &list_medium_asteroid[i].y);
            }
            for (int i = 0; i < nb_asteroid * 4; i++) {
                bord(&list_small_asteroid[i].x, &list_small_asteroid[i].y);
            }
            Shoot(&player, &bullet);
            positionAsteroid_medium(&bullet, list_big_asteroid, list_medium_asteroid);
            positionAsteroid_small(&bullet, list_medium_asteroid, list_small_asteroid);
            mouv(&player);
            mouv_asteroid(list_big_asteroid);
            mouv_asteroid_medium(list_medium_asteroid);
            mouv_asteroid_small(list_small_asteroid);
            colisionShip(&player, list_big_asteroid);
            colisionShip_medium(&player, list_medium_asteroid);
            colisionShip_small(&player, list_small_asteroid);
            colisionShoot_small(&bullet, list_small_asteroid);
            respawn_asteroid(list_big_asteroid);

            sfRectangleShape_setPosition(shape2, (sfVector2f) { bullet.x, bullet.y });
            sfCircleShape_setPosition(shape, (sfVector2f) { player.x, player.y });
            display_score();
            display_timer();
        }
        sfRenderWindow_clear(window, sfBlack);
        game_over();
        if (game == 1) {
            drawAsteroid(list_big_asteroid, list_medium_asteroid, list_small_asteroid);
            display_life(life);
            sfText_setPosition(score_text, (sfVector2f) { posScore.x, posScore.y });
            sfText_setPosition(timertext, (sfVector2f) { 800, 10 });
            sfRenderWindow_drawText(window, score_text, NULL);
            sfRenderWindow_drawText(window, timertext, NULL);
            sfRenderWindow_drawRectangleShape(window, shape2, NULL);
            sfRenderWindow_drawCircleShape(window, shape, NULL);
            sfCircleShape_setRotation(shape, player.angle + 90);
        }
        if (game == 0) {
            display_menu();
        }
        sfRenderWindow_display(window);
    }
    destroy_texture(list_big_asteroid, list_medium_asteroid, list_small_asteroid, life);
    return 0;
}