#include "ofApp.h"


float SpeedX, SpeedY;
ofColor grey = (246, 247, 235);
ofColor orang = (233, 79, 55);
ofColor lblue = (124, 198, 254);
float currentTime = 0;


//--------------------------------------------------------------
void ofApp::setup(){
    

    ofSetFrameRate(60);
    

    
    SpeedX = ofGetFrameNum()-currentTime;
    SpeedY = ofGetFrameNum()-currentTime;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(grey);
    float W = ofGetWidth();
    float H = ofGetHeight();

    for (int i=-10000; i<W; i+=70){
        for(int o=-10000; o<H; o+=70){
            ofSetColor(233, 79, 55);
            ofDrawCircle(i+(ofGetFrameNum())*30, o+(ofGetFrameNum())*20, 27);
        }
    }
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
