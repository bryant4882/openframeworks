#include "ofApp.h"
#include "ofxJSON.h"

#include <time.h>

ofxJSONElement root;
float phase = 0.5;
//--------------------------------------------------------------
void ofApp::setup(){
std::string url = "https://api.darksky.net/forecast/7a6e09268d4234ccaba4962781ca9436/40.7128,-74.0059";

// Now parse the JSON
bool parsingSuccessful = root.open(url);

if (parsingSuccessful)
{
ofLogNotice("ofApp::setup") << root.getRawString(true);
} else {
ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
}

    float tempHigh = root["daily"]["data"][1]["temperatureHigh"].asFloat();//2morrow's high
    float temp_c = root["currently"]["temperature"].asFloat();    //current temp
        
    int sunset = root["daily"]["data"][0]["sunsetTime"].asInt();  //todays sunset
    int sunrise = root["daily"]["data"][1]["sunriseTime"].asInt();//2morrows sunrise
    float humidity_c = root["currently"]["humidity"].asFloat();   //root.currently.humidity
    
    

   // int x = ofMap(temp_c, 20, 90, 0, 255);    //temp current to col
  //  float y = ofMap(humidity_c, 0, 1, 0, 255);       //humidity
  //  float z = ofMap(tempHigh, 20, 90, 0, 255); //temp 2morrow high
  //  float q = ofMap((sunrise/60/60/24)%365, 0, 365, 0, ofGetWidth());  //DAYOFYEaR
int current = time(NULL);
    gui.setup();
    gui.add(Red.setup("Red", temp_c, 0, 255));
    gui.add(Green.setup("Green", tempHigh, 0, 255));
    gui.add(Blue.setup("Blue", humidity_c*255, 0, 255));
    gui.add(Pos.setup("Pos", (current/60/60/24)%365, 0, ofGetWidth()));

ofColor yellow = ofColor::yellow;
ofColor black = ofColor::black;
black.lerp(yellow, phase); // interpolating (LERPING) between colors
ofSetBackgroundColor(black);
}

//--------------------------------------------------------------
void ofApp::update(){

}

std::ostringstream text;
std::ostringstream textTime;
//--------------------------------------------------------------
void ofApp::draw(){
    
std::string opening = "Hello World";
ofSetColor(200,200,0); // greenish
std::string summary = root["daily"]["data"][1]["summary"].asString();

float tempHigh = root["daily"]["data"][1]["temperatureHigh"].asFloat();//2morrow's high
float temp_c = root["currently"]["temperature"].asFloat();    //current temp
    
int sunset = root["daily"]["data"][0]["sunsetTime"].asInt();  //todays sunset
int sunrise = root["daily"]["data"][1]["sunriseTime"].asInt();//2morrows sunrise
float humidity_c = root["currently"]["humidity"].asFloat();   //root.currently.humidity
   
int current = time(NULL); // get current epoch
    int day = (current/60/60/24)%365;
    int hour = (current/60/60)%24;
    int minute = (current/60)%24;
    
if(ofGetFrameNum()==1){
    text<<"Today's summary is "<<summary<<"."<<endl
        <<"Tomorrow's highest temperature "<<tempHigh<<"."<<endl
        <<"Current temoerature "<<temp_c<<"."<<endl
        <<"Current humidity is "<<humidity_c<<"."<<endl
        <<"Tomorrow's sun rise at "<<sunrise<<"."<<endl
    
        <<"Today's sun set at "<<sunset<<".";
    textTime<<"Day "<<day<<" of this year."<<endl
    <<"Hour: "<<hour<<", Minute: "<<minute<<".";
}
   
 //   textTime<<"Day "<<day<<"this year.";
    

//ofDrawBitmapString(opening,20,40);
ofDrawBitmapString(text.str(), 20, 200);
ofDrawBitmapString(textTime.str(), 20, 140);


//int x = ofMap(temp_c, 20, 90, 0, 255);    //temp current to col
//float y = ofMap(humidity_c, 0, 1, 0, 255);       //humidity
//float z = ofMap(tempHigh, 20, 90, 0, 255); //temp 2morrow high
//float q = ofMap((sunrise/60/60/24)%365, 0, 365, 0, ofGetWidth());  //DAYOFYEaR
    
    
ofSetColor(Red,Green,Blue);
ofDrawCircle(Pos, 300, 50);
    



    
     gui.draw();
            

cout<<sunset<<","<<sunrise<<","<<current<<","<<Pos<<endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

if (key > '0' && key < '8') {

text.str(""); // set current text to nothing


int day = key - 48; // character '0' starts at integer 48 in the ASCII table
std::string summary = root["daily"]["data"][day]["summary"].asString(); // 7 day daily forecast. 0 == today
float tempHigh = root["daily"]["data"][day]["temperatureHigh"].asFloat();

text<<"In "<<day<<" day(s): "<<summary<<"The highest temperature will be "<<tempHigh<<".";
}

if (key == 'c')
text.str("Text Cleared");

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
