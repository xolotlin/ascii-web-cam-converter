# (ASCII-VISION) Live ASCII Webcam Stream in C++

A real-time ASCII camera converter

## Prerequisites

- **C++ Compiler:** GCC or Clang (C++17 or higher)
- **CMake:** Version 3.10 or higher
- **OpenCV:** Version 4.x

```bash
sudo apt update
sudo apt install build-essential cmake libopencv-dev
```

Clone this repository and navigate to the directory

Create a build folder and compile:

```bash
mkdir build && cd build
cmake ..
make
```

Run the Application

```bash
./ascii_vision
```

To quit/exit. Focus on the OpenCV preview window and press ESC to stop the program.