/*
* 本cpp实现人脸识别的加载和识别功能，包括了三个子函数，分别采用Eigenfaces，Fisherfaces 和局部二值模式直方图 (LBPH)算法
* 以及一个显示识别效果的函数
* 经测试，Fisherfaces算法识别速度最快,LBPH算法最准确
* 
* 参数说明：
* int LBPH_Identify(std::string photo, std::string mymodel);
* photo 为识别的图片， mymodel为加载的模型（.xml文件）
* 无参调用时，图片为E:\\CXY's Projects\\ORL\\s41\\10.jpg ， 模型为E:\\CXY's Projects\\ORL\\中相应的模型
* 
* void show(std::string load, int x1, int x2, int y1, int y2, std::string name)
* load为图片地址，x,y为左上右下面部的坐标，name为对应的人名
*/
#include "myhead.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "opencv2/face.hpp"
#include "opencv2/core.hpp"
using namespace cv;
using namespace cv::face;
using namespace std;


int Identify_Fisherfaces(string photo ,string mymodel) //大约2s内完成
{
	// 2个容器来存放图像数据和对应的标签        
	Mat testSample = imread(photo);
	cvtColor(testSample, testSample, COLOR_BGR2GRAY);

	String index = mymodel;
	Ptr<FaceRecognizer> model = FisherFaceRecognizer::create();
	model = Algorithm::load<FisherFaceRecognizer>(index);

	int predictedLabel = model->predict(testSample);

	//string result_message = format("Predicted class = %d  Actual class = 35.", predictedLabel);
	//cout << result_message << endl;

	return predictedLabel;
}

int Identify_Eigenfaces(string photo, string mymodel)//大约需要12s
{
	// 2个容器来存放图像数据和对应的标签        
	Mat testSample = imread(photo);
	cvtColor(testSample, testSample, COLOR_BGR2GRAY);

	const String index = mymodel;
	Ptr<FaceRecognizer> model = EigenFaceRecognizer::create();
	model = Algorithm::load<EigenFaceRecognizer>(index);

	int predictedLabel = model->predict(testSample);

	//string result_message = format("Predicted class = %d  Actual class = 35.", predictedLabel);
	//cout << result_message << endl;

	return predictedLabel;
}

int Identify_LBPH(string photo, string mymodel)//大约12秒
{
	// 2个容器来存放图像数据和对应的标签        
	Mat testSample = imread(photo);
	cvtColor(testSample, testSample, COLOR_BGR2GRAY);

	const String index = mymodel;
	Ptr<FaceRecognizer> model = LBPHFaceRecognizer::create();
	model = Algorithm::load<LBPHFaceRecognizer>(index);
	
	int predictedLabel = model->predict(testSample);

	//string result_message = format("Predicted class = %d  Actual class = 35.", predictedLabel);
	//cout << result_message << endl;

	return predictedLabel;
}

int Identify_LBPH()//大约12秒
{
	// 2个容器来存放图像数据和对应的标签        
	Mat testSample = imread("E:\\CXY's Projects\\ORL\\s41\\10.jpg");
	cvtColor(testSample, testSample, COLOR_BGR2GRAY);

	String index = ".\\model\\MyFaceLBPHModel.xml";
	Ptr<FaceRecognizer> model = LBPHFaceRecognizer::create();
	model = Algorithm::load<LBPHFaceRecognizer>(index);

	int predictedLabel = model->predict(testSample);
	string result_message = format("Predicted class = %d  Actual class = 35.", predictedLabel);
	cout << result_message << endl;
	return predictedLabel;
}

int Identify_Fisherfaces() //大约2s内完成
{
	// 2个容器来存放图像数据和对应的标签        
	Mat testSample = imread("E:\\CXY's Projects\\ORL\\s41\\10.jpg");
	cvtColor(testSample, testSample, COLOR_BGR2GRAY);
	
	String index = ".\\model\\MyFaceFisherModel.xml";
	Ptr<FaceRecognizer> model = FisherFaceRecognizer::create();
	model = Algorithm::load<FisherFaceRecognizer>(index);

	int predictedLabel = model->predict(testSample); 
	string result_message = format("Predicted class = %d  Actual class = 35.", predictedLabel);
	cout << result_message << endl;
	return predictedLabel;
}

int Identify_Eigenfaces()//大约需要12s
{
	// 2个容器来存放图像数据和对应的标签        
	Mat testSample = imread("E:\\CXY's Projects\\ORL\\s41\\10.jpg");
	cvtColor(testSample, testSample, COLOR_BGR2GRAY);

	String index = ".\\model\\MyFacePCAModel.xml";
	Ptr<FaceRecognizer> model = EigenFaceRecognizer::create();
	model = Algorithm::load<EigenFaceRecognizer>(index);

	int predictedLabel = model->predict(testSample);
	string result_message = format("Predicted class = %d  Actual class = 35.", predictedLabel);
	cout << result_message << endl;
	return predictedLabel;
}

void predict_show(std::string load, int x1, int x2, int y1, int y2, std::string name)
{
	Mat img;
	img = imread(load);
	if (!img.data)
	{
		cout << "读取图片错误，请重新输入正确路径！\n";
		system("pause");
		return ;
	}
	
	rectangle(img, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 255), 5, 8);
	putText(img, name, Point(x1+1, y2+10), FONT_HERSHEY_COMPLEX, 2, (0, 250, 250),5);
	imwrite(load, img);
	namedWindow("预测结果", WINDOW_NORMAL);
	imshow("预测结果", img);
	waitKey(0);
}