//Paddle.h
//Jordan baxter

#pragma once

#include "ofMain.h"
class Ball;
class Bullet;

class Paddle {
public:
	Paddle(int x);
	void draw();
	void moveUp();
	void moveDown();
	void fire(vector<Bullet*> b);
	void trackBall(vector<Ball*> balls);
	void trackMouse(float y);
	void leftResize();
	void rightResize();
	void changeLives(int n);
	void changeAmmo(int n);
	void frozen();
	void changeTime(float t);
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
	float time;
	ofColor color;
	string state;
};