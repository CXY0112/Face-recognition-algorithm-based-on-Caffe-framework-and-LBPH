#include <string>

//����x�ţ��ո�ץ�ģ��������load��
void TakePhoto(int x,std::string load);
void TakePhoto(std::string load);

//��ȡͼƬ������ֵΪͼƬ����
std::string getPhoto(std::string load);

//�����load�е�ͼƬ����ȡ�������Ҷȴ���(�洢ΪCV_U8��ʽ���ٴ�ʹ�ò�Ҫ����ת�Ҷ�ͼ)�������load�У�xΪͼƬ����
int Normalized(int x,std::string load,int& a,int& b,int& c,int& d);
int Normalized(int x,std::string load);

//�������ݼ�����λ����cmdִ��dir /b/s *.pgm *.jpg >at.txt,Ȼ��ִ�д˺���Ϊ�������ϳ�ʼ��ǩ��Ĭ�ϱ�ǩΪ1��2��3��4�ȵȣ�
int OutCsv(std::string load);

//ģ��ѵ��
int doTrain(std::string load);

//ʶ��ģ��
int Identify_LBPH();//׼ȷ�����
int Identify_LBPH(std::string photo, std::string mymodel= ".\\model\\MyFaceLBPHModel.xml");

int Identify_Fisherfaces();//���
int Identify_Fisherfaces(std::string photo, std::string mymodel= ".\\model\\MyFaceFisherModel.xml");

int Identify_Eigenfaces();
int Identify_Eigenfaces(std::string photo, std::string mymodel= ".\\model\\MyFacePCAModel.xml");

//��ʾʶ��Ľ��
void predict_show(std::string load, int x1, int x2, int y1, int y2,std::string name);