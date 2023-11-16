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
#include "Menu.h"

int display_life(struct Health life[]) {
    for (int i = 0; i < nb_life; i++) {
        sfRenderWindow_drawRectangleShape(window, life[i].shape, NULL);
    }
}

int nblife() {
    nb_life = 3;
}