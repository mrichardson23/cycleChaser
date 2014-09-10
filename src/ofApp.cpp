#include "ofApp.h"
#include <wiringPi.h>
#define WHEEL_SENSOR_PIN 7
#define TOTAL_FRAMES 3

ofImage frame[TOTAL_FRAMES];
int currentFrame = 0;
int framePositionX;
int framePositionY;

//--------------------------------------------------------------
void ofApp::setup(){
	for (int i = 0; i < TOTAL_FRAMES; i++) {
		string filename = "Frame" + ofToString(i) + ".png";
		if (frame[i].loadImage(filename)) {
			ofLog(OF_LOG_NOTICE, "Loaded frame file: " + filename);
		}
		else {
			ofLog(OF_LOG_ERROR, "Unable to load frame file: " + filename);
		}
	}
	int frameWidth = frame[0].getWidth();
	int frameHeight = frame[0].getHeight();

	framePositionX = (ofGetWidth()/2) - (frameWidth/2);
	framePositionY = (ofGetHeight()/2) - (frameHeight/2);

	wiringPiSetup();
	pinMode(WHEEL_SENSOR_PIN, INPUT);
	wiringPiISR (WHEEL_SENSOR_PIN, INT_EDGE_FALLING, &incrementFrame);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	frame[currentFrame].draw(framePositionX,framePositionY);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

void incrementFrame () {
	if (currentFrame < TOTAL_FRAMES - 1) {
		currentFrame++;
	}
	else {
		currentFrame = 0;
	}
	ofLog(OF_LOG_NOTICE, "currentFrame: %d", currentFrame);
}