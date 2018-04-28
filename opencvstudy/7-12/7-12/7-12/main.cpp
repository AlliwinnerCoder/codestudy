#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace cv;
using namespace std;

#define WINDOW_NAME1 "origin windows"
#define WINDOW_NAME2 "Warp picture"
#define WINDOW_NAME3 "Warp and Rotate picture"

int main()
{
	Point2f srcTriangle[3];
	Point2d dstTriangle[3];

	Mat rotMat(2, 3, CV_32FC1);
	Mat warpMat(2, 3, CV_32FC2);
	Mat srcImage, dstImage_warp, dstImage_warp_rotate;

	srcImage = imread("1.jpg", 1);
	dstImage_warp = Mat::zeros(srcImage.rows, srcImage.cols, srcImage.type());
	srcTriangle[0] = Point2f(0, 0);
	srcTriangle[1] = Point2f(static_cast<float>(srcImage.cols - 1), 0);
	srcTriangle[2] = Point2f(0, static_cast<float>(srcImage.rows - 1));

	dstTriangle[0] = Point2f(static_cast<float>(srcImage.cols*0.0), static_cast<float>(srcImage.rows*0.33));
	dstTriangle[1] = Point2f(static_cast<float>(srcImage.cols*0.65), static_cast<float>(srcImage.rows*0.35));

}