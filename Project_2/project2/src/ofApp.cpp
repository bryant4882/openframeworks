//The visualization will include color, shapes, movement, text, fonts

//A UI to manually change each variable used

#include "ofApp.h"
#include "ofxJSON.h"
#include "ofxGui.h"
float degrees0 = 0;
float degrees1 = 120;
float degrees2 = 20;
float degrees3 = 80;
float degrees4 = 30;
float degrees5 = 220;
float degrees6 = 10;
float degrees7 = 180;
float degrees8 = 310;
float degrees9 = 280;
ofTrueTypeFont font1;
int fontSize = 6;
//float velo0, vlo1, velo2; //actual velo
float speed0, speed1, speed2, speed3, speed4, speed5, speed6, speed7, speed8, speed9; //mapped speed



ofxJSONElement root;
std::ostringstream text;
std::ostringstream textTime;

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    gui.setup(); // most of the time you don't need a name
   // gui.add(volumeFloatSlider.setup("volume", 0.2f, 0.0f, 1.0f));
   // gui.add(center.setup("center", {ofGetWidth()*.5, ofGetHeight()*.5}, {0, 0}, {ofGetWidth(), ofGetHeight()}));
    gui.add(earthColor.setup("Earth color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
    gui.add(neoColor.setup("Neo color", ofColor(250, 212, 97), ofColor(0, 0), ofColor(255, 255)));
    gui.add(backColor.setup("Background color", ofColor(10, 10, 50), ofColor(0, 0), ofColor(255, 255)));
    gui.add(fontSize.setup("Font size", 6, 2, 15));
    gui.add(maxVelo.setup("Speed", 0.15, 0.005, 10));
    gui.add(neoSize.setup("Neo size", 10, 5, 60));
    gui.add(earthSize.setup("Earth size", 50, 40, 140));
    gui.add(textalp.setup("Text alpha", 90, 0, 100));
 //   gui.add(Button.setup("scene"));
  //  gui.add(screenSize.setup("screen size", ofToString(ofGetWidth())+"x"+ofToString(ofGetHeight())));
    
    
    ofSetCircleResolution(128);
    float Width = ofGetWidth();
    float Height = ofGetHeight();

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
    
    
    
    font1.load("ab.otf", fontSize);
    ofColor colorOne(backColor);
    ofColor colorTwo(0, 0, 10);

    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    
    float Width = ofGetWidth();
    float Height = ofGetHeight();
    
  //velo ranges from 7 to 38 in 9 objs
    
  //-----------------------------------------------------------------------------
    string name0  = root["near_earth_objects"]["2020-04-23"][0]["name"].asString();
    float diaMin0 = root["near_earth_objects"]["2020-04-23"][0]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
    float diaMax0 = root["near_earth_objects"]["2020-04-23"][0]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
    string velo0  = root["near_earth_objects"]["2020-04-23"][0]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString();
    float Velo0   = std::stof(velo0);
    speed0 = ofMap(Velo0, 4, 38, 0, maxVelo);
    string dis0     = root["near_earth_objects"]["2020-04-23"][0]["close_approach_data"][0]["miss_distance"]["astronomical"].asString();
    float  Dis0   = std::stof(dis0);
    float  distance0 = ofMap(Dis0, 0.05, 0.6, 100, 300);
    
    
    //text<<"velo0 = "<<velo0<<"."<<endl;
    float Dia0 = (diaMin0+diaMax0)/2;
   // ofDrawBitmapString(text.str(), 20, 200);
    float Diameter0 = ofMap(Dia0,20, 900, 3, neoSize); // ****Diameter translation
    
    //-------------------------------------------------------------------------------
    
    

     string name1  = root["near_earth_objects"]["2020-04-23"][1]["name"].asString();
     float diaMin1 = root["near_earth_objects"]["2020-04-23"][1]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
     float diaMax1 = root["near_earth_objects"]["2020-04-23"][1]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
     string velo1  = root["near_earth_objects"]["2020-04-23"][1]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString();
     float Velo1   = std::stof(velo1);
     speed1 = ofMap(Velo1, 4, 38, 0, maxVelo);
     string dis1     = root["near_earth_objects"]["2020-04-23"][1]["close_approach_data"][0]["miss_distance"]["astronomical"].asString();
     float  Dis1   = std::stof(dis1);
     float  distance1 = ofMap(Dis1, 0.05, 0.6, 100, 300);
    
    
     //text<<"dia min = "<<diaMax0<<"."<<endl;
     float Dia1 = (diaMin1+diaMax1)/2;
    // ofDrawBitmapString(text.str(), 20, 200);
     float Diameter1 = ofMap(Dia1,20, 900, 3, neoSize); // ****Diameter translation
     
     //-------------------------------------------------------------------------------
     string name2  = root["near_earth_objects"]["2020-04-23"][2]["name"].asString();
     float diaMin2 = root["near_earth_objects"]["2020-04-23"][2]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
     float diaMax2 = root["near_earth_objects"]["2020-04-23"][2]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
     string velo2  = root["near_earth_objects"]["2020-04-23"][1]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString();
     float Velo2   = std::stof(velo2);
     speed2 = ofMap(Velo2, 4, 38, 0, maxVelo);
     string dis2   = root["near_earth_objects"]["2020-04-23"][2]["close_approach_data"][0]["miss_distance"]["astronomical"].asString();
     float  Dis2   = std::stof(dis2);
     float  distance2 = ofMap(Dis2, 0.05, 0.6, 100, 300);
    
     text<<"dia min = "<<diaMax0<<"."<<endl;
     float Dia2 = (diaMin2+diaMax2)/2;
    // ofDrawBitmapString(text.str(), 20, 200);
     float Diameter2 = ofMap(Dia2,20, 900, 3, neoSize); // ****Diameter translation
    
     //-----------------------------------------------------------------------------
       string name3  = root["near_earth_objects"]["2020-04-23"][3]["name"].asString();
       float diaMin3 = root["near_earth_objects"]["2020-04-23"][3]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
       float diaMax3 = root["near_earth_objects"]["2020-04-23"][3]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
       string velo3  = root["near_earth_objects"]["2020-04-23"][3]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString();
       float Velo3   = std::stof(velo3);
       speed3 = ofMap(Velo3, 4, 38, 0, maxVelo);
       string dis3     = root["near_earth_objects"]["2020-04-23"][3]["close_approach_data"][0]["miss_distance"]["astronomical"].asString();
       float  Dis3  = std::stof(dis3);
       float  distance3 = ofMap(Dis3, 0.05, 0.6, 100, 300);
       
       
       //text<<"velo0 = "<<velo0<<"."<<endl;
       float Dia3 = (diaMin3+diaMax3)/2;
      // ofDrawBitmapString(text.str(), 20, 200);
       float Diameter3 = ofMap(Dia3,20, 900, 3, neoSize); // ****Diameter translation
    
     //-------------------------------------------------------------------------------
    
       string name4  = root["near_earth_objects"]["2020-04-23"][4]["name"].asString();
       float diaMin4 = root["near_earth_objects"]["2020-04-23"][4]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
       float diaMax4 = root["near_earth_objects"]["2020-04-23"][4]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
       string velo4  = root["near_earth_objects"]["2020-04-23"][4]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString();
       float Velo4   = std::stof(velo4);
       speed4 = ofMap(Velo4, 4, 38, 0, maxVelo);
       string dis4     = root["near_earth_objects"]["2020-04-23"][4]["close_approach_data"][0]["miss_distance"]["astronomical"].asString();
       float  Dis4  = std::stof(dis4);
       float  distance4 = ofMap(Dis4, 0.05, 0.6, 100, 300);
       
       
       //text<<"velo0 = "<<velo0<<"."<<endl;
       float Dia4 = (diaMin4+diaMax4)/2;
      // ofDrawBitmapString(text.str(), 20, 200);
       float Diameter4 = ofMap(Dia4,20, 900, 3, neoSize); // ****Diameter translation
    
     //-------------------------------------------------------------------------------
    
       string name5  = root["near_earth_objects"]["2020-04-23"][5]["name"].asString();
       float diaMin5 = root["near_earth_objects"]["2020-04-23"][5]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
       float diaMax5 = root["near_earth_objects"]["2020-04-23"][5]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
       string velo5  = root["near_earth_objects"]["2020-04-23"][5]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString();
       float Velo5   = std::stof(velo5);
       speed5 = ofMap(Velo5, 4, 38, 0, maxVelo);
       string dis5     = root["near_earth_objects"]["2020-04-23"][5]["close_approach_data"][0]["miss_distance"]["astronomical"].asString();
       float  Dis5  = std::stof(dis5);
       float  distance5 = ofMap(Dis5, 0.05, 0.6, 100, 300);
       
       
       //text<<"velo0 = "<<velo0<<"."<<endl;
       float Dia5 = (diaMin5+diaMax5)/2;
      // ofDrawBitmapString(text.str(), 20, 200);
       float Diameter5 = ofMap(Dia5,20, 900, 3, neoSize); // ****Diameter translation
    
     //-------------------------------------------------------------------------------
    
       string name6  = root["near_earth_objects"]["2020-04-23"][6]["name"].asString();
       float diaMin6 = root["near_earth_objects"]["2020-04-23"][6]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
       float diaMax6 = root["near_earth_objects"]["2020-04-23"][6]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
       string velo6  = root["near_earth_objects"]["2020-04-23"][6]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString();
       float Velo6   = std::stof(velo6);
       speed6 = ofMap(Velo6, 4, 38, 0, maxVelo);
       string dis6     = root["near_earth_objects"]["2020-04-23"][6]["close_approach_data"][0]["miss_distance"]["astronomical"].asString();
       float  Dis6  = std::stof(dis6);
       float  distance6 = ofMap(Dis6, 0.05, 0.6, 100, 300);
       
       
       //text<<"velo0 = "<<velo0<<"."<<endl;
       float Dia6 = (diaMin6+diaMax6)/2;
      // ofDrawBitmapString(text.str(), 20, 200);
       float Diameter6 = ofMap(Dia6,20, 900, 3, neoSize); // ****Diameter translation
    
     //-------------------------------------------------------------------------------
    
       string name7  = root["near_earth_objects"]["2020-04-23"][7]["name"].asString();
       float diaMin7 = root["near_earth_objects"]["2020-04-23"][7]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
       float diaMax7 = root["near_earth_objects"]["2020-04-23"][7]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
       string velo7  = root["near_earth_objects"]["2020-04-23"][7]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString();
       float Velo7   = std::stof(velo7);
       speed7 = ofMap(Velo7, 4, 38, 0, maxVelo);
       string dis7     = root["near_earth_objects"]["2020-04-23"][7]["close_approach_data"][0]["miss_distance"]["astronomical"].asString();
       float  Dis7  = std::stof(dis7);
       float  distance7 = ofMap(Dis7, 0.05, 0.6, 100, 300);
       
       
       //text<<"velo0 = "<<velo0<<"."<<endl;
       float Dia7 = (diaMin7+diaMax7)/2;
      // ofDrawBitmapString(text.str(), 20, 200);
       float Diameter7 = ofMap(Dia7,20, 900, 3, neoSize); // ****Diameter translation
    
     //-------------------------------------------------------------------------------
    
       string name8  = root["near_earth_objects"]["2020-04-23"][8]["name"].asString();
       float diaMin8 = root["near_earth_objects"]["2020-04-23"][8]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
       float diaMax8 = root["near_earth_objects"]["2020-04-23"][8]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
       string velo8  = root["near_earth_objects"]["2020-04-23"][8]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString();
       float Velo8   = std::stof(velo8);
       speed8 = ofMap(Velo8, 4, 38, 0, maxVelo);
       string dis8     = root["near_earth_objects"]["2020-04-23"][8]["close_approach_data"][0]["miss_distance"]["astronomical"].asString();
       float  Dis8  = std::stof(dis8);
       float  distance8 = ofMap(Dis8, 0.05, 0.6, 100, 300);
       
       
       //text<<"velo0 = "<<velo0<<"."<<endl;
       float Dia8 = (diaMin8+diaMax8)/2;
      // ofDrawBitmapString(text.str(), 20, 200);
       float Diameter8 = ofMap(Dia8,20, 900, 3, neoSize); // ****Diameter translation
    
     //-------------------------------------------------------------------------------
    
       string name9  = root["near_earth_objects"]["2020-04-23"][9]["name"].asString();
       float diaMin9 = root["near_earth_objects"]["2020-04-23"][9]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
       float diaMax9 = root["near_earth_objects"]["2020-04-23"][9]["estimated_diameter"]["meters"]["estimated_diameter_max"].asFloat();
       string velo9  = root["near_earth_objects"]["2020-04-23"][9]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString();
       float Velo9   = std::stof(velo9);
       speed9 = ofMap(Velo9, 4, 38, 0, maxVelo);
       string dis9     = root["near_earth_objects"]["2020-04-23"][9]["close_approach_data"][0]["miss_distance"]["astronomical"].asString();
       float  Dis9  = std::stof(dis9);
       float  distance9 = ofMap(Dis9, 0.05, 0.6, 100, 300);
       
       
       //text<<"velo0 = "<<velo0<<"."<<endl;
       float Dia9 = (diaMin9+diaMax9)/2;
      // ofDrawBitmapString(text.str(), 20, 200);
       float Diameter9 = ofMap(Dia9,20, 900, 3, neoSize); // ****Diameter translation
    
     //-------------------------------------------------------------------------------
    
    
    
    ofVec2f center(Width/2,Height/2), planet0, planet1, planet2, planet3, planet4,
    planet5, planet6, planet7, planet8, planet9, orbit0, orbit1, orbit2, orbit3,
    orbit4, orbit5, orbit6, orbit7, orbit8, orbit9;
    
    planet0 = center + distance0;   //rotating radius
    planet1 = center + distance1;
    planet2 = center + distance2;
    planet3 = center + distance3;
    planet4 = center + distance4;
    planet5 = center + distance5;
    planet6 = center + distance6;
    planet7 = center + distance7;
    planet8 = center + distance8;
    planet9 = center + distance9;


    orbit0 = planet0.rotate(degrees0+=speed0, center);
    orbit1 = planet1.rotate(degrees1+=speed1, center);
    orbit2 = planet2.rotate(degrees2+=speed2, center);
    orbit3 = planet3.rotate(degrees3+=speed3, center);
    orbit4 = planet4.rotate(degrees4+=speed4, center);
    orbit5 = planet5.rotate(degrees5+=speed5, center);
    orbit6 = planet6.rotate(degrees6+=speed6, center);
    orbit7 = planet7.rotate(degrees7+=speed7, center);
    orbit8 = planet8.rotate(degrees8+=speed8, center);
    orbit9 = planet9.rotate(degrees9+=speed9, center);




    
    //ofNoFill();
    ofSetColor(earthColor);
    ofDrawCircle(center, earthSize);
    ofSetColor(neoColor);
    ofDrawCircle(orbit0, Diameter0);  // ****Translation into orbiting entity
    ofDrawCircle(orbit1, Diameter1);
    ofDrawCircle(orbit2, Diameter2);
    ofDrawCircle(orbit3, Diameter3);
    ofDrawCircle(orbit4, Diameter4);
    ofDrawCircle(orbit5, Diameter5);
    ofDrawCircle(orbit6, Diameter6);
    ofDrawCircle(orbit7, Diameter7);
    ofDrawCircle(orbit8, Diameter8);
    ofDrawCircle(orbit9, Diameter9);




    ofSetColor(255, textalp);
    font1.drawString(name0, orbit0.x+Diameter0, orbit0.y-Diameter0);
    font1.drawString(name1, orbit1.x+Diameter1, orbit1.y-Diameter1);
    font1.drawString(name2, orbit2.x+Diameter2, orbit2.y-Diameter2);
    font1.drawString(name3, orbit3.x+Diameter3, orbit3.y-Diameter3);
    font1.drawString(name4, orbit4.x+Diameter4, orbit4.y-Diameter4);
    font1.drawString(name5, orbit5.x+Diameter5, orbit5.y-Diameter5);
    font1.drawString(name6, orbit6.x+Diameter6, orbit6.y-Diameter6);
    font1.drawString(name7, orbit7.x+Diameter7, orbit7.y-Diameter7);
    font1.drawString(name8, orbit8.x+Diameter8, orbit8.y-Diameter8);
    font1.drawString(name9, orbit9.x+Diameter9, orbit9.y-Diameter9);
   // ofDrawBitmapString(name0, orbit0+Diameter0);
//    ofDrawBitmapString(name1, orbit1+Diameter1);
//    ofDrawBitmapString(name2, orbit2+Diameter2);
//    ofDrawBitmapString(name3, orbit3+Diameter3);
//    ofDrawBitmapString(name4, orbit4+Diameter4);
//    ofDrawBitmapString(name5, orbit5+Diameter5);
//    ofDrawBitmapString(name6, orbit6+Diameter6);
//    ofDrawBitmapString(name7, orbit7+Diameter7);
//    ofDrawBitmapString(name8, orbit8+Diameter8);
//    ofDrawBitmapString(name9, orbit9+Diameter9);



 gui.draw();


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
