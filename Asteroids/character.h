#pragma once

struct Player
{
    float x;
    float y;
    float directionX;
    float directionY;
    float speed;
    float angle;
};

int timer_life;
int mouv(player);
int colisionShip(player, list_big_asteroid);
int colisionShip_medium(player, list_medium_asteroid);
int colisionShip_small(player, list_small_asteroid);
