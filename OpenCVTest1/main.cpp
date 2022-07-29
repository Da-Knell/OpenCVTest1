#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void main()
{
     //��ȡͼƬ��ʹ��ͼƬ�ľ���·�����ο��Լ���ͼ����Ŀ¼��
    string path = "C:\\Users\\Administrator\\Desktop\\1.jpg";
    Mat srcImg = imread(path);

    if (srcImg.empty()) {
        cout << "could not load image..." << endl;
    }

    imshow("Test2", srcImg);
    cout << srcImg.size() << endl;

    /////////////////////////////��ͼ////////////////////////////
    
    //����
    Mat BackImg(512, 512, CV_8UC3, Scalar(255, 255, 255));
    //Բ�Σ�Բ�ģ��뾶����ɫ�����Ƿ���䣩��
    circle(BackImg, Point(256, 256), 155, Scalar(0, 69, 255),FILLED);
    //����(���ϣ����£���ɫ����ϸ��
    rectangle(BackImg, Point(130, 266), Point(382, 286), Scalar(255, 0, 0), 2);
    //��(���ϣ����£���ɫ����ϸ��
    line(BackImg, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 4);
    //����(���£����壬�ֺţ���ɫ��
    putText(BackImg, "Knell", Point(130, 296), FONT_HERSHEY_COMPLEX, 0.75, Scalar(0, 0, 0));
    imshow("Img", BackImg);

    ////������С
    Mat resizeImg;
    resize(srcImg, resizeImg, Size(), 0.5, 0.5);
    imshow("resize", resizeImg);

    ////�ü���С
    Mat ImgCrop;
    Rect roi(100, 100, 300, 250);
    ImgCrop = srcImg(roi);
    imshow("ROI", ImgCrop);

    //////////////////////// ��ʾ�Ҷ�ͼ////////////////////////////
    Mat Gray;
    cvtColor(srcImg, Gray, COLOR_RGB2GRAY);
    imshow("G", Gray);

    ////ģ��
    Mat dst1, dst2, dst3;
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));//ģ����

        //��ʴ
    erode(srcImg, dst1, element);
    imshow("erode", dst1);

        //����
    dilate(srcImg, dst2, element);
    imshow("dilate", dst2);

        //�˲�
    blur(srcImg, dst3, Size(7,7));
    imshow("blur", dst3);

    //��Ե���
    Mat dst4,dst5;
    blur(srcImg, dst4, Size(12, 12));
    Canny(dst4, dst5, 7, 10, 3);//��С��ֵ/���ֵ/sobel����
    imshow("canny", dst5);

    //////////////////////////Video///////////////////////////
    string path1 = "d:\\jianpiandownload\\ĳ��ѧ�ĳ�����ڵ�4��.mp4";
    VideoCapture cap(path1);
    Mat Img;

    while (true) {
        cap.read(Img);
        imshow("image", Img);
        waitKey(5);
    }

    // �ȴ����ⰴ�����£�����Ӵ����ͼƬ��һ������
    waitKey(0);
}
