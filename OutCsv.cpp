/*
* 执行该函数前，应该在训练集所在目录运行cmd执行 dir /b/s *.pgm *.jpg >at.txt
* 然后数据集文件夹下面就多出了一个at.txt文件，但是现在是只有路径没有标签的
* 
* 默认贴标签函数，为训练集贴标签，标签默认格式为1，2，3，4......
* 该函数多用于测试，具体标签可到相应文件中自行修改
* loadg格式为"C:/Users/user/Desktop/",且文件名必须为at.txt
*/
#include"myhead.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int OutCsv(string load)
{
	string fin = load+"at.txt";//读取文件位置
	string fout = load+"out.txt";//存储文件位置

	char words[200];
	ifstream ReadIn;
	fstream out;
	ReadIn.open(fin, ios::in);
	out.open(fout, ios::out | ios::trunc);
	if (!ReadIn)
	{
		std::cerr << "cannot open the file";
		return 0;
	}
	int x = 0;
	while (ReadIn.getline(words, 100))
	{
		out << words <<";"<<(x/10)<< endl;
		++x;
	}
	ReadIn.close();
	out.close();
	return 0;
}