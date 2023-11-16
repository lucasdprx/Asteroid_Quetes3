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

int create_menu() {
    texture_menu = sfTexture_createFromFile("Menu_Asteroid.png", NULL);
    shape_menu = sfRectangleShape_create();
    sfRectangleShape_setSize(shape_menu, (sfVector2f) { 800, 400 });
    sfRectangleShape_setTexture(shape_menu, texture_menu, NULL);
    sfRectangleShape_setFillColor(shape_menu, sfWhite);
}

int display_menu() {
    sfRectangleShape_setPosition(shape_menu, (sfVector2f) { 550, 300 });
    sfRenderWindow_drawRectangleShape(window, shape_menu, NULL);
}

int Button() {
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfMouse_getPosition(window).x > 750 && sfMouse_getPosition(window).x < 1200 && sfMouse_getPosition(window).y > 300 && sfMouse_getPosition(window).y < 400) {
        game = 1;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfMouse_getPosition(window).x > 550 && sfMouse_getPosition(window).x < 1400 && sfMouse_getPosition(window).y > 450 && sfMouse_getPosition(window).y < 550) {
        mode = 1;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfMouse_getPosition(window).x > 750 && sfMouse_getPosition(window).x < 1200 && sfMouse_getPosition(window).y > 600 && sfMouse_getPosition(window).y < 700) {
        sfRenderWindow_close(window);
    }
}
