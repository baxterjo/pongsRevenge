//Hud.h
//Jordan Baxter

#pragma once

#include "ofMain.h"

class Hud {
public:
	Hud();
	void changeState(string s);
	void draw();

private:
	string state;
	int score;
	int hiScore;
	ofColor color;
	ofTrueTypeFont titleFont;
	ofTrueTypeFont gameFont;
};