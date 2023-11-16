#pragma once

sfFont* font;
sfText* score_text;
int score;

struct Score {
	float x;
	float y;
};

int display_score();
int create_score();