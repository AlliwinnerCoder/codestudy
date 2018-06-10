#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;

int main()
{
	Mat image(600, 600, CV_8UC3);
	RNG& rng = theRNG();
	while (1)
	{
		int count = rng.uniform(3, 103);
		vector<Point> points;
		for (int i = 0; i < count; i++)
		{
			Point point;
			point.x = rng.uniform(image.cols / 4, image.cols * 3 / 4);
			point.y = rng.uniform(image.rows / 4, image.rows * 3 / 4);

			points.push_back(point);
		}

		Point2f center;
		float radius = 0;
		minEnclosingCircle(Mat(points), center, radius);
		image = Scalar::all(0);
		for (int i = 0; i < count; i++)
		{
			circle(image, points[i], 3, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), FILLED, LINE_AA);
		}
		circle(image, center, cvRound(radius), Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),2,LINE_AA);
		imshow("radius", image);
		char key = (char)waitKey();
		if (key == 27 || key == 'q' || key == 'Q')
			break;
	}
	return 0;
}