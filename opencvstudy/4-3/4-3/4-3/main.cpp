#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

bool LinearBlending()
{
	double alphaValue = 0.5;
	double betaValue;
	Mat srcImage2, srcImage3, dstImage;
	srcImage2 = imread("1.jpg");
	srcImage3 = imread("2.jpg");

	betaValue = (1.0 - alphaValue);
	addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);

	namedWindow("origin picture",1);

	imshow("origin picture",srcImage2);

	namedWindow("origin fix picture",1);
	imshow("origin fix picture",dstImage);

	return true;
}
void main()
{
	double alphaValue = 0.5;
	double betaValue;
	Mat srcImage2, srcImage3, dstImage;
	srcImage2 = imread("1.jpg");
	srcImage3 = imread("1.jpg");

	betaValue = (1.0 - alphaValue);
	addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);

	namedWindow("origin picture", 1);

	imshow("origin picture", srcImage2);

	namedWindow("origin fix picture", 1);
	imshow("origin fix picture", dstImage);

	waitKey();
}