#pragma once

#include "ofMain.h"
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
    
        void volumeFloatSliderChanged(float & volumeFloatSlider) ;
        void changeExpressionButtonPressed();
    
        ofSoundPlayer bgm;
        float bgmVolume = 0.2f;
    
        ofxPanel gui;

        ofxFloatSlider volumeFloatSlider;
        ofxButton changeExpressionButton;
        ofxVec2Slider sunVecSlider;
        ofxColorSlider backgroundColorSlider;
        ofxIntSlider emotionalIntSlider;
    
        ofxLabel screenSize;
            
};
