#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main() {
    Mat srcImage = imread("../srcImage.jpeg");

    if(srcImage.empty())
    {
        cout << "Image cannot be loaded..." << endl;
        return 0;
    }
    else
    {
        imshow("original image", srcImage);

        // example of box filter
        Mat ImageByBoxFilter;
        boxFilter(srcImage, ImageByBoxFilter, -1, Size(5, 5));
        imshow("smoothed by box filter", ImageByBoxFilter);

        // example of blur filter
        // Blur an image means using normalized box filter to smooth an image.
        Mat ImageByBlur;
        blur(srcImage, ImageByBlur, Size(5, 5));
        imshow("smoothed by blur", ImageByBlur);

        // example of Gaussian filter
        Mat ImageByGaussianFilter;
        GaussianBlur(srcImage, ImageByGaussianFilter, Size(5, 5), 0.8, 0.8);
        imshow("smoothed by Gaussian filter", ImageByGaussianFilter);

        waitKey(0);

        return 0;
    }

}
