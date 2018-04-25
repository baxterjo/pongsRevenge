//Ball.cpp
//Jordan Baxter


#include "Ball.h"
#include "ofMain.h"


Ball::Ball() {
	this->x = ofGetWidth() / 2;
	this->y = ofGetHeight() / 2;
	this->r = 5;
	this->sx = 5;
	this->sy = 5;
	this->color = ofColor(255, 255, 255);
};

Ball::Ball(float x, float y, float r, float s, ofColor c){
	this->x = x;
	this->y = y;
	this->r = r;
	this->sx = s;
	this->sy = s;
	this->color = c;
};

void Ball::move() {
	this->x += this->sx;
	this->y += this->sy;
}

void Ball::draw() {
	ofSetColor(this->color);
	ofCircle(ofGetWidth() / 2 + this->x, ofGetHeight() / 2 + this->y, this->r);
}

void Ball::hitWall() {
	if (this->y == (0 + this->r) || this->y == (ofGetHeight() - this->r)) {
		this->sy *= -1;
	}
}

void Ball::hitPaddle() {
	/* TODO: if(ball hits paddle){
		this->sx *= -1.01

	Try decaying exponential function here, to reach max possible speed and hold.*/
}

void Ball :: hitGoal() {
	if (this->x == (0 - this->r) || this->x == (ofGetWidth() + this->r)) {

	}
}


