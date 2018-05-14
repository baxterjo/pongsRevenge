//Bullet.h
//Jordan Baxter

#include"ofMain.h"

#pragma once
class Paddle;

class Bullet {
public:

	Bullet();
	void hit(Paddle* p);
	void miss();
	void move();
	void draw();
	float getTime();
	void fire(Paddle* p);

private:

	float x;
	float y;
	float vx;
	float r;
	float time;
	ofColor c;
};