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
#include "Destroy.h"
#include "Window.h"
#include "Health.h"
#include "Menu.h"
#include "Game_Over.h"
#include "Timer.h"

int create_game_over() {
    texture_game_over = sfTexture_createFromFile("Game_over_Asteroid.png", NULL);
    shape_game_over = sfRectangleShape_create();
    sfRectangleShape_setSize(shape_game_over, (sfVector2f) { 1000, 500 });
    sfRectangleShape_setTexture(shape_game_over, texture_game_over, NULL);
    sfRectangleShape_setPosition(shape_game_over, (sfVector2f) { 450 ,200 });
}

int game_over() {
    if (nb_life < 1) {
        gameover = 1;
        game = 2;
        sfRenderWindow_drawRectangleShape(window, shape_game_over, NULL);
        sfText_setPosition(timertext, (sfVector2f) { 650, 400 });
        sfRenderWindow_drawText(window, timertext, NULL);
        sfText_setPosition(score_text, (sfVector2f) { 1050, 400 });
        sfRenderWindow_drawText(window, score_text, NULL);
    }
}

int Button_Game_Over(struct Shoot* bullet, struct Big_Asteroid list_big_asteroid[], struct Medium_Asteroid list_medium_asteroid[], struct Small_Asteroid list_small_asteroid[]) {
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfMouse_getPosition(window).x > 400 && sfMouse_getPosition(window).x < 800 && sfMouse_getPosition(window).y > 550 && sfMouse_getPosition(window).y < 750) {
        game = 1;
        gameover = 0;
        nb_life = 3;
        score = 0;
        timer = 0;
        bullet->tire = 0;
        positionAsteroid(list_big_asteroid);
        for (int i = 0; i < 24; i++) {
            if (i < 12) {
                list_medium_asteroid[i].speed = 0;
            }
            list_small_asteroid[i].speed = 0;
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfMouse_getPosition(window).x > 1250 && sfMouse_getPosition(window).x < 1500 && sfMouse_getPosition(window).y > 550 && sfMouse_getPosition(window).y < 750) {
        sfRenderWindow_close(window);
    }
}