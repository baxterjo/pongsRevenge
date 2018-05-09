//Paddle.h
//Jordan baxter

#pragma once

#include "ofMain.h"
class Ball;

class Paddle {
public:
	Paddle(int x);
	void moveUp();
	void moveDown();
	void draw();
	void fire();
	void trackBall(Ball* b);
	void changeSize();
	void changeX();
	int getLives();
	int getAmmo();
	int getX();
	int getY();
	int getW();
	int getH();

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