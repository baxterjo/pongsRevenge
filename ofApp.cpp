//ofApp.cpp
//Jordan Baxter

#include "ofApp.h"
#include "Hud.h"
#include "Ball.h"
#include "Paddle.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0,0,0);
	hiScore.open("hiScore.txt");
	hiScore >> hiScoreString;
	hiScore.close();
	hud = new Hud();
	hud->changeHiScore(ofToInt(hiScoreString));
	p1 = new Paddle(20);
	p2 = new Paddle(ofGetWidth() - ofGetWidth() / 150 - 20);
	for (int i = 0; i < 5; ++i) {
		bullets.push_back(new Bullet());
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	if (hud->getState() == "play") {
		for (int i = 0; i < balls.size(); ++i) {
			balls[i]->move();
			balls[i]->hitLeftPaddle(p1, hud);
			balls[i]->hitRightPaddle(p2);
			balls[i]->hitRightGoal(p1, hud, &balls);
			balls[i]->hitWall();
			p2->trackBall(balls);
			balls[i]->hitLeftGoal(p1,hud, &balls);
		}
		for (int i = 0; i < bullets.size(); ++i) {
			bullets[i]->move();
			bullets[i]->hit(p2);
			bullets[i]->miss();
		}
	}
	else if (hud->getState() == "end" && hud->getScore() > hud->getHiScore()) {
		hiScore.open(ofToDataPath("hiScore.txt"),ofFile::ReadWrite, false);
		hiScore << ofToString(hud->getScore());
		hiScore.close();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	hud->draw(p1);
	if (hud->getState() == "play") {
		p1->draw();
		p2->draw();
		for (int i = 0; i < balls.size(); ++i) {
			balls[i]->draw();
		}
		for (int i = 0; i < bullets.size(); ++i) {
			bullets[i]->draw();
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RETURN && hud->getState() == "start") {
		balls.push_back(new Ball());
		hud->changeState("play");
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	p1->trackMouse(y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (p1->getAmmo() > 0) {
		p1->fire(bullets);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	hud->resize();
	p1->leftResize();
	p2->rightResize();
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
