//#include"myhead.h"
//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <math.h>
//#include "opencv2/face.hpp"
//#include "opencv2/core.hpp"
//using namespace cv;
//using namespace cv::face;
//using namespace std;
//
//    Ptr<FaceRecognizer> model = EigenFaceRecognizer::create();
//    model->train(images, labels);
//    model->save("MyFacePCAModel.xml");      
//    Ptr<FaceRecognizer> model1 = FisherFaceRecognizer::create();     
//    model1->train(images, labels);     
//    model1->save("MyFaceFisherModel.xml");      
//    Ptr<FaceRecognizer> model2 = LBPHFaceRecognizer::create();     
//    model2->train(images, labels);     
//    model2->save("MyFaceLBPHModel.xml");
////当然在这之前要先把之前图片和标签提取出来。这时候就是at.txt派上用场的时候了。
////使用CSV文件去读图像和标签，主要使用stringstream和getline方法
//static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
//    std::ifstream file(filename.c_str(), ifstream::in);
//    if (!file) {
//        string error_message = "No valid input file was given, please check the given filename.";         
//        //CV_Error(CV_StsBadArg, error_message);
//    }
//    string line, path, classlabel;
//    while (getline(file, line)) {
//        stringstream liness(line);
//        getline(liness, path, separator);
//        getline(liness, classlabel);
//        if (!path.empty() && !classlabel.empty()) {
//            images.push_back(imread(path, 0));
//            labels.push_back(atoi(classlabel.c_str()));
//        }
//    }
//}