#include "ofMain.h"
#include "ofAppNoWindow.h"
#include "ofxNetwork.h"
#include <X11/extensions/XTest.h>

#ifdef TERGET_OSX
#endif

#ifdef TERGET_WINDOWS
#endif

class ofApp : public ofBaseApp {
	public:
                ofxUDPManager udp;

		ofApp(int _x, int _y){
			position(ofVec2f(_x,_y));
		}

 		void position(ofVec2f mouse){
			ofLog()<<mouse;
			Display *display = XOpenDisplay(NULL);
			Window root = DefaultRootWindow(display);
			XWarpPointer(display, None, root, 0, 0, 0, 0, mouse.x, mouse.y);
			XCloseDisplay(display);
		}

		void click(int button) {
		        Display *display = XOpenDisplay(NULL);
			XTestFakeButtonEvent (display, button, True,  CurrentTime);
			usleep(1);
                        XTestFakeButtonEvent (display, button, False, CurrentTime);
                        XFlush(display);
		        XCloseDisplay(display);
                }

		void keyboard(Display * disp, KeySym keysym, KeySym modsym){
			KeyCode keycode = 0, modcode = 0;
			keycode = XKeysymToKeycode (disp, keysym);
			if (keycode == 0) return;
			XTestGrabControl (disp, True);
			if (modsym != 0) {
			  modcode = XKeysymToKeycode(disp, modsym);
			  XTestFakeKeyEvent (disp, modcode, True, 0);
			}
			XTestFakeKeyEvent (disp, keycode, True, 0);
			XTestFakeKeyEvent (disp, keycode, False, 0); 
 			if (modsym != 0)
			  XTestFakeKeyEvent (disp, modcode, False, 0);
			XSync (disp, False);
			XTestGrabControl (disp, False);
		}

		#ifdef TERGET_OSX
		//
		#endif

		#ifdef TERGET_WINDOWS
		//
		#endif


 
		void setup(){
			udp.Create();
		        udp.Bind(11999);
		        udp.SetNonBlocking(true);
			//keyboard(disp, XK_A, 0);
		}

		ofVec2f mouse;
		void update(){
			char udpMessage[100000];
		        udp.Receive(udpMessage,100000);
		        string message=udpMessage;
		        if(message!="") {
				vector<string> res = ofSplitString(message, ",");
				mouse = ofVec2f(ofToInt(res[0]),ofToInt(res[1]));
				if(ofTrim(res[1])=="click") {
					click(1);
				}else{
					position(mouse);
				}
			}
		}
};

int main(int argc, char * argv[]) {
	ofAppNoWindow wind;
        int i=0;
        int x , y;
        x=atoi(argv[1]);
        y=atoi(argv[2]);
	ofSetupOpenGL(&wind, 1024,768, OF_WINDOW);
	
	ofRunApp( new ofApp(x,y));
}
