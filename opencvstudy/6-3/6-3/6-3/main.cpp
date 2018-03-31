#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat g_srcImage, g_dstImage;
int g_nElementShape = MORPH_RECT;

int g_nMaxIterationNum = 10;
int g_nOpenCloseNum = 0;
int g_nErodeDilateNum = 0;
int g_nTopBlackHatNum = 0;

static void on_OpenClose(int, void *);
static void on_ErodeDilate(int, void *);
static void on_TopBlackHat(int, void *);
static void ShowHelpText();


int main()
{
	g_srcImage = imread("1.jpg");
	namedWindow("origin picture");
	imshow("origin picture", g_srcImage);

	namedWindow("open/",1);

}