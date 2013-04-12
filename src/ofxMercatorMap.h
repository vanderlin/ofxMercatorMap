#pragma once
#include "ofMain.h"

class ofxMercatorMap {
    
public:
    
    
    float topLatitudeRelative;
    float bottomLatitudeRelative;
    float leftLongitudeRadians;
    float rightLongitudeRadians;
    float mapScreenWidth, mapScreenHeight;
    
    float topLatitude;      // Northern border of this map, in degrees.
    float bottomLatitude;   // Southern border of this map, in degrees.
    float leftLongitude;    // Western border of this map, in degrees.
    float rightLongitude;   // Eastern border of this map, in degrees.
    
    
    //--------------------------------------------------------------
    ofxMercatorMap();
    ~ofxMercatorMap();
    
    //--------------------------------------------------------------
    // leftLon, bottomLat, rightLon, topLat
    void setup(float _mapScreenWidth, float _mapScreenHeight,
               float _leftLongitude    = -180.0,
               float _bottomLatitude   = -80.0,
               float _rightLongitude   = 180.0,
               float _topLatitude      = 80.0);
    
    //--------------------------------------------------------------
    float getScreenYRelative(float latitudeInDegrees);
    float getScreenX(float longitudeInDegrees);
    float getScreenY(float latitudeInDegrees);
    ofPoint getScreenLocationFromLatLon(float lat, float lon);
    
};
