#include "ofApp.h"
#include "ofxJSON.h"
#include "ofxGui.h"
int degrees = 0;
  



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
    
    ofVec2f center(Width/2,Height/2), planet, orbit0, orbit1, orbit2, orbit3;
    
    planet = center + 100;
    orbit0 = planet.rotate(degrees++, center);
    orbit1 = planet.rotate(degrees--, center);
    orbit2 = planet.rotate(degrees++, center);
    orbit3 = planet.rotate(degrees++, center);

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
