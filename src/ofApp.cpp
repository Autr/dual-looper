#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetDataPathRoot("../Resources/data/");
    ofAppGLFWWindow* win = dynamic_cast<ofAppGLFWWindow *> (ofGetWindowPtr());
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString( name , ofGetWidth() / 2, ofGetHeight() / 2);
    video.draw( 0, 0, ofGetWidth(), ofGetHeight() );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f' ) ofToggleFullscreen();
    if (key == 'r' ) {
        ofLogNotice("ofApp") << "resetting both to start";
        video.setPositionAsFloat( 0.0 );
        otherApp->video.setPositionAsFloat( 0 );
    }
//    if (key == 't' ) {
//        ofLogNotice("ofApp") << "testing end loop point";
//        video.setPositionAsFloat( 0.98 );
//        otherApp->video.setPositionAsFloat( 0.98 );
//    }
    if (key == OF_KEY_RIGHT ) {
        float a = video.getPositionAsFloat() + 0.1;
        while (a > 1) a -= 1.0;
        video.setPositionAsFloat( a );
        float b = otherApp->video.getPositionAsFloat() + 0.1;
        while (b > 1) b -= 1.0;
        otherApp->video.setPositionAsFloat( b );
    }
    if (key == OF_KEY_LEFT ) {
        float a = video.getPositionAsFloat() - 0.1;
        while (a < 0) a += 1.0;
        video.setPositionAsFloat( a );
        float b = otherApp->video.getPositionAsFloat() - 0.1;
        while (b < 0) b += 1.0;
        otherApp->video.setPositionAsFloat( b );
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

void ofApp::setVideoPositionFromMouse( int x, int y ) {
    float pos = ofMap( x , 0 , ofGetWidth(), 0 , 1);
    video.setPositionAsFloat( pos);
    otherApp->video.setPositionAsFloat( pos );
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    setVideoPositionFromMouse( x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    setVideoPositionFromMouse( x, y);
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
    if ( dragInfo.files.size() > 0 ) {
        ofLogNotice("ofApp") << "adding file" << dragInfo.files[0];
        
        video.unload();
        video.init( dragInfo.files[0] );
        video.load();
        
    }
}
