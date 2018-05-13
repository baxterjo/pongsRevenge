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
	void trackBall(vector<Ball*> balls);
	void trackMouse(float y);
	void leftResize();
	void rightResize();
	void changeLives(int n);
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