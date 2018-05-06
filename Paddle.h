//Paddle.h
//Jordan baxter

#pragma once

#include "ofMain.h"

class Paddle {
public:
	Paddle();
	void moveUp();
	void moveDown();
	void draw();
	void fire();
	int getLives();
	int getAmmo();

private:
	float x;
	float y;
	float h;
	float w;
	float s;
	int lives;
	int ammo;
	ofColor color;
};