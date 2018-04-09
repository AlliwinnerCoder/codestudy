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

	namedWindow("open/close",1);
	namedWindow("erode",1);
	namedWindow("top", 1);

	g_nOpenCloseNum = 9;
	g_nErodeDilateNum = 9;
	g_nTopBlackHatNum = 2;

	createTrackbar("value","open/close",&g_nOpenCloseNum,g_nMaxIterationNum * 2 + 1,on_OpenClose);
	createTrackbar("value","erode",&g_nErodeDilateNum, g_nMaxIterationNum * 2 + 1, on_ErodeDilate);
	createTrackbar("value", "top", &g_nTopBlackHatNum, g_nMaxIterationNum * 2 + 1, on_TopBlackHat);

	while (1)
	{
		int c;

		on_OpenClose(g_nOpenCloseNum,0);
		on_ErodeDilate(g_nErodeDilateNum, 0);
		on_TopBlackHat(g_nTopBlackHatNum, 0);

		c = waitKey(0);
		if ((char)c == 'q' || (char)c == 27)
			break;
		if ((char)c == 49)
			g_nElementShape = MORPH_ELLIPSE;
		else if ((char)c == 50)
			g_nElementShape = MORPH_RECT;
		else if ((char)c == 51)
			g_nElementShape = MORPH_CROSS;
		else if ((char)c == ' ')
			g_nElementShape = (g_nElementShape + 1) % 3;
	}

	return 0;
}

static void on_OpenClose(int, void *)
{
	int offset = g_nOpenCloseNum - g_nMaxIterationNum;
	int Absolute_offset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	if (offset < 0)
		morphologyEx(g_srcImage, g_dstImage, MORPH_OPEN, element);
	else
		morphologyEx(g_srcImage, g_dstImage, MORPH_OPEN, element);
	imshow("open/close",g_dstImage);
}

static void on_ErodeDilate(int, void *)
{
	int offset = g_nOpenCloseNum - g_nMaxIterationNum;
	int Absolute_offset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	if (offset < 0)
		erode(g_srcImage, g_dstImage, element);
	else
		dilate(g_srcImage, g_dstImage,element);
	imshow("erode", g_dstImage);
}

static void on_TopBlackHat(int, void *)
{
	int offset = g_nOpenCloseNum - g_nMaxIterationNum;
	int Absolute_offset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	if (offset < 0)
		morphologyEx(g_srcImage, g_dstImage, MORPH_TOPHAT, element);
	else
		morphologyEx(g_srcImage, g_dstImage, MORPH_BLACKHAT, element);
	imshow("top", g_dstImage);
}