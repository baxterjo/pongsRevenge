//Ball.h
//Jordan Baxter

#pragma once

#include "ofMain.h"
class Paddle;

class Ball {
public:
	Ball();
	Ball(float x, float y, float r, float s, ofColor c);
	void move();
	void draw();
	void hitWall();
	void hitLeftPaddle(Paddle* p);
	void hitRightPaddle(Paddle* p);
	void hitLeftGoal();
	void hitRightGoal();

private:
	float x;
	float y;
	float r;
	float vx;
	float vy;
	ofColor color;
	float t;

};