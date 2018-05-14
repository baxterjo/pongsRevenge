//Hud.h
//Jordan Baxter

#pragma once

#include "ofMain.h"
class Paddle;

class Hud {
public:
	Hud();
	void changeState(string s);
	string getState();
	void draw(Paddle* p);
	void drawStart();
	void drawPlay(Paddle* p);
	void drawEnd();
	void drawCenterLine(int bottom);
	void drawScore();
	void drawLives(Paddle* p);
	void drawAmmo(Paddle* p);
	void changeScore(int x);
	void changeHiScore(int x);
	void resize();
	int getScore();
	int getHiScore();


private:
	string state;
	int score;
	int hiScore; 
	ofColor color;
	ofTrueTypeFont titleFont;
	ofTrueTypeFont subtitleFont;
	ofTrueTypeFont gameFont;
};