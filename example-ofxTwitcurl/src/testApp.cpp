#include "testApp.h"

std::string name = "add userName";
std::string pass = "add password";
std::string c_k = "add Consumer key";
std::string c_s = "add Consumer secret";
std::string data;
//--------------------------------------------------------------
void testApp::setup(){
    
    twitt.setup(name, pass, c_k, c_s);
    twitt.getPublicTimeline();
    //twitt.getFriendID(std::string("id"));
    //twitt.getTrend();
    //twitt.getUserTimeline();
    //twitt.searchString(std::string("test"));
    data = twitt.getData();
    cout<<"data"<<endl;
    cout<<data<<endl;
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