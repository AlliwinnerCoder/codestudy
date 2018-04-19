#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

Mat g_srcImage, g_srcGrayImage, g_dstImage;

Mat g_cannyDelectedEdges;
int g_cannyLowThreshold = 1;

Mat g_sobelGradient_X, g_sobelGrandient_Y;
Mat g_sobelAbsGradient_X, g_sobelAbsGradient_Y;
int g_sobelKernelSize = 1;

Mat g_scharrGradient_X, g_scharrGrandient_Y;
Mat g_scharrAbsGradient_X, g_scharrAbsGradient_Y;

static void on_Canny(int, void *);
static void on_Sobel(int, void *);

int main(int argc, char** argv)
{
	g_srcImage = imread("1.jpg");
	namedWindow("origin picture");
	imshow("origin picture",g_srcImage);

	g_dstImage.create(g_srcImage.size(),g_srcImage.type());
	cvtColor(g_srcImage,g_srcGrayImage,COLOR_BGR2GRAY);

	namedWindow("result Canny Check",WINDOW_AUTOSIZE);
	namedWindow("result Sobel Check",WINDOW_AUTOSIZE);

	createTrackbar("value:","result Canny Check",&g_cannyLowThreshold,120,on_Canny);
	createTrackbar("value:","result Sobel Check",&g_sobelKernelSize,3,on_Sobel);

	on_Canny(0, 0);
	on_Sobel(0, 0);

	while ((char(waitKey(1))) != 'q') {}
	return 0;
}

void on_Canny(int, void *)
{
	blur(g_srcGrayImage, g_cannyDelectedEdges, Size(3, 3));
	Canny(g_cannyDelectedEdges, g_cannyDelectedEdges, g_cannyLowThreshold, g_cannyLowThreshold * 3.3);
	g_dstImage = Scalar::all(0);
	g_srcImage.copyTo(g_dstImage, g_cannyDelectedEdges);
	imshow("result Canny Check",g_dstImage);
}

void on_Sobel(int, void *)
{
	Sobel(g_srcImage, g_sobelGradient_X, CV_16S, 1, 0, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_X, g_sobelAbsGradient_X);
	Sobel(g_srcImage,g_sobelGrandient_Y,CV_16S,0,1,(2*g_sobelKernelSize + 1),1,1,BORDER_DEFAULT);
	convertScaleAbs(g_sobelGrandient_Y, g_sobelAbsGradient_Y);

	addWeighted(g_sobelAbsGradient_X,0.5,g_sobelAbsGradient_Y,0.5,0,g_dstImage);
	imshow("result Sobel Check",g_dstImage);
}

