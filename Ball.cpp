//Ball.cpp
//Jordan Baxter


#include "Ball.h"
#include "ofMain.h"
#include "Paddle.h"
#include "Hud.h"
#include <math.h>


Ball::Ball() {
	this->x = ofGetWidth() / 2;
	this->y = ofGetHeight() / 2;
	this->r = 5;
	this->vx = 1 * ofRandom(-1,1);
	this->vy = ofRandom(-1,1) * ofNoise(1) * 1;
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

Ball::~Ball() {

}

void Ball::move() {
	this->x += this->vx;
	this->y += this->vy;
}

void Ball::draw() {
	ofSetColor(this->color);
	ofCircle(this->x,this->y, this->r);
}

void Ball::hitWall() {
	if (this->y == (0 + this->r) || this->y == (ofGetHeight() - this->r)) {
		this->vy *= -1;
	}
}

void Ball::hitLeftPaddle(Paddle* p) {
	if (this->x - this->r == p->getX() + p->getW() && this->y > p->getY() && this->y < p->getY() + p->getH()) {
		this->vx *= -1;
		this->t += .01;
	}
}

void Ball::hitRightPaddle(Paddle* p){
	if (this->x + this->r == p->getX() && this->y > p->getY() && this->y < p->getY() + p->getH()) {
		this->vx = -1 + (2.5 / (1 + exp(-.5*(this->t - 3))));
		this->t += .01;
	}
}

void Ball :: hitLeftGoal(Paddle* p) {
	if (this->x == (0 - this->r)) {
		p->changeLives(-1);
		this->~Ball();
	}
}

void Ball::hitRightGoal(Hud* hud) {
	if (this->x == (ofGetWidth() + this->r)) {
		hud->changeScore(100);
		this->~Ball();
	}
}

float Ball::getX() {
	return this->x;
}

float Ball::getY() {
	return this->y;
}
