//Ball.h
//Jordan Baxter

#pragma once

#include "ofMain.h"

class Ball {
public:
	Ball();
	Ball(float x, float y, float r, float s, ofColor c);
	void move();
	void draw();
	void hitWall();
	void hitPaddle();
	void hitGoal();

private:
	float x;
	float y;
	float r;
	float sx;
	float sy;
	ofColor color;

};