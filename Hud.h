//Hud.h
//Jordan Baxter

#pragma once

#include "ofMain.h"

class Hud {
public:
	Hud();
	void changeState(string s);
	string getState();
	void draw();
	void drawStart();
	void drawPlay();
	//void drawEnd();
	void drawCenterLine(int bottom);
	void resize();

private:
	string state;
	int score;
	int hiScore;
	ofColor color;
	ofTrueTypeFont titleFont;
	ofTrueTypeFont gameFont;
};