#include "ofApp.h"

//絶対変わらないと宣言する方法。define
#define GRID 30

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    ofSetCircleResolution(100);
    
    }


//--------------------------------------------------------------
void ofApp::update(){
    
    //idea 1
    //ofVec3f座標を格納する変数
    //ofVec3f vec1=ofVec3f(100,100);
    //ofvec3f vec2=ofvec3f(100,0);
    //cout << vec1.angle()vec2<<endl;
    //powの意味
    //float distance=hypot(distX,distY);
    //distance=radius
    
    ofVec3f vec1(mouseX-ofGetWidth()/2, mouseY-ofGetHeight()/2);
    ofVec3f vec2(1, 0); //vectorべくとる
    
    
    //if分の別の書き方「三項演算子」
    degree = (mouseY-ofGetHeight() < 0)? vec1.angle(vec2): 360-vec1.angle(vec2);
    degree = (mouseY-ofGetHeight()/2 < 0)? vec1.angle(vec2): 360-vec1.angle(vec2);

    
    circle_color = ofColor::fromHsb(degree*255/360, 255, 255);
    
    //color.setHsb(angle*255/360,255,255);
    
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    

    //背景線
    ofSetLineWidth(2);
    float alpha = 120;
    ofSetColor(circle_color,alpha);
    for (int i = 0; i <= ofGetHeight()/30; i++){
    ofLine(0, 30*i, ofGetWidth(), 30*i);
}
    for (int i = 0; i <= ofGetWidth()/30; i++){
    ofLine(30*i, 0, 30*i, ofGetHeight());
        
}
    //円
    ofSetColor(circle_color);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetLineWidth(3);
    ofSetCircleResolution(64);
    float dist = ofDist(ofGetWidth()/2, ofGetHeight()/2,mouseX,mouseY);
    ofCircle(0, 0, dist);

   
    //半径線
    ofPushMatrix();
    ofSetColor(255, 255, 255);
    ofSetLineWidth(1);
    ofLine(0, 0, mouseX-ofGetWidth()/2, mouseY-ofGetHeight()/2);
    ofPopMatrix();
    
    
    //十字線
    ofSetColor(255);
    ofSetLineWidth(2);
    ofLine(mouseX, 0, mouseX, 1024);
    ofLine(0, mouseY, 1024, mouseY);
    
    // 角度表示
    ofDrawBitmapString(ofToString(degree),mouseX*1.03, mouseY-ofGetHeight()/50);
    

    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
