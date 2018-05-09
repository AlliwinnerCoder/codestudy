#include<opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"

using namespace cv;
int main(int argc, char** argv)
{
	Mat srcImage, dstImage;
	srcImage = imread("1.jpg",0);
	cvtColor(srcImage, srcImage, COLOR_BGR2GRAY);
	imshow("origin picture", srcImage);
	equalizeHist(srcImage,dstImage);
	imshow("result picture",dstImage);
	waitKey(0);
	return 0;
}