#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;

int main()
{
	Mat srcImage = imread("1.jpg",0);
	imshow("origin", srcImage);
	int m = getOptimalDFTSize(srcImage.rows);
	int n = getOptimalDFTSize(srcImage.cols);

	Mat padded;

	copyMakeBorder(srcImage,padded,0,m-srcImage.rows,0,n-srcImage.cols,BORDER_CONSTANT,Scalar::all(0));

	Mat planes[] = { Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F) };

	Mat complexI;
	merge()
}