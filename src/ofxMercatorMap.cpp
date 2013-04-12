#include "ofxMercatorMap.h"


//--------------------------------------------------------------
ofxMercatorMap::ofxMercatorMap()  {}
ofxMercatorMap::~ofxMercatorMap() {}
    
//--------------------------------------------------------------
void ofxMercatorMap::setup(float _mapScreenWidth, float _mapScreenHeight, float _leftLongitude, float _bottomLatitude, float _rightLongitude, float _topLatitude) {
        
    mapScreenWidth  = _mapScreenWidth;
    mapScreenHeight = _mapScreenHeight;
    topLatitude     = _topLatitude;
    bottomLatitude  = _bottomLatitude;
    leftLongitude   = _leftLongitude;
    rightLongitude  = _rightLongitude;
    
    
    topLatitudeRelative     = getScreenYRelative(topLatitude);
    bottomLatitudeRelative  = getScreenYRelative(bottomLatitude);
    leftLongitudeRadians    = ofDegToRad(leftLongitude);
    rightLongitudeRadians   = ofDegToRad(rightLongitude);
    
}

//--------------------------------------------------------------
float ofxMercatorMap::getScreenYRelative(float latitudeInDegrees) {
    return log(tan(latitudeInDegrees / 360 * PI + PI / 4));
}

//--------------------------------------------------------------
float ofxMercatorMap::getScreenX(float longitudeInDegrees) {
    float longitudeInRadians = ofDegToRad(longitudeInDegrees);
    return mapScreenWidth * (longitudeInRadians - leftLongitudeRadians) / (rightLongitudeRadians - leftLongitudeRadians);
}

//--------------------------------------------------------------
float ofxMercatorMap::getScreenY(float latitudeInDegrees) {
    return mapScreenHeight * (getScreenYRelative(latitudeInDegrees) - topLatitudeRelative) / (bottomLatitudeRelative - topLatitudeRelative);
}

//--------------------------------------------------------------
ofPoint ofxMercatorMap::getScreenLocationFromLatLon(float lat, float lon) {
    float latitudeInDegrees  = lat;
    float longitudeInDegrees = lon;
    return ofPoint(getScreenX(longitudeInDegrees), getScreenY(latitudeInDegrees));
}


