#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("G:\\picture\\22.jpg");
	cv::Mat dispMat(160, 300, CV_8UC3, Scalar(255,255,255));
	cv::Point pt1; cv::Point pt2; cv::Point pt3; cv::Point pt4;
	int height = srcMat.rows;
	int width = srcMat.cols;
	int r = 0; int g = 0; int b = 0; 
	int mul = 3000;
	float histgram_r[256] = { 0 }; float histgram_g[256] = { 0 }; float histgram_b[256] = { 0 };
	for (int t = 0; t < 256; t++)
	{
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				if (srcMat.at<Vec3b>(j, i)[0] == t)
					histgram_b[t]++;
				if (srcMat.at<Vec3b>(j, i)[1] == t)
					histgram_g[t]++;
				if (srcMat.at<Vec3b>(j, i)[2] == t)
					histgram_r[t]++;
			}
		}
		histgram_r[t] = histgram_r[t] / (height*width);
		histgram_g[t] = histgram_g[t] / (height*width);
		histgram_b[t] = histgram_b[t] / (height*width);
		pt1.x = t; pt1.y = 150;
		pt2.x = t; pt2.y = 150 - histgram_r[t] * mul;
		pt3.x = t; pt3.y = 150 - histgram_g[t] * mul;
		pt4.x = t; pt4.y = 150 - histgram_b[t] * mul;
		line(dispMat, pt1, pt2, CV_RGB(255, 0, 0), 1, 8, 0);
		line(dispMat, pt1, pt3, CV_RGB(0, 255, 0), 1, 8, 0);
		line(dispMat, pt1, pt4, CV_RGB(0, 0, 255), 1, 8, 0);
	}
	imshow("Ö±·½Í¼", dispMat);
	waitKey(0);
}
