#include "ofApp.h"
#include <wiringPi.h>
#define WHEEL_SENSOR_PIN 7
#define TOTAL_FRAMES 3

ofImage frame[TOTAL_FRAMES];
int currentFrame = 0;


//--------------------------------------------------------------
void ofApp::setup(){
	for (int i = 0; i++; i < TOTAL_FRAMES) {
		string filename = "Frame" + ofToString(i) + ".png";
		frame[i].loadImage(filename);
	}

	wiringPiSetup();
	pinMode(WHEEL_SENSOR_PIN, INPUT);
	wiringPiISR (WHEEL_SENSOR_PIN, INT_EDGE_FALLING, &incrementFrame);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	if (digitalRead(WHEEL_SENSOR_PIN) == HIGH) {
		frame[currentFrame].draw(0,0);
	}
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