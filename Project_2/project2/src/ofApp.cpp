#include "ofApp.h"
#include "ofxJSON.h"
#include "ofxGui.h"
float degrees0 = 0;
float degrees1 = 120;
float degrees2 = 20;
float degrees3 = 80;

  



ofxJSONElement root;
std::ostringstream text;
std::ostringstream textTime;

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofSetCircleResolution(128);
    float Width = ofGetWidth();
    float Height = ofGetHeight();

    std::string url = "https://api.nasa.gov/neo/rest/v1/feed?start_date=2020-04-20&api_key=1SOcQaXmgQXNHuChy7Q7xcQiPJQ6cGV0d5Z4C7y8";
    
    // Now parse the JSON
    bool parsingSuccessful = root.open(url);

    if (parsingSuccessful)
    {
    ofLogNotice("ofApp::setup") << root.getRawString(true);
    } else {
    ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    
    float diaMin = root["near_earth_objects"]["2020-04-23"][0]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofColor colorOne(30, 30, 100);
    ofColor colorTwo(150, 150, 255);

    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    
    float Width = ofGetWidth();
    float Height = ofGetHeight();
    
  //-----------------------------------------------------------------------------
    
    float diaMin0 = root["near_earth_objects"]["2020-04-23"][0]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
    float diaMax0 =
        root["near_earth_objects"]["2020-04-23"][0]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
    text<<"dia min = "<<diaMax0<<"."<<endl;
    float Dia0 = (diaMin0+diaMax0)/2;
   // ofDrawBitmapString(text.str(), 20, 200);
    float Diameter0 = ofMap(Dia0,20, 100, 3, 20); // ****Diameter translation
    
    //-------------------------------------------------------------------------------
    
    

     
     float diaMin1 = root["near_earth_objects"]["2020-04-23"][1]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
     float diaMax1 =
         root["near_earth_objects"]["2020-04-23"][1]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
     text<<"dia min = "<<diaMax0<<"."<<endl;
     float Dia1 = (diaMin1+diaMax1)/2;
    // ofDrawBitmapString(text.str(), 20, 200);
     float Diameter1 = ofMap(Dia1,20, 100, 3, 20); // ****Diameter translation
     
     //-------------------------------------------------------------------------------
    
     float diaMin2 = root["near_earth_objects"]["2020-04-23"][2]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
     float diaMax2 =
         root["near_earth_objects"]["2020-04-23"][2]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
     text<<"dia min = "<<diaMax0<<"."<<endl;
     float Dia2 = (diaMin2+diaMax2)/2;
    // ofDrawBitmapString(text.str(), 20, 200);
     float Diameter2 = ofMap(Dia2,20, 100, 3, 20); // ****Diameter translation
     
     //-------------------------------------------------------------------------------
    
    ofVec2f center(Width/2,Height/2), planet0, planet1, planet2, planet3, orbit0, orbit1, orbit2, orbit3;
    
    planet0 = center + 100;   //rotating radius
    planet1 = center + 200;
    planet2 = center + 250;
    planet3 = center + 350;
    orbit0 = planet0.rotate(degrees0+=0.2, center);
    orbit1 = planet1.rotate(degrees1+=0.12, center);
    orbit2 = planet2.rotate(degrees2+=0.5, center);
    orbit3 = planet3.rotate(degrees3+=0.03, center);

    
    ofNoFill();
    ofDrawCircle(center, 50);
    ofDrawCircle(orbit0, Diameter0);  // ****Translation into orbiting entity
    ofDrawCircle(orbit1, Diameter1);
    ofDrawCircle(orbit2, Diameter2);
    //ofDrawCircle(orbit3, Diameter3);

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
