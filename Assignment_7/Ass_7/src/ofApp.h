#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
    
    void drawhappy();
    void drawsad();
    void drawsurp();
    void drawmad();
        
        void exit();

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

        void circleResolutionChanged(int & circleResolution);
        void ringButtonPressed();

        bool bHide;

        ofxFloatSlider vol;
        ofxColorSlider color;
        ofxVec2Slider center;
        ofxIntSlider circleResolution;
        ofxIntSlider deg;
        ofxButton emoF;
        ofxButton emoB;
        ofxLabel screenSize;

        ofxPanel gui;

        ofSoundPlayer ring;
    };



//Create a UI with the following:
//
//An ofxFloatSlider to control the sound volume 0
//An ofxButton to rotate between which emotion is being displayed 0
//An ofxVec2Slider to change the x,y of all shapes being drawn
//An ofxColorSlider to select the color of one shape in the drawing
//An ofxIntSlider shape movement (degree of emotion)
//Appropriate labels
//Use translation, scaling, and rotation to add at least 3 new features to the existing emotions.
