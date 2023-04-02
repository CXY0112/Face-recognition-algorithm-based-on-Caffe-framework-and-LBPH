/*
* 本程序用于人脸检测和人脸识别，其基于C++中opencv模块开发，若想使用本项目，需要安装opencv2,以及opencv2/dnn模块
* dnn模块的安装方法，已经放置于DNNinstall.rar中
* 各API调用方法见myhead.h
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

//标记与名字的哈希表
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
	//模型训练模块
	//Normalized(10,".\\ORL\\");
	//OutCsv(".\\ORL\\");
	//doTrain(".\\ORL\\"); //DNN2.cpp中

	string load = ".\\Photo\\";//程序处理过程中产生的目录，该值为默认值
	int num = 0;
	Name name;
	getname(name);//将标记和名字的对应关系插入类中
	
	//通过读取文件中图片获得图
	//getPhoto("C:\\Users\\13741\\Desktop\\test\\4.jpg");

	//还可以通过拍照获得照片
	TakePhoto(".\\Photo\\");

	//先对图像进行格式处理
	Normalized(1, load, name.X1, name.X2, name.Y1, name.Y2);

	//识别图像
	//num=Identify_Fisherfaces(load+"1.jpg");//快速识别
	num = Identify_LBPH(load + "1.jpg");//准确识别
	//num = Identify_Eigenfaces(load + "1.jpg");//取中识别
	
	//在名字类中找到标记对应的名字
	string thename = name.find(num);

	//显示结果
	system("cls");//输出窗口清屏
	cout << "该图像中为: " <<thename<<endl;
	//cout << num << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	predict_show(load+"face.jpg", name.X1, name.X2, name.Y1, name.Y2,thename);

	return 1;
}
