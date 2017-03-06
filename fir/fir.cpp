#include<iostream>
#include<opencv2/opencv.hpp>
#include "add.h"
using namespace cv;
using namespace std;
int main()
{
	int a = 2;
	int b = 6;
	

	const size_t N=8;
	int c[N] = { 0 };
#ifndef _DEBUG
	cout << "Debug" << endl;
#endif
	Mat src = imread("0000.png");
	imshow("src",src);
	waitKey(0);
	//printf("%d\n",add(a,b));
	return 0;
}