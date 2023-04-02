#include <string>

//拍照x张，空格抓拍，并存放在load中
void TakePhoto(int x,std::string load);
void TakePhoto(std::string load);

//获取图片，返回值为图片副本
std::string getPhoto(std::string load);

//检测在load中的图片，提取人脸并灰度处理(存储为CV_U8格式，再次使用不要忘记转灰度图)，存放在load中，x为图片数量
int Normalized(int x,std::string load,int& a,int& b,int& c,int& d);
int Normalized(int x,std::string load);

//现在数据集所在位置用cmd执行dir /b/s *.pgm *.jpg >at.txt,然后执行此函数为数据贴上初始标签（默认标签为1，2，3，4等等）
int OutCsv(std::string load);

//模型训练
int doTrain(std::string load);

//识别模块
int Identify_LBPH();//准确度最高
int Identify_LBPH(std::string photo, std::string mymodel= ".\\model\\MyFaceLBPHModel.xml");

int Identify_Fisherfaces();//最快
int Identify_Fisherfaces(std::string photo, std::string mymodel= ".\\model\\MyFaceFisherModel.xml");

int Identify_Eigenfaces();
int Identify_Eigenfaces(std::string photo, std::string mymodel= ".\\model\\MyFacePCAModel.xml");

//显示识别的结果
void predict_show(std::string load, int x1, int x2, int y1, int y2,std::string name);