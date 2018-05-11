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
	~Ball();
	void move();
	void draw();
	void hitWall();
	void hitLeftPaddle(Paddle* p);
	void hitRightPaddle(Paddle* p);
	void hitLeftGoal(Paddle* p);
	void hitRightGoal(Hud* hud);
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