#include <stdlib.h>
#include <string.h>
#include <highgui.h>
#include <cv.h>


int main(int argc, char **argv)
{
	int i;
	char *file[3] = {"1.jpg", "2.jpg", "3.jpg"};
	IplImage *pImg[3];
	IplImage *dstImg = NULL;

	for (i = 0; i < 3; ++i)
		pImg[i] = cvLoadImage(file[i]);

	int sw = pImg[0]->width;
	int sh = pImg[0]->height;

	dstImg = cvCreateImage(cvSize(sw * 3, sh), pImg[0]->depth, pImg[0]->nChannels);
	cvZero(dstImg);

	printf("Please wait...\n");

	for (i = 0; i < 3; ++i) {
		cvSetImageROI(dstImg, cvRect(i * sw, 0, sw, sh));
		cvCopy(pImg[i], dstImg);
		cvResetImageROI(dstImg);
	}

	cvNamedWindow("dstImg");
	cvShowImage("dstImg", dstImg);
	cvSaveImage("image_stitching_1.jpg", dstImg);
	cvWaitKey(0);
	
	for (i = 0; i < 3; ++i)
		cvReleaseImage(&pImg[i]);
		
	cvReleaseImage(&dstImg);
	cvDestroyWindow("dstImg");

	return 0;
}
