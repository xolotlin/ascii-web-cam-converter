#ifndef WINDOW_H
#define WINDOW_H

#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <stdexcept>

class Window {
    
    private:
        std::string windowName;

    public:
        // Constructor: Creates OpenCV Window
        Window(const std::string& name, int width = 640, int height = 480) : windowName(name) {
            try 
            {
            // Window NORMAL adjusts window size to allow resizing
            cv::namedWindow(windowName, cv::WINDOW_NORMAL);
            
            // Set an initial default size
            cv::resizeWindow(windowName, width, height);
            } catch (const cv::Exception &e) {
                throw std::runtime_error("OpenCV Window Init Error: " + std::string(e.what()));
            }

        }

        // Destructor: destroy the window when obj is out of scope
        ~Window() {
            try {
                cv::destroyWindow(windowName);
            } catch(...) {

            }
        }

        // Set a new size at any time
        void setDimensions(int width, int height) {
            cv::resizeWindow(windowName, width, height);
        }

        // Display a frame (we will pass acutal image data here later)
        void show(const cv::Mat& frame) {
            if (frame.empty()) throw std::invalid_argument("Cannot display an empty frame");
            cv::imshow(windowName, frame);
        }

};

#endif //WINDOW_H
