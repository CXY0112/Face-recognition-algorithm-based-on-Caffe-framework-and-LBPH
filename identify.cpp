/*
* ��cppʵ������ʶ��ļ��غ�ʶ���ܣ������������Ӻ������ֱ����Eigenfaces��Fisherfaces �;ֲ���ֵģʽֱ��ͼ (LBPH)�㷨
* �Լ�һ����ʾʶ��Ч���ĺ���
* �����ԣ�Fisherfaces�㷨ʶ���ٶ����,LBPH�㷨��׼ȷ
* 
* ����˵����
* int LBPH_Identify(std::string photo, std::string mymodel);
* photo Ϊʶ���ͼƬ�� mymodelΪ���ص�ģ�ͣ�.xml�ļ���
* �޲ε���ʱ��ͼƬΪE:\\CXY's Projects\\ORL\\s41\\10.jpg �� ģ��ΪE:\\CXY's Projects\\ORL\\����Ӧ��ģ��
* 
* void show(std::string load, int x1, int x2, int y1, int y2, std::string name)
* loadΪͼƬ��ַ��x,yΪ���������沿�����꣬nameΪ��Ӧ������
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


int Identify_Fisherfaces(string photo ,string mymodel) //��Լ2s�����
{
	// 2�����������ͼ�����ݺͶ�Ӧ�ı�ǩ        
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

int Identify_Eigenfaces(string photo, string mymodel)//��Լ��Ҫ12s
{
	// 2�����������ͼ�����ݺͶ�Ӧ�ı�ǩ        
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

int Identify_LBPH(string photo, string mymodel)//��Լ12��
{
	// 2�����������ͼ�����ݺͶ�Ӧ�ı�ǩ        
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

int Identify_LBPH()//��Լ12��
{
	// 2�����������ͼ�����ݺͶ�Ӧ�ı�ǩ        
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

int Identify_Fisherfaces() //��Լ2s�����
{
	// 2�����������ͼ�����ݺͶ�Ӧ�ı�ǩ        
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

int Identify_Eigenfaces()//��Լ��Ҫ12s
{
	// 2�����������ͼ�����ݺͶ�Ӧ�ı�ǩ        
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
		cout << "��ȡͼƬ����������������ȷ·����\n";
		system("pause");
		return ;
	}
	
	rectangle(img, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 255), 5, 8);
	putText(img, name, Point(x1+1, y2+10), FONT_HERSHEY_COMPLEX, 2, (0, 250, 250),5);
	imwrite(load, img);
	namedWindow("Ԥ����", WINDOW_NORMAL);
	imshow("Ԥ����", img);
	waitKey(0);
}