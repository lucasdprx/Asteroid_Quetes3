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

int destroy_texture(struct Big_Asteroid list_big_asteroid[], struct Medium_Asteroid list_medium_asteroid[], struct Small_Asteroid list_small_asteroid[], struct Health life[]) {
    sfRectangleShape_destroy(shape2);
    sfCircleShape_destroy(shape);
    sfRenderWindow_destroy(window);
    sfTexture_destroy(texturevaisseau);
    sfTexture_destroy(textureasteroid);
    sfFont_destroy(font);
    sfFont_destroy(font2);
    sfText_destroy(score_text);
    sfText_destroy(timertext);
    sfTexture_destroy(texture_menu);
    sfRectangleShape_destroy(shape_menu);
    sfTexture_destroy(texture_game_over);
    sfRectangleShape_destroy(shape_game_over);

    for (int i = 0; i < 3; i++) {
        sfRectangleShape_destroy(life[i].shape);
    }
    for (int i = 0; i < nb_asteroid; i++) {
        sfRectangleShape_destroy(list_big_asteroid[i].shape);
    }
    for (int h = 0; h < (nb_asteroid * 2); h++) {
        sfRectangleShape_destroy(list_medium_asteroid[h].shape);
    }
    for (int h = 0; h < (nb_asteroid * 4); h++) {
        sfRectangleShape_destroy(list_small_asteroid[h].shape);
    }
}