//Paddle.cpp
//Jordan baxter

#include "Paddle.h"

Paddle::Paddle() {
	this->x = 20;
	this->y = ofGetHeight() / 2;
	this->h = 30;
	this->w = 5;
	this->s = 5;
	this->lives = 3;
	this->ammo = 0;
	this->color = ofColor(255, 255, 255);
};