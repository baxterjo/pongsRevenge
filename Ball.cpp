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
	this->vx = ofGetWidth() * .005 * this->random();
	this->vy = this->random() * ofNoise(1) * ofGetHeight() * .01;
	this->color = ofColor(255, 255, 255);
	this->t = 1;
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
	if (this->y < (0 + this->r) || this->y > (ofGetHeight() - this->r)) {
		this->vy *= -1;
	}
}

void Ball::hitLeftPaddle(Paddle* p, Hud* h) {
	if (this->x - this->r < p->getX() + p->getW() && this->y > p->getY() && this->y < p->getY() + p->getH()) {
		this->vx =((ofGetWidth() * .01) / (1 + exp(-1*(this->t - 1))));
		this->t += .1;
		h->changeScore(10);
		this->vy += ofMap(this->y, p->getY(), p->getY() + p->getH(), ofGetHeight() * -.01, ofGetHeight() * .01);
		if (h->getScore() % 50 == 0) {
			p->changeAmmo(1);
		}
	}
}

void Ball::hitRightPaddle(Paddle* p){
	if (this->x + this->r > p->getX() && this->y > p->getY() && this->y < p->getY() + p->getH()) {
		this->vx = -1 * ((ofGetWidth() * .010) / (1 + exp(-1*(this->t - 1))));
		this->t += .1;
	}
}

void Ball :: hitLeftGoal(Paddle* p, Hud* hud, vector<Ball*>* balls) {
	if (this->x < (0 - this->r)) {
		if (balls->size() == 1) {
			p->changeLives(-1);
			this->x = ofGetWidth() / 2;
			this->y = ofGetHeight() / 2;
			this->vx = ofGetWidth() * .005 * this->random();
			this->vy = this->random() * ofNoise(1) * 2;
		}
		else {
			
		}
		if (p->getLives() == 0) {
			hud->changeState("end");
		}
	}	
}

void Ball::hitRightGoal(Paddle* p, Hud* hud, vector<Ball*>* balls) {
	if (this->x > (ofGetWidth() + this->r)) {
		if (balls->size() == 1) {
			hud->changeScore(100);
			this->x = ofGetWidth() / 2;
			this->y = ofGetHeight() / 2;
			this->vx = ofGetWidth() * .005 * this->random();
			this->vy = this->random() * ofNoise(1) * 2;
			if (p->getLives() == 4) {
				balls->push_back(new Ball());
			}
			else {
				p->changeLives(1);
			}
		} 
		else {
			hud->changeScore(100);
			if (p->getLives() == 4) {
				balls->push_back(new Ball());
			}
			else {
				p->changeLives(1);
			}
			delete this;
		}

	}
}


int Ball::random() {
	if (rand() % 2 == 1) {
		return -1;
	}
	else {
		return 1;
	}
}

float Ball::getX() {
	return this->x;
}

float Ball::getY() {
	return this->y;
}
