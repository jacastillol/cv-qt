/*

  Turn on the id=0 camera and close it pressing ESC
  To compile this code:

  g++ -o test_cam <filename.cpp> -I/path/to/include/opencv \
      -L/path/to/lib/opencv  \
      -lopencv_core -lopencv_videoio -lopencv_highgui

 */

#include <iostream>
#include "opencv2/opencv.hpp"
 
using namespace std;
using namespace cv;
 
int main()
{
  VideoCapture cap(0);
  if(!cap.isOpened()) {
    return -1;
  }
 
  while(1) {
    Mat frame;
    cap >>frame;
 
    if (frame.empty())
      break;
 
    imshow( "Frame", frame );
 
    char c = (char)waitKey(25);
    if(c==27) // ESC
      break;
  }
 
  cap.release();
  destroyAllWindows();
 
  return 0;
}
