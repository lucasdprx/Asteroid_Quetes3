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

int create_score() {
    score_text = sfText_create();
    font = sfFont_createFromFile("pixelmix.ttf");
    sfText_scale(score_text, (sfVector2f) { 1, 1 });
    sfText_setFont(score_text, font);
}

int display_score() {
    char str_score[13];
    snprintf(str_score, 13, "Score : %d", score);
    sfText_setString(score_text, str_score);
}
