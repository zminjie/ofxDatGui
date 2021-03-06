#include "ofApp.h"

/*
    Simple example to demonstrate the Range Slider Component
    https://github.com/braitsch/ofxDatGui @braitsch
*/

void ofApp::setup()
{
    ofSetWindowPosition(0, 0);
    
// instantiate a slider with a default value of 20 //
    slider = new ofxDatGuiSlider("BACKGROUND BRIGHTNESS", 0, 100, 20);
    
// let's make it BIG //
    mTemplate.row.width = ofGetWidth();
    mTemplate.row.label.maxAreaWidth = 340;
    slider->setTemplate(&mTemplate);
    
// and position it verticaly centered on the screen //
    slider->setOrigin(0, ofGetHeight()/2 - slider->getHeight()/2);

// listen for change events //
    slider->onSliderEvent(this, &ofApp::onSliderEvent);
    
// and set the background color to the slider's default value //
    ofSetBackgroundColor(ofColor::white*slider->getScale());
}

void ofApp::onSliderEvent(ofxDatGuiSliderEvent e)
{
    ofSetBackgroundColor(ofColor::white*e.scale);
}

void ofApp::update()
{
    slider->update();
}

void ofApp::draw()
{
    slider->draw();
}

