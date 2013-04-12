#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBuffer file = ofBufferFromFile("WiFi_Lite.csv");
    while (!file.isLastLine()) {
        vector <string> values = ofSplitString(file.getNextLine(), ",");
        if(values.size()>=2) {
            float lon = ofToFloat(values[0]);
            float lat = ofToFloat(values[1]);
            coordinates.push_back(ofPoint(lon, lat));
        }
    }
    
    mapImage.loadImage("geography-class_c928f5.png");
    merMap.setup(mapImage.getWidth(), mapImage.getHeight(), -130.6055, 18.2294, -61.6992, 51.5087);
 
    ofSetWindowShape(mapImage.getWidth(), mapImage.getHeight());
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw() {

    ofEnableAlphaBlending();
    ofSetColor(255);
    mapImage.draw(0, 0);
    
    for(int i=0; i<coordinates.size(); i++) {
        ofPoint p = merMap.getScreenLocationFromLatLon(coordinates[i].y, coordinates[i].x);
        
        ofSetColor(0);
        ofCircle(p, 1);
    }
    
    ofDrawBitmapString(ofToString((int)coordinates.size())+" Wifi HotSpots in the US", 20, ofGetHeight()-50);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}