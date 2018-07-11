#include "faceTracker.h"

using namespace ofxCv;

//--------------------------------------------------------------
void faceTracker::init(){
    cam.initGrabber(640, 480);
    ofSetVerticalSync(true);
    ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    
    faceFound = false;
    tracker.setup();
    tracker.setRescale(.5); // Do i need to rescale?
}

//--------------------------------------------------------------
void faceTracker::update(){
    
    cam.update();
    
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
    }

    debug();
}

//--------------------------------------------------------------
void faceTracker::draw(){
    ofSetColor(255);
    cam.draw(0, 0);
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    
    ofSetLineWidth(1);
    tracker.draw();
    
    ofPolyline leftEye = tracker.getImageFeature(ofxFaceTracker::LEFT_EYE);
    ofPolyline rightEye = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYE);
    ofPolyline faceOutline = tracker.getImageFeature(ofxFaceTracker::FACE_OUTLINE);
    
    ofSetLineWidth(2);
    ofSetColor(ofColor::red);
    leftEye.draw();
    ofSetColor(ofColor::green);
    rightEye.draw();
    ofSetColor(ofColor::blue);
    faceOutline.draw();
    
    if(tracker.getFound()) {
        faceFound = true;
        ofSetColor(255);
        bool inside = faceOutline.inside(mouseX, mouseY);
        ofDrawBitmapString(inside ? "inside" : "outside", 10, 40);
    }
}

//--------------------------------------------------------------
void faceTracker::reset(){
    tracker.reset();
}

//--------------------------------------------------------------
void faceTracker::debug(){
    if (faceFound) cout << "face found" << endl;
}

