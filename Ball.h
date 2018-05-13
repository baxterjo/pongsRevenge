//Ball.h
//Jordan Baxter

#pragma once

#include "ofMain.h"
class Paddle;
class Hud;

class Ball {
public:
	Ball();
	Ball(float x, float y, float r, float s, ofColor c);
	void move();
	void draw();
	void hitWall();
	void hitLeftPaddle(Paddle* p, Hud* h);
	void hitRightPaddle(Paddle* p);
	void hitLeftGoal(Paddle* p);
	void hitRightGoal(Hud* hud);
	int random();
	float getX();
	float getY();

private:
	float x;
	float y;
	float r;
	float vx;
	float vy;
	ofColor color;
	float t;

};