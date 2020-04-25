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

    std::string url = "https://api.nasa.gov/neo/rest/v1/feed?start_date=2020-04-20&api_key=MY_KEY";
    
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
    
    float diaMin = root["near_earth_objects"]["2020-04-23"][0]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
    
    text<<"dia min = "<<diaMin<<"."<<endl;
   // ofDrawBitmapString(text.str(), 20, 200);
    float diameter_min = ofMap(diaMin,20, 100, 3, 20); // ****Diameter translation
    
    ofVec2f center(500,500), planet, orbit;
    
    planet = center + 100;
    orbit = planet.rotate(degrees++, center);

    ofDrawCircle(center, 50);
    ofDrawCircle(orbit, diameter_min);  // ****Translation into orbiting entity


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
