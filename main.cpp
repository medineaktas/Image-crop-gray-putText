#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  float x = 5.0;


  Mat image;
  Mat greyMat;

  Mat img_converted;
  image = imread("00001.jpg", IMREAD_COLOR);
  if (!image.data)
  {
    cout << "Could not open or find the image" << endl;
    return -1;
  }
    imshow("img", image);

  int offset_x = 0;
  int offset_y = 0;

  Rect roi;
  roi.x = offset_x;
  roi.y = offset_y;
  //roi.width = image.size().width - (offset_x*2);
  //roi.height = image.size().height - (offset_y*2);
  roi.width = image.size().width/2;
  roi.height = image.size().height;


  Mat crop = image(roi);

cvtColor(crop, greyMat, CV_BGR2GRAY);
putText(greyMat, "Hello World", cvPoint(30,40), 
    FONT_HERSHEY_COMPLEX_SMALL, 0.9, cvScalar(0,0,255,255), 1);

  imshow("crop", greyMat);
  waitKey(0);


  return 0;
}