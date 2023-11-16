#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "Window.h"

int create_window() {
	sfVideoMode mode = { 1920, 1080, 32 };
	window = sfRenderWindow_create(mode, "Asteroids", sfFullscreen, NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
}