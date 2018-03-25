#include"opencv2/imgproc/imgproc.hpp"
#include<opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

static void on_ContrastAndBright(int, void *);
static void ShowHelpText();

int g_nContrastValue;
int g_nBrightValue;

Mat g_srcImage, g_dstImage;

int main()
{
	g_srcImage = imread("1.jpg");
	g_dstImage = Mat::zeros(g_srcImage.size(),g_srcImage.type());
	g_nContrastValue = 80;
	g_nBrightValue = 80;

	namedWindow("picture",1);
	createTrackbar("Contrast:","picture",&g_nContrastValue,300,on_ContrastAndBright);
	createTrackbar("Bright:","picture",&g_nBrightValue,200, on_ContrastAndBright);

	on_ContrastAndBright(g_nContrastValue, 0);
	on_ContrastAndBright(g_nBrightValue, 0);

	while (char(waitKey(1)) != 'q') {}
	return 0;
}

static void on_ContrastAndBright(int, void *)
{
	namedWindow("origin picture",1);
	for (int y = 0; y < g_srcImage.rows; y++)
	{
		for (int x = 0; x < g_srcImage.cols; x++)
		{
			for (int c = 0; c < 3; c++) 
			{
				g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y,x)[c]) + g_nBrightValue);
			}
		}
	}

	imshow("origin picture", g_srcImage);
	imshow("picture", g_dstImage);
}