//Hud.cpp
//Jordan Baxter

#include "Hud.h"
#include "ofApp.h"

Hud::Hud() {
	this->state = "start";
	this->score = 0;
	this->hiScore = 0; //TODO;
	this->color = ofColor(255, 255, 255);
	this->titleFont.load("Act_Of_Rejection.ttf", ofGetWidth() / 10, true, true);
	this->gameFont.load("Act_Of_Rejection.ttf", 24, true, true);
}

void Hud::changeState(string s) {
	this->state = s;
}

string Hud::getState() {
	return this->state;
}

void Hud::draw() {
	ofSetColor(this->color);
	if (this->state == "start") {
		Hud::drawStart();

	}
	else if (this->state == "play") {
		Hud::drawPlay();
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
	this->gameFont.drawString("Press ENTER to get revenge!", ofGetWidth() / 2 - titleFont.stringWidth("Press enter to get revenge!") / 5 - 2, ofGetHeight() * (3 / 2) - titleFont.stringHeight("Press enter to get revenge!") / 2);
	this->gameFont.drawString("Press ENTER to get revenge!", ofGetWidth() / 2 - titleFont.stringWidth("Press enter to get revenge!") / 5 + 2, ofGetHeight() * (3 / 2) - titleFont.stringHeight("Press enter to get revenge!") / 2);
	this->gameFont.drawString("Press ENTER to get revenge!", ofGetWidth() / 2 - titleFont.stringWidth("Press enter to get revenge!") / 5, ofGetHeight() * (3 / 2) - titleFont.stringHeight("Press enter to get revenge!") / 2 + 2);
	this->gameFont.drawString("Press ENTER to get revenge!", ofGetWidth() / 2 - titleFont.stringWidth("Press enter to get revenge!") / 5, ofGetHeight() * (3 / 2) - titleFont.stringHeight("Press enter to get revenge!") / 2 - 2);
	ofSetColor(227, 15, 15);
	this->gameFont.drawString("Press ENTER to get revenge!", ofGetWidth() / 2 - titleFont.stringWidth("Press enter to get revenge!") / 5, ofGetHeight() * (3 / 2) - titleFont.stringHeight("Press enter to get revenge!") / 2);
}

void Hud::drawPlay() {
	ofSetColor(this->color);
	this->drawCenterLine(ofGetHeight());
}

void Hud::drawCenterLine(int bottom) {
	int dashLength = bottom / 30;  
	int dashWidth = ofGetWidth() / 200;
	for (int i = 0; i < bottom; i += dashLength * 2) {
		ofDrawRectangle(ofGetWidth() / 2 - dashWidth / 2, i, dashWidth, dashLength);
	}
}

void Hud::resize() {
	this->titleFont.load("Act_Of_Rejection.ttf", ofGetWidth() / 10, true, true);
	this->gameFont.load("Act_Of_Rejection.ttf", ofGetWidth() / 30, true, true);
}