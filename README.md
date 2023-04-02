# Face-recognition-algorithm-based-on-Caffe-framework-and-LBPH
	人脸识别算法应用说明
本算法应用是基于 Caffe 框架和 LBPH 算法实现的人脸识别应用。在此应用中，我们使用了
基于 Caffe 框架训练的深度学习模型进行人脸检测，接着使用 LBPH 算法对检测出的人脸进
行识别，并使用 k 近邻分类器作为分类模型。 功能描述
本应用可以快速准确地检测出输入图像中的人脸，并适应不同的人脸大小、角度和姿态。
支持将已有图片和实时拍照两种方式作为测试集来进行人脸识别。
本应用具有检测速度快、识别准确率高、扩展性强等优点，适用于人脸门禁系统、人脸支付
等场景，提高系统的安全性和便利性。 技术实现
本应用使用基于 Caffe 框架训练的深度学习模型进行人脸检测。该模型使用了卷积神经网络
（CNN）进行特征提取和分类，并使用非极大值抑制（NMS）算法对检测结果进行后处理。
接着，我们将检测出的人脸图像输入到 LBPH 算法中进行人脸识别。LBPH 算法是一种基于
局部二值模式（LBP）的人脸识别算法，它可以对输入的人脸图像进行特征提取和匹配，从
而实现人脸识别的功能。在 LBPH 算法中，我们使用了 k 近邻分类器作为分类模型，用于将
特征向量映射到人脸识别的结果上。 测试集数据来源
我们使用了 ORL 人脸集和本组中参赛人员的照片作为训练集。
本应用支持两种方式获取测试集：读取已有图片和实时拍照。 使用方法
解压“DNNface.rar”文件，使用 visual studio 运行，若运行失败，可能是 opencv 安装不完
整，确实需要的 DNN 库，请解压“DNNinstall.rar”，并按照 readme.txt 中步骤进行安装。
若需要重新录入人脸数据，请注释主函数，并取消注释“temp.cpp”文件，按照注释内容进
行收入运行录入。
