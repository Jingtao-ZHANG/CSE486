#include <iostream>
#include <opencv2/opencv.hpp>
#include <Python.h>

using namespace std;
using namespace cv;


int main() {
    Mat srcImage = imread("../srcImage.jpeg", IMREAD_COLOR);

    if (srcImage.empty()){
        cout << "Picture doesn't exist or cannot be loaded." << endl;
        return -1;

    }
    else{
        imshow("original image", srcImage);

        // transform RGB image to gray image
        Mat ImageGray;
        cvtColor(srcImage, ImageGray, COLOR_RGB2GRAY);
        imshow("gary image", ImageGray);

        // or using 7 lines of code behind to transform RGB to gray
        Mat srcImageGray = imread("../srcImage.jpeg", IMREAD_GRAYSCALE);
        if (!srcImageGray.data){
            cout << "Picture doesn't exist or cannot be converted to Gray image." << endl;
        }
        else{
            imshow("original gray image", srcImageGray);
        }

        imwrite("temp.png", srcImageGray);
        cout << srcImageGray.cols << endl;
        cout << srcImageGray.rows << endl;

        waitKey(0);

//        Py_Initialize();
//        PyRun_SimpleString("import matplotlib.pyplot as plt");
//        PyRun_SimpleString("import sys");
//        PyRun_SimpleString("sys.path.append('./')");//这一步很重要，修改Python路径
//        PyRun_SimpleString("image = cv2.imread('temp.png')");
//        PyRun_SimpleString("xLength = image.shape[0]");
//        PyRun_SimpleString("yLength = image.rows[1]");
//        PyRun_SimpleString("zLength = 255");
//        PyRun_SimpleString("print(xLength)");
//        PyRun_SimpleString("print(yLength)");
//        PyRun_SimpleString("plt.plot([1,2,3,4], [12,3,23,231])");
//        PyRun_SimpleString("plt.show()");
//        Py_Finalize();

        return 0;
    }

}


