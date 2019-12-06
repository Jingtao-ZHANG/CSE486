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

        /*
         * Above-mentioned filters are low pass filters, which are linear operators.
         * Then, a media pass filter is presented.
         * MedianBLur is a non-linear operator, where the statistical median of each point in the neighborhood is
         * the output. This filter can effectively remove salt and pepper noise. It also keeps the boundaries of
         * the objects in the image from being blurred.
         */

        // example of median blur filter
        Mat ImageByMedianBlur;
        medianBlur(srcImage, ImageByMedianBlur, 7);
        imshow("smoothed by median blur filter", ImageByMedianBlur);

        /*
         * We can customize the filter kernel using the function of "cv::filter2D" or "cv::sepFilter2D".
         * The "filter2D" uses a square kernel, while "sepFilter2D" uses a X kernel and a Y kernel.
         */
        // example of customize a Gaussian filter
        Mat GaussianKernel3By1 = getGaussianKernel(5, 0.8);  // get a one dimension Gaussian kernel
        Mat GaussianKernel1By3 = GaussianKernel3By1.t();
        // use filter2D
        Mat CustomizedGaussianKernel = GaussianKernel3By1 * GaussianKernel1By3;
        cout << CustomizedGaussianKernel << endl;
        Mat ImageByCustomizedKernel1;
        filter2D(srcImage, ImageByCustomizedKernel1, srcImage.depth(), CustomizedGaussianKernel);
        imshow("smoothed by customized filter using square kernel", ImageByCustomizedKernel1);
        // use seqFilter2D
        Mat ImageByCustomizedKernel2;
        sepFilter2D(srcImage, ImageByCustomizedKernel2, srcImage.depth(), GaussianKernel3By1, GaussianKernel1By3);
        imshow("smoothed by customized filter using separate kernel", ImageByCustomizedKernel2);

        waitKey(0);

        return 0;
    }

}
