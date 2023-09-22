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
Mat transform(Mat A, Mat H)
{
// allocate array of all locations
int Numrows = A.rows;
int Numcols = A.cols;
int channels   = A.channels();
cout << "rows " << Numrows << "col " << Numcols << "channels " << channels <<endl;
int size = Numrows*Numcols;
int MaxX,MaxY = -1000;
int MinX,MinY =  1000;
int *TransArry = (int *)malloc(sizeof(int)*size);
int Idx;

int homeX=Idx % Numcols;
int homeY=Idx / Numcols;
cout << H << endl;

waitKey();
for (Idx=0; Idx < size; ++Idx ){

       homeX=Idx % Numcols;
       homeY=Idx / Numcols;

       float x  = (H.at<float>(0,0) * (homeX)) +( H.at<float>(0,1) * (homeY)) + ( H.at<float>(0,2) * 1) ;
       float y  = (H.at<float>(1,0) * (homeX)) +( H.at<float>(1,1) * (homeY)) + ( H.at<float>(1,2) * 1) ;
       float s  = (H.at<float>(2,0) * (homeX)) +( H.at<float>(2,1) * (homeY)) + ( H.at<float>(2,2) * 1) ;

       cout << " x = " << x << " y= " << y << " s= " << s;
       x = (x/s);

       y = y/s;

       // for the first col in TransMatrix
       if (homeX ==0){
           if (x > MaxX) MaxX = x;
           if (x < MinX) MinX = x;
       }

       //for thee first row in TransMatrix
       if (homeY ==0){
           if (y > MaxY) MaxY = y;
           if (y < MinY) MinY = y;
       }
       if((y)>=A.rows || (y)<0 || (x)>=A.cols || (x)<0){
           TransArry[Idx]  = -1;
           cout << "x= " << x << "y= "<< y << endl;
       }else{
           TransArry[Idx] = (y * Numcols + x);
       }

       //cout << Numcols << endl;
       cout <<     "New index of " << Idx << "is " << TransArry[Idx] << endl;
       }

        Mat   tranImg ;

        A.copyTo(tranImg);
        tranImg = tranImg - tranImg;
       cout <<     "Rows" << tranImg.rows << "cols" << tranImg.cols << "cha" <<  A.channels() << endl;


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
    
    Mat outputImg;
    transform(inputImage,outputImg);
    cout<<"hello world\n";
    cout<<"test";
}