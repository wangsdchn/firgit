#ifndef _MYTEST_H
#define _MYTEST_H

#include<iostream>
#include<opencv2/opencv.hpp>
#include<omp.h>
#include<xmmintrin.h>

#define USE_SSE
using namespace cv;
using namespace std;

class CMytest
{
public:
	int a = 0;
	int b = 0;
	int c = 0;
	float *op1 = NULL;
	float *op2 = NULL;
	float *op3 = NULL;

	void TestOfOpenmp(const int &a);

	void TestOfSSE(float *op1,float *op2, float *op3,int &size);

};

#endif