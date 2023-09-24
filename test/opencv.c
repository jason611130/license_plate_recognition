#include <iostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/highgui/highgui_c.h>
using namespace cv;
using namespace std;
int main(int argc, const char * argv[]) {
    Point2f srcTri[4];
    Point2f dstTri[4];
    Mat warpPerspective_mat(3,3,CV_32FC1);
    Mat src = imread("/Users/michelle/Documents/Michelle/NTUST專題/car.png",0);
    Mat warpPerspective_dst;
    warpPerspective_dst=Mat::zeros(src.rows,src.cols,src.type());
    
    srcTri[0]=Point2f(src.cols*0.45,src.rows*0.65);
    srcTri[1]=Point2f(src.cols*0.65,src.rows*0.8);
    srcTri[2]=Point2f(src.cols*0.45,src.rows*0.8);
    srcTri[3]=Point2f(src.cols*0.65,src.rows*0.95);
    
    dstTri[0]=Point2f(src.cols*0.2,src.rows*0.3);
    dstTri[1]=Point2f(src.cols*0.8,src.rows*0.4);
    dstTri[2]=Point2f(src.cols*0.17,src.rows*0.79);
    dstTri[3]=Point2f(src.cols*0.815,src.rows*0.82);
    warpPerspective_mat=getPerspectiveTransform(srcTri,dstTri);
    warpPerspective(src,warpPerspective_dst,warpPerspective_mat,src.size());
    imshow("inputImg",src);
    imshow("outputImg",warpPerspective_dst);
   
    waitKey(0);
    return 0;
}


      
