#include <opencv/highgui.h>

int main()
{
    IplImage*img=cvLoadImage("c:/micky.png");

    cvShowImage("img",img);
    cvWaitKey(0);

}
