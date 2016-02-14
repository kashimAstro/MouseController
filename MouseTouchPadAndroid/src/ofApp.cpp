#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sender.Create();
	sender.Connect("192.168.8.102",11999);
	sender.SetNonBlocking(true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(25,185,255);
	ofFill();
	ofSetColor(255,0,0);
	ofDrawEllipse(mouseX-5,mouseY-5,10,10);
	ofNoFill();
	ofSetColor(255,255,255);
	ofDrawEllipse(mouseX-30,mouseY-30,60,60);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id){
	string message=ofToString(ofMap(x,0,ofGetWidth(),0,1366))+","+ofToString(ofMap(y,0,ofGetHeight(),0,768))+"\n";
	sender.Send(message.c_str(),message.length());
}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id){
	string message="2,click\n";
	sender.Send(message.c_str(),message.length());
}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){

}

//--------------------------------------------------------------
void ofApp::pause(){

}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}
