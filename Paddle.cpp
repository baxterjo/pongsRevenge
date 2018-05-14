//Paddle.cpp
//Jordan baxter

#include "Paddle.h"
#include "Ball.h"
#include "Bullet.h"

Paddle::Paddle(int x) {
	this->x = x;
	this->y = ofGetHeight() / 2;
	this->h = ofGetHeight() / 10;
	this->w = ofGetWidth() / 150;
	this->s = ofGetHeight() * .01;
	this->lives = 4;
	this->ammo = 0;
	this->color = ofColor(255, 255, 255);
	this->state = "free";
	this->time = 0;
};


void Paddle::draw() {
	ofSetColor(this->color);
	ofDrawRectangle(this->x, this->y, this->w, this->h);
}

void Paddle::moveUp() {
	this->y -= this->s;
}

void Paddle::moveDown() {
	this->y += this->s;
}

void Paddle::fire(vector<Bullet*> b) {
	b[this->ammo]->fire(this);
	this->ammo -= 1;
}

void Paddle::trackBall(vector<Ball*> balls) {
	Ball* closest = balls[0];
	for (int i = 0; i < balls.size(); ++i) {
		if (balls[i]->getX() > closest->getX()) {
			closest = balls[i];
		}
	}
	if (this->state == "free") {
		this->y = closest->getY() - this->h / 2;
	}
}
void Paddle::trackMouse(float y) {
	this->y = y - this->h/2;
}

void Paddle::leftResize() {
	this->w = ofGetWidth() / 150;
	this->h = ofGetHeight() / 15;
}

void Paddle::rightResize() {
	this->w = ofGetWidth() / 150;
	this->h = ofGetHeight() / 15;
	this->x = ofGetWidth() - ofGetWidth() / 150 - 20;
}

void Paddle::changeLives(int n) {
	this->lives += n;
}

void Paddle::changeAmmo(int n) {
	this->ammo += n;
}

void Paddle::frozen() {
	if (this->time < ofGetElapsedTimef() - 100) {
		this->state = "frozen";
	}
	else {
		this->state = "free";
	}
}

void Paddle::changeTime(float t) {
	this->time = t;
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