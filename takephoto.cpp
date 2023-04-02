/*
* ��cpp�������գ�TakePhoto(string load) ��loadΪ��Ƭ�洢·��
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
	cout << "���¿ո������" << endl;
	while (1) {
		Mat frame;
		capture >> frame;
		if (32 == waitKey(20)) {			//�ո�����
			name = writePath + to_string(i) + ".jpg";
			//medianBlur(frame, frame, 3);
			imwrite(name, frame);
			imwrite(writePath + "face.jpg",frame);
			cout << "��������ɣ���ȴ�..." << endl;
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
	cout << "���¿ո������" << endl;
	while (1) {
		Mat frame;
		capture >> frame;
		if (32 == waitKey(20)) {			//�ո�����
			name = writePath + to_string(i) + ".jpg";
			//medianBlur(frame, frame, 3);
			imwrite(name, frame);
			cout << "�Ѿ����գ��ٴΰ��¿ո����������" << endl;
			i++;
		}
		if (i == x+1) 
		{
			cout << "��������ɣ���ȴ�..." << endl;
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
		cout << "��ȡͼƬ����������������ȷ·����\n";
		system("pause");
		return "";
	}
	flip(img, img, 1);
	imwrite(".\\Photo\\1.jpg", img);
	imwrite(".\\Photo\\face.jpg", img);
	return ".\Photo\\";
}