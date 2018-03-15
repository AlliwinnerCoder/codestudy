#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void colorReduce(Mat& inputImage, Mat& outputImage, int div);

int main()
{
	Mat srcImage = imread("1.jpg");
	imshow("origin picture", srcImage);

	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());

	double time0 = static_cast<double>(getTickCount());

	colorReduce(srcImage, dstImage, 32);

	time0 = ((double)getTickCount() - time0) / getTickFrequency();

	cout << "This method run time :" << time0 << "s" << endl;

	imshow("xiaoguo picture",dstImage);
	waitKey(0);
}

void colorReduce(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols * outputI
}