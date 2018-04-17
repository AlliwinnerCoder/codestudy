#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

#define WINDOW_NAME "program windows"

Mat g_srcImage, g_dstImage, g_tmpImage;

int main()
{
	g_srcImage = imread("1.jpg");
	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
	imshow(WINDOW_NAME, g_srcImage);

	g_tmpImage = g_srcImage;
	g_dstImage = g_tmpImage;
	int key = 0;
	while (1)
	{
		key = waitKey(9);
		switch (key)
		{
		case 27:
			return 0;
			break;
		case 'q':
			return 0;
			break;
		case 'a':
			pyrUp(g_tmpImage, g_dstImage, Size(g_tmpImage.cols*2,g_tmpImage.rows*2));
			printf("check A");
			break;
		case 'w':
			resize(g_tmpImage, g_dstImage, Size(g_tmpImage.cols * 2, g_tmpImage.rows * 2));
			printf("check B");
			break;
		case '1':
			resize(g_tmpImage, g_dstImage, Size(g_tmpImage.cols * 2, g_tmpImage.rows * 2));
			printf("check 1");
			break;
		case '3':
			resize(g_tmpImage, g_dstImage, Size(g_tmpImage.cols * 2, g_tmpImage.rows * 2));
			printf("check 3");
			break;
		case 'd':
			pyrDown(g_tmpImage, g_dstImage, Size(g_tmpImage.cols / 2, g_tmpImage.rows / 2));
			printf("check d");
			break;
		case 's':
			pyrDown(g_tmpImage, g_dstImage, Size(g_tmpImage.cols / 2, g_tmpImage.rows / 2));
			printf("check s");
			break;
		case '2':
			resize(g_tmpImage,g_dstImage,Size(g_tmpImage.cols/2,g_tmpImage.rows/2),(0,0),(0,0),2);
			printf("check 2");
			break;
		case '4':
			pyrDown(g_tmpImage,g_dstImage,Size(g_tmpImage.cols/2,g_tmpImage.rows/2));
			printf("check 4");
			break;
		}
		imshow(WINDOW_NAME, g_dstImage);
		g_tmpImage = g_dstImage;
	}
	return 0;
}