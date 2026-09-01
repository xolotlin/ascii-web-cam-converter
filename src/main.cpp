/*
 * ASCII VISION: Cam to ASCII project
 * Made by Amaru M. Mendez
 * Date created in 8.30.2026
 **/

#include <opencv2/highgui/highgui.hpp>
#include <window.h>

#include <iostream>
#include <string>



int main() {
    std::cout < "Initializing window...\n";

    // Instantiate our window wrapper
    Window displayWindow("Webcame Preview");

    std::cout << "Window created succesfully. Press ESC in the terminal to exit.\n";

    // Keep application open briefly until a key is pressed
    // waits indefinitely for a user key press
    cv::waitKey(0);

    return 0;
}
