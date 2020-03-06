#include "ofApp.h"

ofSoundPlayer boop;

int x, y, w, h;

//palette
ofColor yellow(252, 212, 101);
ofColor blue(58, 144, 181);
ofColor black (0);
ofColor white (255);

ofPolyline line;

float mx, my, mw, mh;
float length = 30;
float currenttime = 0;
int no = 0;


//--------------------------------------------------------------
void ofApp::setup(){
    
    boop.loadSound("dash.wav");


    ofSetFrameRate(60);
    ofBackground(yellow);
    w = ofGetWidth();
    h = ofGetHeight();
    mx = w/2;
    my = h/2;
    mw = 30;
    mh = 10;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------

void ofApp::draw(){
    
    
    ofSetColor(blue);
    ofSetLineWidth(1);
    ofFill();
    line.addVertex(ofVec3f(w/2-w/10, h/2-100));
    line.addVertex(ofVec3f(w/2-w/10, h/2+h/6));
    line.addVertex(ofVec3f(w/2+w/10, h/2+100));
    line.addVertex(ofVec3f(w/2+w/10, h/2-h/6));
    line.addVertex(ofVec3f(w/2, h/2-h/6));
    line.close();
    line.draw();
    
//    ofSetRectMode(OF_RECTMODE_CENTER);
//
//
//
//    ofSetColor(blue);
//    ofRectangle face;
//    face.x = w/2;
//    face.y = h/2;
//    face.width = w/5;
//    face.height = h/3;
//    ofDrawRectRounded(face, 20);
    
    
    //eyes
    ofPushMatrix();
    ofTranslate(-10, 0);
    ofSetColor(white);
    ofRectangle leye;
    leye.x = w/2 - 30;
    leye.y = h/2 - 30;
    leye.width = 20;
    leye.height = 20;
    ofDrawRectRounded(leye, 10);
    
    ofSetColor(white);
    ofRectangle reye;
    reye.x = w/2 + 30;
    reye.y = h/2 - 30;
    reye.width = 20;
    reye.height = 20;
    ofDrawRectRounded(reye, 10);
    ofPopMatrix();
    
//    //mouth
//    ofSetColor(white);
//    ofDrawEllipse(mx, my, mw, mh);
    


    
    //brow global vars
    float browlx = leye.x-18;
    float browly = leye.y-20;
    
    float browrx = reye.x+17;
    float browry = reye.y-20;
    
//state id
    if (no == 0){
        drawhappy();
        
    }
    if (no == 1){
        drawsad();
    }
    if (no == 2){
        drawsurp();
    }
    if (no == 3){
        drawmad();
    }

    if ((ofGetFrameNum()%120) == 0){
        
        boop.play();
        
        if (no > 2){
            no=0;
        }else {
            no++;
            currenttime = ofGetFrameNum();
        }
    }
    
    
}

    //happybrows

    void ofApp::drawhappy(){

        
    float browlx = w/2 - 30-18;
    float browly = h/2 - 30-20;
    
    float browrx = w/2 + 30+17;
    float browry = h/2 - 30-20;
        
    ofSetColor(white);
    ofSetLineWidth(15);

    ofDrawLine(browlx, browly-0.1*(ofGetFrameNum()-currenttime), browlx+length, browly-0.1*(ofGetFrameNum()-currenttime));

    ofDrawLine(browrx, browry-0.1*(ofGetFrameNum()-currenttime), browrx-length, browry-0.1*(ofGetFrameNum()-currenttime));

    //happymouth

    ofSetColor(white);
    ofDrawBezier(mx-15, my, mx-15, my+0.1*(ofGetFrameNum()-currenttime), mx+15, my+0.1*(ofGetFrameNum()-currenttime), mx+15, my);
    
    }
    //madbrows
   
void ofApp::drawmad(){
    
    float browlx = w/2 - 30-18;
    float browly = h/2 - 30-20;
    
    float browrx = w/2 + 30+17;
    float browry = h/2 - 30-20;

    ofSetColor(white);
    ofSetLineWidth(15);

    ofPushMatrix();
    ofTranslate(browlx+length, browly);
    ofRotateDeg(0.1 * (ofGetFrameNum() - currenttime));
    ofDrawLine(0, 0, -length, 0);
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(browrx-length, browry);
    ofRotateDeg(-0.1 * (ofGetFrameNum() - currenttime));
    ofDrawLine(0, 0, length, 0);
    ofPopMatrix();
    
        //mouth
        ofSetColor(white);
        ofDrawEllipse(mx, my, mw, mh);

}
//sadbrows

void ofApp::drawsad(){
    
    float browlx = w/2 - 30-18;
    float browly = h/2 - 30-20;
    
    float browrx = w/2 + 30+17;
    float browry = h/2 - 30-20;
    
    ofSetColor(white);
    ofSetLineWidth(15);

    ofPushMatrix();
    ofTranslate(browlx+length, browly);
    ofRotateDeg(-0.1 * (ofGetFrameNum() - currenttime));
    ofDrawLine(0, 0, -length, 0);
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(browrx-length, browry);
    ofRotateDeg(0.1 * (ofGetFrameNum() - currenttime));
    ofDrawLine(0, 0, length, 0);
    ofPopMatrix();
    
        //mouth
        ofSetColor(white);
        ofDrawEllipse(mx, my, mw, mh);
    
}
//
    //surprisebrows
    
void ofApp::drawsurp(){
    
    float browlx = w/2 - 30-18;
    float browly = h/2 - 30-20;
    
    float browrx = w/2 + 30+17;
    float browry = h/2 - 30-20;
    
    ofSetColor(white);
    ofSetLineWidth(15);

    ofDrawLine(browlx, browly-0.1*(ofGetFrameNum()-currenttime), browlx+length, browly-0.1*(ofGetFrameNum()-currenttime));
    
    ofDrawLine(browrx, browry-0.1*(ofGetFrameNum()-currenttime), browrx-length, browry-0.1*(ofGetFrameNum()-currenttime));

    //surprisemouth
    
   
        ofSetColor(white);
        ofDrawEllipse(mx, my, mw+0.07*(ofGetFrameNum()- currenttime), mh+0.1*(ofGetFrameNum()- currenttime));
    
    

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
