#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    ofSetFrameRate(24);

//    face.init();
    
    video.init();
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    face.update();
    
    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    face.draw();
    
    video.draw(ofGetWidth() / 2, ofGetHeight() / 2, 540, 540);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
//    if (key == 'r'){
//        face.reset();
//        cout << "tracker reset" << endl;
//    }
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
