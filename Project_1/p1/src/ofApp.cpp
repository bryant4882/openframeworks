#include "ofApp.h"


float SpeedX, SpeedY;
ofColor grey = (246, 247, 235);
ofColor orang = (233, 79, 55);
ofColor lblue = (124, 198, 254);
float currentTime = 0;
int size = 96;


//--------------------------------------------------------------
void ofApp::setup(){

    
//mesh----------------------------------------------------------------
    int p;
    p=1;
    int size = 96;
    cam.setDistance(7.5);
    //6.5 >>
    
    for (int x= 0; x<size; x++){
        for (int y= 0; y<size; y++){
            mesh.addVertex(ofPoint(x - size /2, y - size / 2));
        }
    }
    
    for (int x =0; x< size-p; x++){
        for (int y = 0; y < size-p; y++){
            mesh.addIndex(x + y * size);
            mesh.addIndex((x+p) + y * size);
            mesh.addIndex(x + (y+p) * size);
            mesh.addIndex((x+p) + y * size);
            mesh.addIndex((x+p) + (y+p) * size);
            mesh.addIndex(x + (y+p) * size);
        }
    }
    
//----------------------------------------------------------------
    ofSetFrameRate(60);
    

    
    SpeedX = ofGetFrameNum()-currentTime;
    SpeedY = ofGetFrameNum()-currentTime;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
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

    draw2();
    //drawcable();
}
//--------------------------------------------------------------
void ofApp::drawcable(){
 
    ofSetColor(255, 0, 0);
    ofFill();
    ofDrawCircle(640, 360, 60);
}
//--------------------------------------------------------------
void ofApp::draw1(){
        
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
void ofApp::draw3(){
    
//    int size = 96;
//    cam.setDistance(100);
//
//    for (int x= 0; x<size; x++){
//        for (int y= 0; y<size; y++){
//            mesh.addVertex(ofPoint(x - size /2, y - size / 2));
//        }
//    }
//
//    for (int x =0; x< size-1; x++){
//        for (int y = 0; y < size-1; y++){
//            mesh.addIndex(x + y * size);
//            mesh.addIndex((x+1) + y * size);
//            mesh.addIndex(x + (y+1) * size);
//            mesh.addIndex((x+1) + y * size);
//            mesh.addIndex((x+1) + (y+1) * size);
//            mesh.addIndex(x + (y+1) * size);
//        }
//    }
    
    ofPushMatrix();
    ofTranslate(40, 20, 200);
    cam.begin();
    ofSetColor(255);
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
