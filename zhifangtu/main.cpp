#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("G:\\picture\\11.png");
	cv::Mat dispMat(300, 300, CV_8UC3, Scalar(0, 0, 0));
	cv::Point pt1; cv::Point pt2; cv::Point pt3; cv::Point pt4;
	int height = srcMat.rows;
	int width = srcMat.cols;
	int tol = height*width;
	int r = 0; int g = 0; int b = 0; int mul = 250;
	float histgram_r[256] = { 0 }; float histgram_g[256] = { 0 }; float histgram_b[256] = { 0 };
	for (int t = 0; t < 256; t++)
	{
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				if (srcMat.at<Vec3b>(j, i)[0] == t)
					b++;
				if (srcMat.at<Vec3b>(j, i)[1] == t)
					g++;
				if (srcMat.at<Vec3b>(j, i)[2] == t)
					r++;
			}
		}
		histgram_r[t] = r / tol;
		histgram_g[t] = g / tol;
		histgram_b[t] = b / tol;
	}
	for (int k = 0; k < 256; k++)
	{
		pt1.x = k; pt1.y = 256;
		pt2.x = k; pt2.y = 256 - histgram_r[k] * mul;
		pt3.x = k; pt3.y = 256 - histgram_g[k] * mul;
		pt4.x = k; pt4.y = 256 - histgram_b[k] * mul;
		line(dispMat, pt1, pt2, CV_RGB(255, 0, 0), 1, 8, 0);
		line(dispMat, pt1, pt3, CV_RGB(0, 255, 0), 1, 8, 0);
		line(dispMat, pt1, pt4, CV_RGB(0, 0, 255), 1, 8, 0);
	}
	imshow("Ö±·½Í¼", dispMat);
	waitKey(0);
}
