#pragma once

struct  Shoot {
	float directionX;
	float directionY;
	float x;
	float y;
	int tire;
	int timer;
};

int colisionShoot(bullet, list_big_asteroid);
int colisionShoot_medium(bullet, list_medium_asteroid);
int colisionShoot_small(bullet, list_small_asteroid);
int Shoot(player, bullet);
