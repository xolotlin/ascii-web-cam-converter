#ifndef WEBCAM_H
#define WEBCAM_H

#include <opencv2/opencv.hpp>
#include <iostream>

class Webcam {

    private:
        cv::VideoCapture cap;
        int deviceID;
    public:
        // open camera device (0 is default primary camera)
        Webcam(int deviceIdx = 0) : deviceID(deviceIdx) {
            cap.open(deviceID);
            if (!cap.isOpened()) {
                std::cerr << "Error: can't open webcam device index " << deviceID << "\n";
            }
        }

        // release hardware device
        ~Webcam() {
            if (cap.isOpened()) {
                cap.release();
            }
        }
        
        // Check if camera opened
        bool isReady() const {
            return cap.isOpened();
        }

        // Read a frame into OpenCV Mat obj safely
        bool getFrame(cv::Mat frame) {
            if (!cap.isOpened()) return false;

            cap.read(frame);

            // Ensure frame is non-empty before proceeding
            if (frame.empty()) {
                std::cerr << "Warning: Blank frame grabbed.\n";
                return false;
            }

            return true;
        }
};

#endif