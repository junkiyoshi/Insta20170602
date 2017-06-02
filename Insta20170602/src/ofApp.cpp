#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(120);
	ofSetWindowTitle("hex");

	this->size = 18;
	bool flg = true;
	for (float y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += this->size + this->size / 2) {
		for (float x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += this->size * sqrt(3)) {

			if (flg) {
				this->particles.push_back(Particle(ofVec3f(x, y, 0), this->size));
			} else {
				this->particles.push_back(Particle(ofVec3f(x + (this->size * sqrt(3) / 2), y, 0), this->size));
			}
		}
		flg = !flg;
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (Particle& p : this->particles) {
		p.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	
	float noise_value = 0.005;
	for (Particle& p : this->particles) {
		p.draw(ofNoise(p.location.x  * noise_value, p.location.y * noise_value, p.location.z * noise_value, ofGetFrameNum() * noise_value) * 255);
	}

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
