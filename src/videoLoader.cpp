#include "videoLoader.h"

//--------------------------------------------------------------
void videoLoader::init(){
    
    // Fill the array with GIFs
//    for (int i = 0; i <= numVideos; i++){
//        videos[i].load("movies/" + ofToString(i) + ".mp4");
//        videos[i].play();
//    }
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    singleVid.load("movies/" + ofToString(currentVid) + ".mp4");
    singleVid.setLoopState(OF_LOOP_NONE);
    singleVid.play();

    loopCounter = 0;
}

//--------------------------------------------------------------
void videoLoader::update(){
    
//    for (int i = 0; i <= numVideos; i++){
//        videos[currentVid].update();
//    }
    
    if (singleVid.getTotalNumFrames() > 250){
        loopAmount = 3;
    }
    else { loopAmount = 4; }
    
    singleVid.update();
    
    // Check for a loop and increment
    if (singleVid.getIsMovieDone()){
        
        singleVid.setFrame(0); //stutter?
        loopCounter++;
        singleVid.play();
        
        ofLog() << "number of times video has looped: " << loopCounter << endl;
    }
    
    // If loop > loopamount, move to next video
    if (loopCounter > loopAmount){
        
        currentVid++;
        
        // Check if it's the last video
        if (currentVid > numVideos){
            currentVid = 0;
        }
        
        ofLog() << "Loading next video..." << endl;
        init();
        
        
    }
    
    cout << loopCounter << endl;
    
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

