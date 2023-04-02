/*
* 该cpp将照相获得的图片预处理为训练算法需要的图片，存放在“load”中，以备训练模型使用
* 图片名必须为i.jpg格式，i从1开始
* Normalized(int x,string load)
* 参数说明：
* x为需要处理图片数量，load为图片读取和存储路径
*/
#include"myhead.h"
#include <opencv2/highgui/highgui.hpp>                      
#include <opencv2/imgproc/imgproc.hpp>        
#include<opencv2/dnn.hpp>
#include <iostream>   
#include<string>
using namespace std;
using namespace cv;

int Normalized(int x, string load)
{
	Mat img, myface;
	int i = 1;
	Mat img_gray;
	//读取图片
	while (i < x + 1)
	{
		img = imread(load + to_string(i) + ".jpg");
		if (!img.data)
		{
			cout << "读取图片错误，请重新输入正确路径！\n";
			system("pause");
			return -1;
		}

		//获得脸部图像坐标
		string root = "E:/OpenCV/opencv/sources/samples/dnn/face_detector/";
		dnn::Net net = cv::dnn::readNetFromTensorflow(root + "opencv_face_detector_uint8.pb", root + "opencv_face_detector.pbtxt");
		Mat blob = dnn::blobFromImage(img, 1.0, Size(300, 300), Scalar(104, 177, 123), 0, 0);
		net.setInput(blob);
		Mat probs = net.forward();
		Mat detection(probs.size[2], probs.size[3], CV_32F, probs.ptr<float>());
		Mat index;
		for (int i = 0; i < detection.rows; i++)
		{
			float confidence = detection.at<float>(i, 2);
			if (confidence > 0.5)
			{
				int x1 = static_cast<int>(detection.at<float>(i, 3) * img.cols);
				int y1 = static_cast<int>(detection.at<float>(i, 4) * img.rows);
				int x2 = static_cast<int>(detection.at<float>(i, 5) * img.cols);
				int y2 = static_cast<int>(detection.at<float>(i, 6) * img.rows);
				Rect m_select;
				m_select = Rect(x1 - 30, y1 - 30, x2 - x1 + 50, y2 - y1 + 50);
				index = img(m_select);
			}
		}
		//灰度处理，调整大小输出
		cvtColor(index, img_gray, COLOR_BGR2GRAY);
		resize(img_gray, myface, Size(92, 112));
		string  str = load + to_string(i) + ".jpg";
		imwrite(str, myface);

		i++;
	}
	return 1;
}

//返回了图像脸部边界坐标，为了后文中显示检测结果
int Normalized(int x,string load, int& a, int& b, int& c, int& d)
{
	Mat img, myface;
	int i = 1;
	Mat img_gray;
	//读取图片
	while(i < x+1)
	{
		img = imread(load +to_string(i)+".jpg");
		if (!img.data)
		{
			cout << "读取图片错误，请重新输入正确路径！\n";
			system("pause");
			return -1;
		}

		//获得脸部图像坐标
		string root = "E:/OpenCV/opencv/sources/samples/dnn/face_detector/";
		dnn::Net net = cv::dnn::readNetFromTensorflow(root + "opencv_face_detector_uint8.pb", root + "opencv_face_detector.pbtxt");
		Mat blob = dnn::blobFromImage(img, 1.0, Size(300, 300), Scalar(104, 177, 123), 0, 0);
		net.setInput(blob);
		Mat probs = net.forward();
		Mat detection(probs.size[2], probs.size[3], CV_32F, probs.ptr<float>());
		Mat index;
		for (int i = 0; i < detection.rows; i++)
		{
			float confidence = detection.at<float>(i, 2);
			if (confidence > 0.5)
			{
				int x1 = static_cast<int>(detection.at<float>(i, 3) * img.cols);
				int y1 = static_cast<int>(detection.at<float>(i, 4) * img.rows);
				int x2 = static_cast<int>(detection.at<float>(i, 5) * img.cols);
				int y2 = static_cast<int>(detection.at<float>(i, 6) * img.rows);
				a = x1, b = x2, c = y1, d = y2;
				Rect m_select;
				m_select = Rect(x1 - 30, y1 - 30, x2 - x1 + 50, y2 - y1 + 50);
				index= img(m_select);
			}
		}
				//灰度处理，调整大小输出
				cvtColor(index, img_gray, COLOR_BGR2GRAY);
				resize(img_gray, myface, Size(92, 112));
				string  str = load+to_string(i)+".jpg";
				imwrite(str, myface);
				
		i++;
	}
	return 1;
}