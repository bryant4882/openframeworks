#include "ofApp.h"

int size = 96;



//--------------------------------------------------------------
void ofApp::setup(){

    
    ofSetFrameRate(60);
    
}

//--------------------------------------------------------------
void ofApp::update(){
   // cam.setDistance(ofGetMouseY());
    
    
//    if(pin.y<=base.y-80){
//        pin.y++;}else{
//            pin.y = base.y-80;}
    
//mesh-------------------------------------------------------------
    int count = 0;
    for (int x = 0; x < size; x++){
        for( int y = 0; y <size; y++){
            ofVec3f position = mesh.getVertex(count);
            position.z = ofMap(ofNoise(count, ofGetElapsedTimef()), 0, 1, 0, ofRandom(0, 12));
            mesh.setVertex(count, position);
            count++;
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
}
//--------------------------------------------------------------
void ofApp::draw1(){
        
    ofBackground(70);
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
void ofApp::draw2(){

    ofSetCircleResolution(128);
    ofPushMatrix();
    cam.begin();
    ofTranslate(40, 190);
    float radius = 4;
    for (int i = 0; i<21; i++){
        float noisex = ofNoise(ofGetElapsedTimef()+i)*0.3;
        float noisey = ofNoise(ofGetElapsedTimef()+i)*0.3;
        float noisez = ofNoise(ofGetElapsedTimef()+i)*0.3;
        
        float x = ofGetWidth()/2*noisex;
        float y = ofGetWidth()/2*noisey;
        float z = ofGetWidth()/2*noisez;
        
        ofNoFill();
        ofSetColor(255);
        ofDrawCircle(x, y, z, radius);
        radius += i;
         cam.end();
        ofPopMatrix();
       
        
        
        
    }




}
//--------------------------------------------------------------
void ofApp::draw3(int a){
    

    ofBackground(0, a);
    
    ofPushMatrix();
    ofTranslate(40, 20, 200);
    cam.begin();
    ofSetColor(0,0,255, a);
    ofSetLineWidth(5);
    mesh.drawWireframe();
    
    cam.end();
    ofPopMatrix();
}
//--------------------------------------------------------------
void ofApp::draw4(int a){
    

    
    ofPushMatrix();
    ofTranslate(120, 60, 200);
    cam.begin();
    ofSetColor(255, a);
    ofSetLineWidth(2);
    mesh.drawWireframe();
    
    cam.end();
    ofPopMatrix();
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
