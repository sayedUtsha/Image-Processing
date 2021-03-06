#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <math.h>


using namespace std;
using namespace cv;


int main() {

	Mat image = imread("lap.tif");
	cvtColor(image, image, CV_BGR2GRAY);
	imshow("Input1", image);
	waitKey(0);

	float kernel[9] = {-1,-1,-1,-1,8,-1,-1,-1,-1};

	Mat kern = Mat(3, 3, CV_32F, kernel);
	Mat out,out2;
	filter2D(image, out, CV_32F, kern, Point(-1, -1));
	imshow("Filter", out);
	/*for (int i = 0; i < out.rows; i++)
	{
		for (int j = 0; j < out.cols; j++)
		{
			//int a = (int)out.at<uchar>(Point(j, i));
			out.at<float>(Point(j, i)) = abs(out.at<float>(Point(j, i)));
		}
	}*/
	normalize(out, out2, 0, 255, NORM_MINMAX, CV_8U);
	imshow("out1", out2);
	//imshow("out1", out2);
	//Mat fin;
	//addWeighted(image,0.5,out,0.5,0,fin);
	Mat fin = image + out2;

	imshow("Final", fin);
	waitKey(0);


}
