#include <iostream>
#include <fstream>
#include <vector>
#include <opencv2/opencv.hpp>
#include "Watermark_Text.h"

using namespace std;
using namespace cv;

int main()
{
	WaterMarkText wmt;

	// 原始图像
	Mat img = imread("./image/wallhaven-137628.jpg");
	imshow("org", img);

	// 原始图像傅里叶分解
	Mat imgFly = wmt.getWatermarkColorImage(img);
	imshow("imgOriFly", imgFly);
	imwrite("./image/imgOriFly.jpg", imgFly * 255);

	// 原始图像添加水印
	Mat result = wmt.addTextWatermarkColorImage(img, "CS SWJTU");
	imshow("result", result);

	// 水印实验一
	Mat resultsave = result * 255; // 保存之前乘以255
	imwrite("./image/resultsave-1.jpg", resultsave);
	Mat imgWatermark1 = imread("./image/resultsave-1.jpg");
	Mat imgFly1 = wmt.getWatermarkColorImage(imgWatermark1);
	imshow("testImgFly1", imgFly1);
	imwrite("./image/testImgFly1.jpg", imgFly1 * 255);

	imwrite("./image/resultsave-2.bmp", resultsave);
	Mat imgWatermark2 = imread("./image/resultsave-2.bmp");
	Mat imgFly2 = wmt.getWatermarkColorImage(imgWatermark2);
	imshow("testImgFly2", imgFly2);
	imwrite("./image/testImgFly2.bmp", imgFly2 * 255);

	cv::waitKey(0);
	return 0;
}