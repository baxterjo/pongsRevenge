//Bullet.cpp
//Jordan Baxter

#include "Bullet.h"
#include "Paddle.h"
#include "ofMain.h"

Bullet::Bullet() {
	this->x = 1;
	this->y = -2;
	this->vx = 0;
	this->r = 2;
	this->c = ofColor(255, 45, 0);
	this->time = 0;
}

void Bullet::hit(Paddle* p) {
	if (this->x + this->r > p->getX() && this->y > p->getY() && this->y < p->getY() + p->getH()) {
		p->changeTime(ofGetElapsedTimef());
		this->y = -2;
		this->vx = 0;
	}
}

void Bullet::miss() {
	if (this->x > (ofGetWidth() + this->r)) {
		this->y = -2;
		this->vx = 0;
	}
}

void Bullet::move() {
	this->x += vx;
}

void Bullet::draw() {
	ofSetColor(this->c);
	ofDrawCircle(this->x,this->y,this->r);
}

float Bullet::getTime() {
	return this->time;
}

void Bullet::fire(Paddle* p) {
	this->x = p->getX();
	this->y = p->getY() + p->getH() / 2;
	this->vx = 10;
}