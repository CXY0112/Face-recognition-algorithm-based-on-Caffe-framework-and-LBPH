/*
* ����������������������ʶ�������C++��opencvģ�鿪��������ʹ�ñ���Ŀ����Ҫ��װopencv2,�Լ�opencv2/dnnģ��
* dnnģ��İ�װ�������Ѿ�������DNNinstall.rar��
* ��API���÷�����myhead.h
*/

#include <opencv2/highgui/highgui.hpp>                      
#include <opencv2/imgproc/imgproc.hpp>        
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>
#include <unordered_map>
#include<stdlib.h>
#include"myhead.h"

using namespace std;
using namespace cv;
using namespace dnn;

//��������ֵĹ�ϣ��
class Name {
public:
		Name()
		{
			umap.clear();
			X1 = 0;
			X2 = 0;
			Y1 = 0;
			Y2 = 0;
		}
		void insert(int num, string name);
		string find(int num);
		int X1,X2,Y1,Y2;
private:
		unordered_map<int, std::string> umap;	
};

string Name::find(int num)
{
	if (umap.find(num) != umap.end())
	{
		return umap.at(num);
	}
	return "NO People";
}

void Name::insert(int num,string name)
{
	umap.emplace(num, name);
}

void getname(Name& name)
{
	name.insert(35, "CXY");
	name.insert(36, "JPZ");
	name.insert(37, "FYQ");
}

int main()
{
	//ģ��ѵ��ģ��
	//Normalized(10,".\\ORL\\");
	//OutCsv(".\\ORL\\");
	//doTrain(".\\ORL\\"); //DNN2.cpp��

	string load = ".\\Photo\\";//����������в�����Ŀ¼����ֵΪĬ��ֵ
	int num = 0;
	Name name;
	getname(name);//����Ǻ����ֵĶ�Ӧ��ϵ��������
	
	//ͨ����ȡ�ļ���ͼƬ���ͼ
	//getPhoto("C:\\Users\\13741\\Desktop\\test\\4.jpg");

	//������ͨ�����ջ����Ƭ
	TakePhoto(".\\Photo\\");

	//�ȶ�ͼ����и�ʽ����
	Normalized(1, load, name.X1, name.X2, name.Y1, name.Y2);

	//ʶ��ͼ��
	//num=Identify_Fisherfaces(load+"1.jpg");//����ʶ��
	num = Identify_LBPH(load + "1.jpg");//׼ȷʶ��
	//num = Identify_Eigenfaces(load + "1.jpg");//ȡ��ʶ��
	
	//�����������ҵ���Ƕ�Ӧ������
	string thename = name.find(num);

	//��ʾ���
	system("cls");//�����������
	cout << "��ͼ����Ϊ: " <<thename<<endl;
	//cout << num << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	predict_show(load+"face.jpg", name.X1, name.X2, name.Y1, name.Y2,thename);

	return 1;
}
