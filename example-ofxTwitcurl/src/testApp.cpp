#include "testApp.h"

std::string name = "add userName";
std::string pass = "add password";
std::string c_k = "add Consumer key";
std::string c_s = "add Consumer secret";
std::string t_k = "add Access token";
std::string t_s = "add Access token secret";

//--------------------------------------------------------------
void testApp::setup(){
    
    twitt.setup(name,pass,c_k,c_s,t_k,t_s);
    twitt.getFriendID();
    //twitt.getTrend();
    //twitt.getPublicTimeline();
    //twitt.getUserTimeline();
    //twitt.searchString(std::string("test"));
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
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