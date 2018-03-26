#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3, g_dstImage4, g_dstImage5;
int g_nBoxFilterValue = 6;
int g_nMeanBlurValue = 10;
int g_nGaussianBlurValue = 6;
int g_nMedianBlurValue = 0;
int g_nBilateralFilterValue = 10;

static void on_BoxFilter(int, void *);
static void on_MeanBlur(int, void *);
static void on_GaussianBlur(int, void *);
static void on_MedianBlur(int, void *);
static void on_BilateralFilter(int, void *);

int main()
{
	g_srcImage = imread("1.jpg",1);

	g_dstImage1 = g_srcImage.clone();
	g_dstImage2 = g_srcImage.clone();
	g_dstImage3 = g_srcImage.clone();
	g_dstImage4 = g_srcImage.clone();
	g_dstImage5 = g_srcImage.clone();
	
	namedWindow("origin picture", 1);
	imshow("origin picture",g_srcImage);

	namedWindow("BoxFilter", 1);
	createTrackbar("coreValue:","BoxFilter",&g_nBoxFilterValue,50,on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue,0);
	imshow("BoxFilter",g_dstImage1);

	namedWindow("MeanFilter", 1);
	createTrackbar("coreValue:","MeanFilter",&g_nMeanBlurValue,50,on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue,0);

	namedWindow("GaussianFilter",1);
	createTrackbar("CoreValue:","GaussianFilter",&g_nGaussianBlurValue,50,on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue,0);

	namedWindow("MedianFilter", 1);
	createTrackbar("CoreValue:", "MedianFilter", &g_nMedianBlurValue, 50, on_MedianBlur);
	on_MedianBlur(g_nGaussianBlurValue, 0);

	namedWindow("BilateralFilter",1);
	createTrackbar("CoreValue","BilateralFilter",&g_nBilateralFilterValue,50, on_BilateralFilter);
	on_BilateralFilter(g_nBilateralFilterValue,0);
	
	while (char(waitKey(1)) != 'q') {}
	return 0;
}

static void on_BoxFilter(int, void *)
{
	boxFilter(g_srcImage, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	imshow("BoxFilter",g_dstImage1);
}

static void on_MeanBlur(int, void *)
{
	blur(g_srcImage, g_dstImage2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1,-1));
	imshow("MeanFilter",g_dstImage2);
}

static void on_GaussianBlur(int, void *)
{
	GaussianBlur(g_srcImage, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("GaussianFilter",g_dstImage3);
}

static void on_MedianBlur(int, void *)
{
	medianBlur(g_srcImage, g_dstImage4, g_nMedianBlurValue * 2 + 1);
	imshow("MedianFilter", g_dstImage4);
}

static void on_BilateralFilter(int, void *)
{
	bilateralFilter(g_srcImage,g_dstImage5,g_nBilateralFilterValue,g_nBilateralFilterValue*2,g_nBilateralFilterValue/2);
	imshow("BilateralFilter",g_dstImage5);
}