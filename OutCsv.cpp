/*
* ִ�иú���ǰ��Ӧ����ѵ��������Ŀ¼����cmdִ�� dir /b/s *.pgm *.jpg >at.txt
* Ȼ�����ݼ��ļ�������Ͷ����һ��at.txt�ļ�������������ֻ��·��û�б�ǩ��
* 
* Ĭ������ǩ������Ϊѵ��������ǩ����ǩĬ�ϸ�ʽΪ1��2��3��4......
* �ú��������ڲ��ԣ������ǩ�ɵ���Ӧ�ļ��������޸�
* loadg��ʽΪ"C:/Users/user/Desktop/",���ļ�������Ϊat.txt
*/
#include"myhead.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int OutCsv(string load)
{
	string fin = load+"at.txt";//��ȡ�ļ�λ��
	string fout = load+"out.txt";//�洢�ļ�λ��

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