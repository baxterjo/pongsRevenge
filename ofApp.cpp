#include "ofApp.h"
#include "Hud.h"
#include "Ball.h"
#include "Paddle.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0,0,0);
	hud = new Hud();
	p1 = new Paddle(20);
	p2 = new Paddle(ofGetWidth() - ofGetWidth() / 150 - 20);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (hud->getState() == "play") {

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	hud->draw(p1);
	if (hud->getState() == "play") {
		p1->draw();
		p2->draw();
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RETURN && hud->getState() == "start") {
		hud->changeState("play");
		//balls.insert(delaySpawn());
	}
	else if (hud->getState() == "play") {
		if (key == 'w') {
			p1->moveUp();
		}
		else if (key == 's') {
			p1->moveDown();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
	p1->changeSize();
	p2->changeSize();
	p2->changeX();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
