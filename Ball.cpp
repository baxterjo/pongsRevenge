//Ball.cpp
//Jordan Baxter


#include "Ball.h"
#include "ofMain.h"
#include "Paddle.h"
#include <math.h>


Ball::Ball() {
	this->x = ofGetWidth() / 2;
	this->y = ofGetHeight() / 2;
	this->r = 5;
	this->vx = 5 * ofRandom(-1,1);
	this->vy = ofRandom(-1,1) * ofNoise(1) * 5;
	this->color = ofColor(255, 255, 255);
	this->t = 0;
};

Ball::Ball(float x, float y, float r, float s, ofColor c){
	this->x = x;
	this->y = y;
	this->r = r;
	this->vx = s;
	this->vy = s;
	this->color = c;
};

void Ball::move() {
	this->x += this->vx;
	this->y += this->vy;
}

void Ball::draw() {
	ofSetColor(this->color);
	ofCircle(ofGetWidth() / 2 + this->x, ofGetHeight() / 2 + this->y, this->r);
}

void Ball::hitWall() {
	if (this->y == (0 + this->r) || this->y == (ofGetHeight() - this->r)) {
		this->vy *= -1;
	}
}

void Ball::hitLeftPaddle(Paddle* p) {
	if (this->x + this->r == p->getX() + p->getW()) {
		this->vx = 1 + (10 / (1 + exp(-.5*(this->t - 3))));
		this->t += .01;
	}
}

void Ball::hitRightPaddle(Paddle* p){

}

void Ball :: hitLeftGoal() {
	if (this->x == (0 - this->r) || this->x == (ofGetWidth() + this->r)) {

	}
}


