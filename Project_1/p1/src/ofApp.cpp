#include "ofApp.h"


float SpeedX, SpeedY, ctf;
ofColor grey = (246, 247, 235);
ofColor orang = (233, 79, 55);
ofColor lblue = (124, 198, 254);
float currentTime = 0;
int size = 96;
int fade = 0;


ofVec2f base, socket, pin, ni;

ofFbo fbo;
float fading;
bool fPressed;


//--------------------------------------------------------------
void ofApp::setup(){

    
     fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
     fbo.begin();
     ofClear(0);
     fbo.end();
    
    ofSetBackgroundColor(0);
    
    ofSetCircleResolution(128);
    float mw = ofGetWidth()/2;
    float mh = ofGetHeight()/2;
    
    //vec set-------------------------------------------------------

    base.set(mw, mh);
    pin.set(mw-100, mh-240);
    
    
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
    
    if(fPressed == true){
        fade += 1;
    }
    
    if(pin.y<=base.y-115){
        pin.y++;}else{
            pin.y = base.y-115;}
    
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
    
    fbo.begin();
    ofSetColor(140, 60, 240, fade);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    fbo.end();

    fbo.draw(0, 0);

    
  //  -------------edge dectection
    
  //  if(pin.y==base.y-115){
    //    draw3();
    //    draw4();}
//    draw2();
    //draw3();
    //draw4();
    drawcable();
//-----------------
    
 
    //draw5();
    
    fbo.begin();
    ofSetColor(140, 60, 240, fade);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    fbo.end();

    fbo.draw(0, 0);
    
   

    
    
}
//--------------------------------------------------------------
void ofApp::drawcable(){
 
    float mw = ofGetWidth()/2;
    float mh = ofGetHeight()/2;

    
   
//
//    //nid-------------------
//    ofSetColor(180);
//    ofFill();
//    ofRectangle nid;
//    nid.x = pin.x+10;
//    nid.y + pin.y+70;
//    nid.width = 10;
//    nid.height = 45;
//
//    ofDrawRectRounded(nid, 2);
//
//    //nid1-------------------
//    ofSetColor(180);
//    ofFill();
//    ofRectangle nid1;
//    nid1.x = pin.x+55;
//    nid1.y + pin.y+70;
//    nid1.width = 10;
//    nid1.height = 45;
//
//    ofDrawRectRounded(nid1, 2);
    
    //pin---------------------
    
    ofSetColor(200);
    ofFill();
    ofRectangle pi;
    pi.x = pin.x;
    pi.y = pin.y;
    pi.width = 80;
    pi.height = 80;
    
    ofDrawRectRounded(pi, 10);
    
   
  //base--------------------
    
       ofSetColor(255);
       ofFill();
       ofRectangle ba;
       ba.x = base.x-200;
       ba.y = base.y-35;
       ba.width = 400;
       ba.height = 70;

       ofDrawRectRounded( ba, 30);
    
//CABLE-----------------
    ctf = ofGetElapsedTimef(); //--current time in frames
        ofSetLineWidth(3);
        ofNoFill();
        ofDrawCurve(ba.x, ba.y, ofGetMouseX(), ofGetMouseY(), 200*ofNoise(ctf), 400*ofNoise(ctf), 600*ofNoise(ctf), 1400*ofNoise(ctf));
    

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
    ofBackground(0);
    
    ofPushMatrix();
    ofTranslate(40, 20, 200);
    cam.begin();
    ofSetColor(0,0,255);
    ofSetLineWidth(5);
    mesh.drawWireframe();
    
    cam.end();
    ofPopMatrix();
}
//--------------------------------------------------------------
void ofApp::draw4(){
    
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
   // ofBackground(0);
    
    ofPushMatrix();
    ofTranslate(120, 60, 200);
    cam.begin();
    ofSetColor(255);
    ofSetLineWidth(2);
    mesh.drawWireframe();
    
    cam.end();
    ofPopMatrix();
}

void ofApp::draw5(){
 
    ofBackground(0);
    ofSetColor(255);
    ofSetLineWidth(3);
    ofNoFill();
    
   // ofDrawCurve(20, 20, ofGetMouseX(), ofGetMouseY(), ofRandom(200,400), ofRandom(200,800), ofRandom(500,700), ofRandom(1120,1180));
       // ofDrawCurve(20, 20, ofGetMouseX(), ofGetMouseY(), 100, 200, 500,1120);
    
}
    
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'f'){
        fPressed = true;
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

    base.set(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    pin.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

     base.set(ofGetWidth()/2,ofGetHeight()/2);
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
