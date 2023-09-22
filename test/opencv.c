#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("C://Users//凱駿//Documents//GitHub//license_plate_recognition//test//testcar1.bmp",IMREAD_COLOR);
    cvtColor(inputImage, gray, COLOR_BGR2GRAY);
    //find threshold
    for(size_t y=0;y<gray.rows;y+=block){
        for(size_t x=0;x<gray.cols;x+=block){
            tot=0;
            for(int i=0;i<block;i++){
                for(int j=0;j<block;j++){
                    unsigned char* row_ptr=gray.data+(y+i)*gray.cols;
                    tot+=row_ptr[x+j];
                }
            }
            th=tot/(block*block)*0.6;
    //binarization
            for(int i=0;i<block;i++){
                for(int j=0;j<block;j++){
                    unsigned char* row_ptr=gray.data+(y+i)*gray.cols;
                    if(row_ptr[x+j]>th){
                        row_ptr[x+j]=255;
                    }
                    else{
                        row_ptr[x+j]=0;
                    }
                }
            }
        }
     }
    imshow("Gray",gray);
    
    cout<<"hello world\n";
    cout<<"test";
}
