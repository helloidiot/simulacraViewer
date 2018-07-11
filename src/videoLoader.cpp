#include "videoLoader.h"

//--------------------------------------------------------------
void videoLoader::init(){
    
    // 3 empty frames....
    for (int i = 0; i < numVideos; i++){
        videos[i].load("movies/" + ofToString(currentVid) + ".mp4");
        videos[i].setLoopState(OF_LOOP_NONE);
        videos[i].play();
    }
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    singleVid.load("movies/" + ofToString(currentVid) + ".mp4");
    singleVid.setLoopState(OF_LOOP_NONE);
    singleVid.play();

    loopCounter = 0;
}

//--------------------------------------------------------------
void videoLoader::update(){
    
    if (singleVid.getTotalNumFrames() > loopThreshold){
        loopAmount = shortLoop;
    }
    else { loopAmount = longLoop; }
    
    singleVid.update();
    
    // Check for a loop and increment loopCounter
    if (singleVid.getIsMovieDone()){
        
        singleVid.setFrame(0); // causing stutter?
        loopCounter++;
        singleVid.play();
        
        ofLog() << "number of times video has looped: " << loopCounter << endl;
    }
    
    // If loops are complete, move to next video
    if (loopCounter > loopAmount){
        
        currentVid++;
        
        // Check if it's the last video
        if (currentVid > numVideos){
            currentVid = 0;
        }
        
        ofLog() << "Loading next video..." << endl;
        init();
        
        
    }
    
}

//--------------------------------------------------------------
void videoLoader::draw(int vidPosX, int vidPosY, int vidSizeX, int vidSizeY){

    singleVid.draw(vidPosX, vidPosY, vidSizeX, vidSizeY);
}



//--------------------------------------------------------------
void videoLoader::debug(){
    ofLog() << "Video: " << currentVid;
    ofLog();
    ofLog();
}

