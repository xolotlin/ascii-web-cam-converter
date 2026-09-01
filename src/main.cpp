/*
 * ASCII VISION: Cam to ASCII project
 * Made by Amaru M. Mendez
 * Date created in 8.30.2026
 **/

#include <opencv2/highgui/highgui.hpp>
#include "window.h"
#include "webcam.h"

#include <iostream>
#include <string>



int main() {
    Webcam camera(0);

    if (!camera.isReady()) {
        std::cerr << "Exiting: Camera is not available.\n";
        return -1;
    }

    std::cout << "Initializing window...\n";

    // Instantiate our window wrapper with initial size 800x600
    Window displayWindow("Webcame Preview", 800, 600);
    cv::Mat currentFrame;

    std::cout << "Window created succesfully. Press ESC in the terminal to exit.\n";

    for(;;) {
        // grab frame safely
        if (!camera.getFrame(currentFrame)) break;

        // display current frame
        displayWindow.show(currentFrame);

        //waitKey(30) waits 30 ms and listens for user key events (~33 FPS loop rate)
        // 27 == ESC
        if (cv::waitKey(30) == 27) break;
    }

    return 0;
}
