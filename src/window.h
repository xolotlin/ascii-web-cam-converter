#ifndef WINDOW_H
#define WINDOW_H

#include <opencv2/highgui/highgui.hpp>
#include <string>

class Window {
    
    private:
        std::string windowName;

    public:
        // Constructor: Creates OpenCV Window
        Window(const std::string& name) : windowName(name) {
            // Window AUTOSIZE adjusts window size to the image frame automatically
            cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
        }

        // Destructor: destroy the window when obj is out of scope
        ~Window() {
            cv::destroyWindow(windowName);
        }

        // Display a frame (we will pass acutal image data here later)
        void show(const cv::Mat& frame) {
            if (!frame.empty()) cv::imshow(windowName, frame);
        }

}

#endif WINDOW_H
