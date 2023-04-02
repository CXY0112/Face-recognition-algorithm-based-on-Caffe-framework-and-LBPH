/*
* 本cpp用于拍照，TakePhoto(string load) ，load为照片存储路径
*/
#include"myhead.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void TakePhoto(string load) 
{
	string writePath = load;
	VideoCapture capture(0);
	string name;
	namedWindow("Photo", WINDOW_NORMAL);
	int i = 1;
	cout << "按下空格键拍照" << endl;
	while (1) {
		Mat frame;
		capture >> frame;
		if (32 == waitKey(20)) {			//空格拍照
			name = writePath + to_string(i) + ".jpg";
			//medianBlur(frame, frame, 3);
			imwrite(name, frame);
			imwrite(writePath + "face.jpg",frame);
			cout << "已拍照完成，请等待..." << endl;
			i++;
		}
		if (i==2) {		
			break;
		}
		imshow("Photo", frame);

	}
	//waitKey(0);
}

void TakePhoto(int x, string load)
{
	string writePath = load;
	VideoCapture capture(0);
	string name;
	namedWindow("Photo", WINDOW_NORMAL);
	int i = 1;
	cout << "按下空格键拍照" << endl;
	while (1) {
		Mat frame;
		capture >> frame;
		if (32 == waitKey(20)) {			//空格拍照
			name = writePath + to_string(i) + ".jpg";
			//medianBlur(frame, frame, 3);
			imwrite(name, frame);
			cout << "已经拍照，再次按下空格键继续拍照" << endl;
			i++;
		}
		if (i == x+1) 
		{
			cout << "已拍照完成，请等待..." << endl;
			break;
		}
		imshow("Photo", frame);
	}
}

std::string getPhoto(std::string load)
{
	string writePath = load;
	Mat img=imread(load);		
	if (!img.data)
	{
		cout << "读取图片错误，请重新输入正确路径！\n";
		system("pause");
		return "";
	}
	flip(img, img, 1);
	imwrite(".\\Photo\\1.jpg", img);
	imwrite(".\\Photo\\face.jpg", img);
	return ".\Photo\\";
}