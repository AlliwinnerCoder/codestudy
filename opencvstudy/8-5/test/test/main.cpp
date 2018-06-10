#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;

#define WINDOW_NAME1 "origin windows"
#define WINDOW_NAME2 "result windows"

Mat g_srcImage;
Mat g_grayImage;
int g_nThresh = 50;
int g_nMaxThresh = 255;
RNG g_rng(12345);

void on_ContoursChange(int, void *);

int main()
{
	g_srcImage = imread("1.jpg", 1);
	cvtColor(g_srcImage,g_grayImage,COLOR_BGR2GRAY);
	blur(g_grayImage, g_grayImage, Size(3, 3));
	namedWindow(WINDOW_NAME1, WINDOW_AUTOSIZE);
	imshow(WINDOW_NAME1, g_srcImage);
	createTrackbar("value:",WINDOW_NAME1,&g_nThresh,g_nMaxThresh,on_ContoursChange);
	on_ContoursChange(0, 0);
	waitKey(0);
	return 0;
}

void on_ContoursChange(int, void *)
{
	Mat threshold_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	threshold(g_grayImage,threshold_output,g_nThresh,255,THRESH_BINARY);
	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	vector<vector<Point>> contours_poly(contours.size());
	vector<Rect>boundRect(contours.size());
	vector<Point2f>center(contours.size());
	vector<float>radius(contours.size());

	for (unsigned int i = 0; i < contours.size(); i++)
	{

	}
}