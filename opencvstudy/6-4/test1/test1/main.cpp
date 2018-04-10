#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat g_srcImage, g_dstImage, g_grayImage, g_maskImage;
int g_nFillMode = 1;
int g_nLowDifference = 20,g_nUpDifference = 20;
int g_nConnectivity = 4;
bool g_bIsColor = true;
bool g_bUseMask = false;
int g_nNewMaskVal = 255;

static void onMouse(int event, int x, int y, int, void *)
{
	if (event != CV_EVENT_LBUTTONDOWN)
		return;
	Point seed = Point(x, y);
	int LowDifference = g_nFillMode == 0 ? 0 : g_nLowDifference;
	int UpDifference = g_nFillMode == 0 ? 0 : g_nUpDifference;
	int flags = g_nConnectivity + (g_nNewMaskVal << 8) + (g_nFillMode == 1 ? CV_FLOODFILL_FIXED_RANGE : 0);

	int b = (unsigned)theRNG() & 255;
	int g = (unsigned)theRNG() & 255;
	int r = (unsigned)theRNG() & 255;

	Rect ccomp;
	Scalar newVal = g_bIsColor ? Scalar(b, g, r) : Scalar(r*0.299 + g*0.587 + b*0.114);
	Mat dst = g_bIsColor ? g_dstImage : g_grayImage;
	int area;
	if (g_bUseMask)
	{
		threshold(g_maskImage,g_maskImage,1,128,THRESH_BINARY);
		area = floodFill(dst,g_maskImage,seed,newVal,)
	}
}

int main()
{
	
}