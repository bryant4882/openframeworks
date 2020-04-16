#include "ofApp.h"


float SpeedX, SpeedY, ctf;
ofColor grey = (246, 247, 235);
ofColor orang = (233, 79, 55);
ofColor lblue = (124, 198, 254);
float currentTime = 0;
int size = 96;
int fade = 0;

ofImage emo;


ofSoundPlayer audio;

ofVec2f base, socket, pin, ni;

ofFbo fbo;
float fading;
bool fPressed;
float volume = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    
    emo.load("img/emo.jpg");
    
    audio.load("audio/audio.mp3");
    audio.setLoop(true);
    audio.setVolume(0);
    audio.play();

    
     fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
     fbo.begin();
     ofClear(0);
     fbo.end();
    
    ofSetBackgroundColor(0);
    
    ofSetCircleResolution(128);
    ofSetCurveResolution(320);
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
   // cam.setDistance(ofGetMouseY());
    
    if(fPressed == true){
        fade += 1;
    }
    
//    if(pin.y<=base.y-95){
//        pin.y++;}else{
//            pin.y = base.y-95;}
    
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
//
//   if(pin.y==base.y-115){
//        draw3();
//        draw4();}
    //draw1();
//    draw2();
    //draw3();
   // draw4();
   // draw5();
 //   drawcable();

    fbo.draw(0, 0);
    
        //pin---------------------
        
        ofSetColor(255);
        ofFill();
        ofRectangle pi;
        pi.x = ofNoise(0.05*ctf)*pin.x;
        pi.y = ofNoise(ctf)*pin.y*2.5+80;
        pi.width = 80;
        pi.height = 80;

        //----------------------------
//       if(cframe %3 ==0){
//       draw3();
//       draw4();} else if (cframe % 3==1){
//           draw1();
//       }else{draw2();}
        
       
      //base--------------------
        
           ofSetColor(255);
           ofFill();
           ofRectangle ba;
           ba.x = ofNoise(0.3*ctf)*base.x-200;
           ba.y = ofNoise(1.2*ctf)*base.y+150;
           ba.width = 400;
           ba.height = 30;
    
    //---------------------------------
    
    int cframe = ofGetFrameNum();
    
   // pi.y = 30;
    if(pi.y>=ba.y-80 && pi.x<=ba.x+400 && pi.x+80>=ba.x){
//
//
        audio.setVolume(0.2);;
//
        pi.y = ba.y-80;
        
        int index = 0;
        int currentf = 0;
        
        if (cframe%600 <300){
            draw3();
            draw4();
        }
        if (cframe%600 <450 && cframe%600>300){
            draw1();
        }
        if(cframe%600>450){
            draw2();
        }
        
       
            
        
        

        
    }
    else{
        audio.setVolume(0);
    }

            
//        pi.y = ba.y-80;}
    
//    if(pi.y<ba.y-80){
//        pi.y = ba.y-80;}
//
    
    ofDrawRectRounded(pi, 3);

    ofDrawRectRounded( ba, 3);
    
        
    //CABLE-----------------
        ctf = ofGetElapsedTimef(); //--current time in frames
            ofSetLineWidth(10);
            ofNoFill();
            ofDrawBezier(ba.x+10, ba.y+ba.height/2, 200*ofNoise(ctf), 500*ofNoise(0.5*ctf), 700*ofNoise(ctf), 200*ofNoise(ctf), pi.x+pi.width/2, pi.y+20);
    emo.draw(pi.x, pi.y, pi.width, pi.height);
    


   

    
    
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
    
    ofSetColor(255);
    ofFill();
    ofRectangle pi;
    pi.x = ofNoise(0.05*ctf)*pin.x;
    pi.y = pin.y;
    pi.width = 80;
    pi.height = 80;
    
    ofDrawRectRounded(pi, 3);
    
   
  //base--------------------
    
       ofSetColor(255);
       ofFill();
       ofRectangle ba;
       ba.x = ofNoise(0.03*ctf)*base.x-200;
       ba.y = base.y-35;
       ba.width = 400;
       ba.height = 30;

       ofDrawRectRounded( ba, 3);
    
//CABLE-----------------
    ctf = ofGetElapsedTimef(); //--current time in frames
        ofSetLineWidth(10);
        ofNoFill();
        ofDrawBezier(ba.x+10, ba.y+ba.height/2, 200*ofNoise(ctf), 500*ofNoise(0.5*ctf), 700*ofNoise(ctf), 200*ofNoise(ctf), pi.x+pi.width/2, pi.y+20);
    
    
    

}
//--------------------------------------------------------------
void ofApp::draw1(){
        
    int i, o, d;
    d = 2;
    
    ofBackground(0);
        float W = ofGetWidth();
        float H = ofGetHeight();


        for (i=-10000; i<W; i+=70){
            for(o=-10000; o<H; o+=70){
                ofSetColor(233, 79, 55);
                if (i>1400){
                    i = 0;
                    o = 0;
                }
                    ofDrawCircle(i+(ofGetFrameNum())*d, o+(ofGetFrameNum())*d, 27);
                
            }
        }
        
    }
    
//--------------------------------------------------------------
void ofApp::draw2(){

    ofBackground(0);
    ofSetCircleResolution(128);
    ofPushMatrix();
    cam.begin();
    ofSetLineWidth(2);
    ofTranslate(40, 190);
    float radius = 4;
    for (int i = 0; i<40; i++){
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
