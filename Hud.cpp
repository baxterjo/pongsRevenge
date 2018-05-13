//Hud.cpp
//Jordan Baxter

#include "Hud.h"
#include "ofApp.h"

Hud::Hud() {
	this->state = "start";
	this->score = 0;
	this->hiScore = 0; //TODO;
	this->color = ofColor(255, 255, 255);
	this->titleFont.load("Act_of_Rejection.ttf", ofGetWidth() / 10, true, true);
	this->subtitleFont.load("Act_of_Rejection.ttf", ofGetWidth() / 30, true, true);
	this->gameFont.load("Stay_On_The_Ground_Grunge.ttf", ofGetWidth() / 40, true, true);
}

void Hud::changeState(string s) {
	this->state = s;
}

string Hud::getState() {
	return this->state;
}

void Hud::draw(Paddle* p) {
	ofSetColor(this->color);
	if (this->state == "start") {
		Hud::drawStart();

	}
	else if (this->state == "play") {
		Hud::drawPlay(p);
	}
	else if (this->state == "end") {
		//Hud::drawEnd();
	}
}

void Hud::drawStart() {
	ofSetColor(255);
	this->titleFont.drawString("Pong's Revenge!", ofGetWidth() / 2 - titleFont.stringWidth("Pong's Revenge!") / 2 - 2, ofGetHeight() / 2 - titleFont.stringHeight("Pong's Revenge!") / 2);
	this->titleFont.drawString("Pong's Revenge!", ofGetWidth() / 2 - titleFont.stringWidth("Pong's Revenge!") / 2 + 2, ofGetHeight() / 2 - titleFont.stringHeight("Pong's Revenge!") / 2);
	this->titleFont.drawString("Pong's Revenge!", ofGetWidth() / 2 - titleFont.stringWidth("Pong's Revenge!") / 2, ofGetHeight() / 2 - titleFont.stringHeight("Pong's Revenge!") / 2 - 2);
	this->titleFont.drawString("Pong's Revenge!", ofGetWidth() / 2 - titleFont.stringWidth("Pong's Revenge!") / 2, ofGetHeight() / 2 - titleFont.stringHeight("Pong's Revenge!") / 2 + 2);
	ofSetColor(227, 15, 15);
	this->titleFont.drawString("Pong's Revenge!", ofGetWidth() / 2 - titleFont.stringWidth("Pong's Revenge!") / 2, ofGetHeight() / 2 - titleFont.stringHeight("Pong's Revenge!") / 2);

	ofSetColor(255);
	this->subtitleFont.drawString("Press ENTER to get revenge!", ofGetWidth() / 2 - subtitleFont.stringWidth("Press enter to get revenge!") / 2 - 2, ofGetHeight() * (3 / 2) - subtitleFont.stringHeight("Press enter to get revenge!") / 2);
	this->subtitleFont.drawString("Press ENTER to get revenge!", ofGetWidth() / 2 - subtitleFont.stringWidth("Press enter to get revenge!") / 2 + 2, ofGetHeight() * (3 / 2) - subtitleFont.stringHeight("Press enter to get revenge!") / 2);
	this->subtitleFont.drawString("Press ENTER to get revenge!", ofGetWidth() / 2 - subtitleFont.stringWidth("Press enter to get revenge!") / 2, ofGetHeight() * (3 / 2) - subtitleFont.stringHeight("Press enter to get revenge!") / 2 + 2);
	this->subtitleFont.drawString("Press ENTER to get revenge!", ofGetWidth() / 2 - subtitleFont.stringWidth("Press enter to get revenge!") / 2, ofGetHeight() * (3 / 2) - subtitleFont.stringHeight("Press enter to get revenge!") / 2 - 2);
	ofSetColor(227, 15, 15);
	this->subtitleFont.drawString("Press ENTER to get revenge!", ofGetWidth() / 2 - subtitleFont.stringWidth("Press enter to get revenge!") / 2, ofGetHeight() * (3 / 2) - subtitleFont.stringHeight("Press enter to get revenge!") / 2);
}

void Hud::drawPlay(Paddle* p) {
	ofSetColor(this->color);
	this->drawCenterLine(ofGetHeight());
	this->drawScore();
	this->drawLives(p);
	this->drawAmmo(p);
}

void Hud::drawCenterLine(int bottom) {
	int dashLength = bottom / 30;  
	int dashWidth = ofGetWidth() / 200;
	for (int i = 0; i < bottom; i += dashLength * 2) {
		ofDrawRectangle(ofGetWidth() / 2 - dashWidth / 2, i, dashWidth, dashLength);
	}
}

void Hud::drawScore() {
	ofSetColor(255);
	this->gameFont.drawString("Score  " + ofToString(this->score), ofGetWidth() * .75 - gameFont.stringWidth("Score  " + ofToString(this->score)) / 2, 10 + gameFont.stringHeight("Score  " + ofToString(this->score)));
}

void Hud::drawLives(Paddle* p) {
	this->gameFont.drawString("Lives  " + ofToString(p->getLives()), ofGetWidth() * .125 - gameFont.stringWidth("Lives  " + ofToString(p->getLives())) / 2, 10 + gameFont.stringHeight("Lives  " + ofToString(p->getLives())));
}

void Hud::drawAmmo(Paddle* p) {
	this->gameFont.drawString("Ammo  " + ofToString(p->getAmmo()), ofGetWidth() * .25, 10 + gameFont.stringHeight("Ammo  " + ofToString(p->getAmmo())));
}

void Hud::changeScore(int x) {
	this->score += x;
}

void Hud::resize() {
	this->titleFont.load("Act_of_Rejection.ttf", ofGetWidth() / 10, true, true);
	this->subtitleFont.load("Act_of_Rejection.ttf", ofGetWidth() / 30, true, true);
	this->gameFont.load("Stay_On_The_Ground_Grunge.ttf", ofGetWidth() / 40, true, true);
}

int Hud::getScore() {
	return this->score;
}