#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("1.jpg");
	Mat midImage, dstImage;
	Canny(srcImage,midImage,50,200,3);
	cvtColor(midImage, dstImage, COLOR_GRAY2BGR);

	vector<Vec4i> lines;
	HoughLinesP(midImage, lines, 1, CV_PI / 180, 80, 50, 10);

	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		Scalar(186, 88, 255);
		line(dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186,88,255),1,LINE_AA);
	}
	imshow("origin pisture", srcImage);
	imshow("result picture1",midImage);
	imshow("result picture2",dstImage);
	waitKey(0);
	return 0;
}