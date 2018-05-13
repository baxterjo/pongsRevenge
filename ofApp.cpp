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
	hud = new Hud();
	p1 = new Paddle(20);
	p2 = new Paddle(ofGetWidth() - ofGetWidth() / 150 - 20);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (hud->getState() == "play") {
		for (int i = 0; i < balls.size(); ++i) {
			if (!balls.empty()) {
				balls[i]->move();
				balls[i]->hitLeftPaddle(p1, hud);
				balls[i]->hitRightPaddle(p2);
				balls[i]->hitLeftGoal(p1);
				balls[i]->hitRightGoal(hud);
				balls[i]->hitWall();
				p2->trackBall(balls);
			}
		}
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
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RETURN && hud->getState() == "start") {
		hud->changeState("play");
		balls.push_back(new Ball());
	}
	else if (hud->getState() == "play") {
		
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
