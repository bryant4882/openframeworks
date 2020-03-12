#include "ofApp.h"
int counter;

float SpeedX, SpeedY;
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

    counter =0;
     fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
     fbo.begin();
     ofClear(0);
     fbo.end();
    

    Button.addListener(this, &ofApp::ButtonPressed);
    volumeFloatSlider.addListener(this, &ofApp::volumeFloatSliderChanged);
    
    //guis---------------------------------------------------------
    gui.setup(); // most of the time you don't need a name
    gui.add(volumeFloatSlider.setup("volume", 0.2f, 0.0f, 1.0f));
    gui.add(center.setup("center", {ofGetWidth()*.5, ofGetHeight()*.5}, {0, 0}, {ofGetWidth(), ofGetHeight()}));
    gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
    gui.add(dis.setup("dis", 7, 6, 15));
    gui.add(Button.setup("scene"));
    gui.add(screenSize.setup("screen size", ofToString(ofGetWidth())+"x"+ofToString(ofGetHeight())));
    
    ofSetBackgroundColor(color);
    
    ofSetCircleResolution(128);
    float mw = center->x;
    float mh = center->y;

    bHide = false;

    bgm.load("Noise.mp3");
    bgm.play();
    bgm.setLoop(true);
    bgm.setVolume(bgmVolume);
    
    //vec set-------------------------------------------------------

    base.set(center->x, center->y);
    pin.set(center->x-100, center->y-240);
    
    
    //mesh----------------------------------------------------------------
    int p;
    p=1;
    int size = 96;
    cam.setDistance(7);
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
    
    cam.setDistance(dis);
    
    if(fPressed == true){
        fade += 1;
    }
    
    if(pin.y<=center->y-115){
        pin.y++;}else{
            pin.y = center->y-115;}
    
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

    if(pin.y==center->y-115){
       
        if (counter == 0){
             draw1();
        }else if (counter == 1){
            draw2();
        }else if (counter == 2){
            draw3();
            draw4();
        }
    }else if (counter==3){
        counter=0;
    }
    
    drawcable();


        
       
//    draw2();
    //draw3();
    //draw4();
    
    
    
    fbo.begin();
    ofSetColor(140, 60, 240, fade);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    fbo.end();

    fbo.draw(0, 0);
    
   if(!bHide){
       gui.draw();
   }

    
    
}
//--------------------------------------------------------------
void ofApp::ButtonPressed(){
    
    counter++;
    
}
//-----------------------------------------------
void ofApp::volumeFloatSliderChanged(float & volumeFloatSlider ) {
    bgm.setVolume(volumeFloatSlider);
}


//--------------------------------------------------------------
void ofApp::drawcable(){
 
    float mw = ofGetWindowWidth()/2;
    float mh = ofGetWindowHeight()/2;

    
   
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
       ba.x = center->x-200;
       ba.y = center->y-35;
       ba.width = 400;
       ba.height = 70;

       ofDrawRectRounded( ba, 30);
    

}
//--------------------------------------------------------------
void ofApp::draw1(){
        
    ofBackground(color);
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

    ofSetBackgroundColor(color);?
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
    ofBackground(color);
    
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
