#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat g_srcImage, g_dstImage;
int g_nTrackbarNumber = 0;
int g_nStructElementSize = 3;

void Process();
void on_TrackbarNumChange(int, void *);
void on_ElementSizeChange(int, void *);

int main()
{
	g_srcImage = imread("1.jpg");
	namedWindow("origin picture");
	imshow("origin picture",g_srcImage);
	namedWindow("result picture");

	Mat element = getStructuringElement(MORPH_RECT,Size(2*g_nStructElementSize+1,2*g_nStructElementSize+1),Point(g_nStructElementSize, g_nStructElementSize));
	erode(g_srcImage, g_dstImage, element);
	imshow("result picture",g_dstImage);

	createTrackbar("code:","result picture",&g_nTrackbarNumber,21, on_TrackbarNumChange);
	createTrackbar("corevalue", "result picture", &g_nStructElementSize, 21, on_ElementSizeChange);
	while (char(waitKey(1)) != 'q') {}
	
	return 0;
}

void Process()
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * g_nStructElementSize + 1, 2 * g_nStructElementSize + 1), Point(g_nStructElementSize,g_nStructElementSize));
	if (g_nTrackbarNumber == 0) {
		erode(g_srcImage, g_dstImage, element);
	}
	else {
		dilate(g_srcImage, g_dstImage, element);
	}
	imshow("result picture", g_dstImage);
}

void on_TrackbarNumChange(int,void *)
{
	Process();
}

void on_ElementSizeChange(int,void *)
{
	Process();
}