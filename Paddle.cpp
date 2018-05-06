//Paddle.cpp
//Jordan baxter

#include "Paddle.h"

Paddle::Paddle() {
	this->x = 20;
	this->y = ofGetHeight() / 2;
	this->h = 30;
	this->w = 5;
	this->s = 5;
	this->lives = 3;
	this->ammo = 0;
	this->color = ofColor(255, 255, 255);
};

void Paddle::moveUp(){
	this->y -= this->s;
}

void Paddle::moveDown() {
	this->y += this->s;
}

void Paddle::draw() {
	ofSetColor(this->color);
	ofDrawRectangle(this->x, this->y, this->w, this->h);
}

int Paddle::getLives() {
	return this->lives;
}

int Paddle::getAmmo() {
	return this->ammo;
}

void Paddle::fire() {
	//TODO
	this->ammo -= 1;
}