//Paddle.cpp
//Jordan baxter

#include "Paddle.h"
#include "Ball.h"

Paddle::Paddle(int x) {
	this->x = x;
	this->y = ofGetHeight() / 2;
	this->h = ofGetHeight() / 10;
	this->w = ofGetWidth() / 150;
	this->s = 10;
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
	if (chance > 50) {
		if (closest->getY() < this->y + ofRandom(this->getH())) {
			this->moveUp();
		}
		else {
			this->moveDown();
		}
	}
	
}

void Paddle::changeSize() {
	this->w = ofGetWidth() / 150;
	this->h = ofGetHeight() / 15;
}

void Paddle::changeX() {
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