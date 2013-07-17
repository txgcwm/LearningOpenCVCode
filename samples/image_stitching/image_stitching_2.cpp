#include <iostream>
#include <fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/stitcher.hpp"

using namespace std;
using namespace cv;


int main(int argc, char **argv)
{
	string srcFile[3] = {"1.jpg", "2.jpg", "3.jpg"};
	string dstFile = "image_stitching_2.jpg";
	vector < Mat > imgs;

	for (int i = 0; i < 3; ++i) {
		Mat img = imread(srcFile[i]);
		if (img.empty()) {
			cout << "Can't read image '" << srcFile[i] << "'\n";
			return -1;
		}
		imgs.push_back(img);
	}

	cout << "Please wait..." << endl;
	Mat pano;
	Stitcher stitcher = Stitcher::createDefault(false);
	Stitcher::Status status = stitcher.stitch(imgs, pano);

	if (status != Stitcher::OK) {
		cout << "Can't stitch images, error code=" << int (status) << endl;
		return -1;
	}

	imwrite(dstFile, pano);
	namedWindow("Result");
	imshow("Result", pano);
	waitKey(0);
	destroyWindow("Result");

	return 0;
}
