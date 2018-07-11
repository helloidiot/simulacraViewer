#pragma once

#include "ofMain.h"
#include "faceTracker.h"

class videoLoader : public ofBaseApp{
    
public:
    void init();
    void update();
    void draw(int vidPosX, int vidPosY, int vidSizeX, int vidSizeY);
    void debug();
    
    faceTracker face;
    
    int numVideos = 24;
    int currentVid = 0;
    int loopCounter;
    int loopAmount = 4;
    ofVideoPlayer videos[24];
    ofVideoPlayer singleVid;

};

