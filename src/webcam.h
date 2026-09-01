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
           try {
                cap.open(deviceIdx);
                if (!cap.isOpened()) {
                    throw std::runtime_error("Failed to open video capture device at index " + std::to_string(deviceIdx));
                }
            } catch(const cv::Exception& e) {
                throw std::runtime_error("OpenCV Videocapture error: " + std::string(e.what()));
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
        void getFrame(cv::Mat& frame) {
            if (!cap.isOpened()) {
                throw std::runtime_error("Webcam device is not open.");
            }

            try {
                cap.read(frame);
                if (frame.empty()) {
                    throw std::runtime_error("Captured a blank frame from webcam.");
                }
            } catch (const cv::Exception& e) {
                throw std::runtime_error("Frame capture error: " + std::string(e.what()));
            }
        }
};

#endif