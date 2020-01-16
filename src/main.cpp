#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    ofGLFWWindowSettings settings;

    /* Win A */
    
    settings.setSize(300, 300);
    settings.setPosition(ofVec2f(300,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> winA = ofCreateWindow(settings);
    shared_ptr<ofApp> appA(new ofApp);
    
    /* Win B */
    
    settings.setSize(300, 300);
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = false;
    shared_ptr<ofAppBaseWindow> winB = ofCreateWindow(settings);
    shared_ptr<ofApp> appB(new ofApp);
    
    /* Link both */
    
    appA->otherApp = appB;
    appA->name = "A";
    appB->otherApp = appA;
    appB->name = "B";
    
    ofRunApp(winA, appA);
    ofRunApp(winB, appB);
    ofRunMainLoop();

}
