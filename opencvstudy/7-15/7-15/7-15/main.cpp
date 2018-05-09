#include<opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace cv;
using std::vector;

int main(int argc, char ** argv)
{
	Mat srcImage = imread("1.jpg", 0);
	imshow("origin picture",srcImage);

	Mat dstImage = Mat::zeros(srcImage.rows, srcImage.cols, CV_8UC3);
	srcImage = srcImage > 119;
	imshow("origin picture",srcImage);

	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(srcImage, contours, hierarchy, CV_RETR_CCOMP,CHAIN_APPROX_SIMPLE);
	int index = 0;
	for (; index >= 0; index = hierarchy[index][0])
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dstImage, contours, index, color, FILLED, 8, hierarchy);
	}
	imshow("result picture",dstImage);
	waitKey(0);
}