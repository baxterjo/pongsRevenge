//Hud.cpp
//Jordan Baxter

#include "Hud.h"

Hud::Hud() {
	this->state = "start";
	this->score = 0;
	this->hiScore = 0; //TODO;
	this->color = ofColor(255, 255, 255);
	this->titleFont.load("Act_Of_Rejection.ttf", ofGetWidth() / 5, true, true);
	this->gameFont.load("Act_Of_Rejection.ttf", 24, true, true);
}

void Hud::changeState(string s) {
	this->state = s;
}

void Hud::draw() {
	ofSetColor(this->color);
	if (this->state == "start") {


	}
}