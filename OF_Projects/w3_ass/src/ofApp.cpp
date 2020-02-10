#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
 
    ofBackground(255);
    
    float posX = ofGetWidth()*0.5;
    float posY = ofGetHeight()*0.5;
    
    float speedX = ofRandom(-3.0, 5.0);
    float speedY = ofRandom(-3.0, 5.0);
}




//--------------------------------------------------------------
void ofApp::update(){

   // posX += speedX;
   // posY += speedY;
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawBitmapStringHighlight("of", 20, 20);
    ofSetColor(0);
    ofDrawCircle(posX, posY, 20);
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
uint64_t ofGetFrameNum(int x);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
