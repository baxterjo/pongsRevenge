//Paddle.h
//Jordan baxter

#pragma once

#include "ofMain.h"

class Paddle {
	public:
		Paddle();
		void move();
		void draw();
		void fire();

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