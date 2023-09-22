#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include<iostream>
using namespace std;
using namespace cv;

Mat Picture2Gray(Mat im2gray) {
    Mat im1(im2gray.rows, im2gray.cols,CV_8U);
    for (int i = 0; i < im2gray.rows; i++) {
        for (int j = 0; j < im2gray.cols; j++) {
            im1.at<uchar>(i, j) = 0.299 * im2gray.at<Vec3b>(i, j)[2] + 0.587 *im2gray.at<Vec3b>(i, j)[1] + 0.114 *im2gray.at<Vec3b>(i, j)[0];
        }
    }
    return im1;
}
int main()
{
    Mat inputImage = imread("C://Users//凱駿//Documents//GitHub//license_plate_recognition//test//testcar1.bmp",IMREAD_COLOR);

<<<<<<< HEAD
=======
       waitKey();
       // Remap Image
       for (Idx=0; Idx < size; Idx ++ ){

           homeX=Idx % Numcols;
           homeY=Idx / Numcols;
           //tranImg.at<uchar>(homeY, homeX) =0;
           if(TransArry[Idx] != -1){
               //cout << "Index " << Idx << "Passed " << endl;
               int newhomeX=TransArry[Idx] % Numcols; // Col ID
               int newhomeY=TransArry[Idx] / Numcols;  // Row ID


                cout << "Index is " << Idx << endl;
                cout << "HomeX is " << homeX << " and HomeY is " << homeY << endl;
                cout << "New Index is " << TransArry[Idx] << endl;
                cout << "New HomeX is " << newhomeX << " and New HomeY is " << newhomeY << endl;
                cout << "*****************************************"<< endl;
               // if (!(Idx%100)) sleep(20);

               tranImg.at<uchar>(newhomeY, (newhomeX*channels)) = A.at<uchar>(homeY, homeX*channels);
               if(channels>1)
                   tranImg.at<uchar>(newhomeY, newhomeX*channels+1) = A.at<uchar>(homeY, homeX*channels+1);
               if(channels>2)
                   tranImg.at<uchar>(newhomeY, newhomeX*channels+2) = A.at<uchar>(homeY, homeX*channels+2);
               // if (!(Idx%100)){
                   // imshow("inside", tranImg);
                   // waitKey(1);
                   // }
               }
       }
       //cout << tranImg << endl;

return tranImg;

}

int main()
{
    Mat inputImage = imread("C://Users//凱駿//Documents//GitHub//license_plate_recognition//test//testcar1.bmp",IMREAD_COLOR);
    Mat outputImg;
    transform(inputImage,outputImg);
>>>>>>> 1125011182f25ef031e4a5e27d2f30f095a3d3b4
    cout<<"hello world\n";
    cout<<"test";
}
