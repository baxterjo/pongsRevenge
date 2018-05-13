//Paddle.cpp
//Jordan baxter

#include "Paddle.h"
#include "Ball.h"

Paddle::Paddle(int x) {
	this->x = x;
	this->y = ofGetHeight() / 2;
	this->h = ofGetHeight() / 10;
	this->w = ofGetWidth() / 150;
	this->s = ofGetHeight() * .01;
	this->lives = 3;
	this->ammo = 0;
	this->color = ofColor(255, 255, 255);
};

void Paddle::moveUp(){
	if (this->y > 0) {
		this->y -= this->s;
	}	
}

void Paddle::moveDown() {
	if (this->y + this->h < ofGetHeight()) {
		this->y += this->s;
	}
}

void Paddle::draw() {
	ofSetColor(this->color);
	ofDrawRectangle(this->x, this->y, this->w, this->h);
}

void Paddle::fire() {
	//TODO
	this->ammo -= 1;
}

void Paddle::trackBall(vector<Ball*> balls) {
	Ball* closest = balls[0];
	int chance = ofRandom(100);
	for (int i = 0; i < balls.size(); ++i) {
		if (balls[i]->getX() > closest->getX()) {
			closest = balls[i];
		}
	}
	this->y = closest->getY() - this->h/2;
	
}

void Paddle::trackMouse(float y) {
	this->y = y - this->h/2;
}

void Paddle::leftResize() {
	this->w = ofGetWidth() / 150;
	this->h = ofGetHeight() / 15;
	this->s = ofGetHeight() * .01;
}

void Paddle::rightResize() {
	this->w = ofGetWidth() / 150;
	this->h = ofGetHeight() / 15;
	this->x = ofGetWidth() - ofGetWidth() / 150 - 20;
}

void Paddle::changeLives(int n) {
	this->lives += n;
}

int Paddle::getLives() {
	return this->lives;
}

int Paddle::getAmmo() {
	return this->ammo;
}

int Paddle::getX() {
	return this->x;
}

int Paddle::getY() {
	return this->y;

}

int Paddle::getW() {
	return this->w;
}

int Paddle::getH() {
	return this->h;
}