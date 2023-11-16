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

int create_timer() {
    timertext = sfText_create();
    font2 = sfFont_createFromFile("pixelmix.ttf");
    sfText_scale(timertext, (sfVector2f) { 1, 1 });
    sfText_setFont(timertext, font);
    sfText_setFillColor(timertext, sfWhite);
}

int display_timer() {
    char str_timer[13];
    snprintf(str_timer, 13, "Timer : %f", timer);
    sfText_setString(timertext, str_timer);

    timer += 1.0f / 60 ;
}