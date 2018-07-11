#pragma once

#include "ofMain.h"
#include "ofxFaceTracker.h"

class faceTracker : public ofBaseApp{
    
public:
    void init();
    void update();
    void draw();
    void reset();
    void debug();
    
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
    
    bool faceFound;
};
