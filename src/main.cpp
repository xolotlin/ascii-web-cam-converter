/*
 * ASCII VISION: Cam to ASCII project
 * Made by Amaru M. Mendez
 * Date created in 8.30.2026
 **/

#include <opencv2/imgproc/imgproc.hpp>
#include "window.h"
#include "webcam.h"

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#define __OPTIMIZE_IO__ std::ios_base::sync_with_stdio(false); cin.tie(nullptr);

// ASCII characters sorted by visual density (dark to light)
const std::string CHAR_SET = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

// Mapping function: maps [0, 255] to character index [0, CHAR_SET.size() - 1]
char mapPixeltoAscii(uint8_t pixelValue) {
    const float scale = static_cast<float>(CHAR_SET.size() - 1) / 255.0f;
    int index = static_cast<int>(pixelValue * scale);
    return CHAR_SET[index];
}

// Convert a raw frame into ASCII strings of art
std::string frameToAscii(const cv::Mat& inputFrame, int outputWidth = 120) {
    cv::Mat grayFrame;
    cv::Mat resizedFrame;

    // Convert BGR image to GrayScale
    cv::cvtColor(inputFrame, grayFrame, cv::COLOR_BGR2GRAY);

    // Adjust for terminal font aspect ration (font height is roughly 2x width)
    int outputHeight = static_cast<int>(outputWidth * (static_cast<float>(grayFrame.rows) / grayFrame.cols) * 0.5f);

    cv::resize(grayFrame, resizedFrame, cv::Size(outputWidth, outputHeight), 0,0, cv::INTER_AREA);
    std::string asciiBuffer = "";
    asciiBuffer.reserve((resizedFrame.cols + 1) * resizedFrame.rows);

    for (int r = 0; r < resizedFrame.rows; ++r) {
        for (int c = 0; c < resizedFrame.cols; ++c) {
            uint8_t brightness = resizedFrame.at<uint8_t>(r, c);
            asciiBuffer += mapPixeltoAscii(brightness);
        }

        asciiBuffer += "\n";
    }

    return asciiBuffer;
}

int main() {
    __OPTIMIZE_IO__
    
    try {
        Webcam camera(0);

        if (!camera.isReady()) {
            std::cerr << "Exiting: Camera is not available.\n";
            return -1;
        }

        std::cout << "Initializing window...\n";

        // Instantiate our window wrapper with initial size 800x600
        Window previewWindow("Webcame Preview", 800, 600);
        cv::Mat rawFrame;

        std::cout << "Window created succesfully. Press ESC in the terminal to exit.\n";

        for(;;) {
            // grab frame safely
            camera.getFrame(rawFrame);

            // display raw frame
            previewWindow.show(rawFrame);

            std::string asciiFrame = frameToAscii(rawFrame, 100);

            std::cout << "\033[H" << asciiFrame << std::flush;

            //waitKey(30) waits 30 ms and listens for user key events (~33 FPS loop rate)
            // 27 == ESC
            if (cv::waitKey(30) == 27) break;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }

    return 0;
}
