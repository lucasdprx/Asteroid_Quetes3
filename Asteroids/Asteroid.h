#pragma once


struct Big_Asteroid
{
    sfRectangleShape* shape;
    float x;
    float y;
    float speed;
    float directionAX;
    float directionAY;
};

struct Medium_Asteroid
{
    sfRectangleShape* shape;
    float x;
    float y;
    float speed;
    float directionAX;
    float directionAY;

};

struct Small_Asteroid
{
    sfRectangleShape* shape;
    float x;
    float y;
    float speed;
    float directionAX;
    float directionAY;
};

int nb_asteroid;
int respawn;
int level;

int nbasteroid();
int positionAsteroid(list_big_asteroid);
int mouv_asteroid(list_big_asteroid);
int mouv_asteroid_medium(list_medium_asteroid);
int mouv_asteroid_small(list_small_asteroid);
int positionAsteroid_medium(bullet, list_big_asteroid, list_medium_asteroid);
int positionAsteroid_small(bullet, list_medium_asteroid, list_small_asteroid);
int drawAsteroid(list_big_asteroid, list_medium_asteroid, list_small_asteroid);
int respawn_asteroid(list_big_asteroid);