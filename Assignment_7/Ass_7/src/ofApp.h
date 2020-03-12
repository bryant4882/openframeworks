#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
    
        void draw1();
        void draw2();
        void draw3();
        void draw4();
        void drawcable();
    
    
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
        bool bHide;
    
    ofxFloatSlider volume;
    ofxColorSlider color;
    ofxVec2Slider center;
    ofxIntSlider intensity;
    ofxButton scene;
    ofxLabel screenSize;

    ofxPanel gui;

    ofSoundPlayer ring;
    
    ofEasyCam cam;
    ofMesh mesh;
        
};
