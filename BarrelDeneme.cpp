#include <iostream>
#include <cstdlib>
#include "opencv2/opencv.hpp"
#include "../../../Desktop/barrel-distortion-cpp-master/barrel_distortion.hpp"

int main(int argc, char** argv)
{
	using namespace std;
	using namespace cv;

	Mat input, output;
	float K;
	float centerX, centerY;
	int width, height;

	input = imread("C:\\Users\\seyda\\Downloads\\fishermen.jpg", IMREAD_COLOR);
	output = Mat(input.rows, input.cols, input.type());
	K = 0.000001;
	width = input.cols;
	height = input.rows;
	centerX = width / 2;
	centerY = height / 2;

	barrelDistortion barrel = barrelDistortion(input, output,
		K, centerX, centerY, width, height);
	barrel.barrel_distort();

	// show output
	imshow("distorted", output);
	waitKey();

	return 0;
}