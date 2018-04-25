#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

Mat g_srcImage, g_dstImage, g_midImage;
vector<Vec4i> g_lines;
int g_nthreshold = 100;

static void on_HoughLines(int,void*)

int main()
{
	Mat g_srcImage = imread("1.jpg");
	imshow("origin picture",g_srcImage);
	namedWindow("result picture",1);
	createTrackbar("value","result picture",&g_nthreshold,200,on_HoughLines);
	Canny(g_srcImage, g_midImage, 50, 200, 3);
	cvtColor(g_midImage, g_dstImage, COLOR_GRAY2BGR);

	on_HoughLines(g_nthreshold,0);
	HoughLinesP(g_midImage, g_lines, 1, CV_PI / 180, 80, 50, 10);
	imshow("result picture",g_dstImage);
	
	waitKey(0);
	
	return 0;
}

static void on_HoughLines(int, void *)
{
	Mat dstImage = g_dstImage.clone();
	Mat midImage = g_midImage.clone();

	
}