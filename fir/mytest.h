#ifndef _MYTEST_H
#define _MYTEST_H

#include<iostream>
#include<opencv2/opencv.hpp>
#include<omp.h>
#include<xmmintrin.h>
#include"define.h"

using namespace cv;
using namespace std;

class CMytest
{
public:
	unsigned int unRoot;
	float sqrtNum;
	int *dina;
	int *dinb;
	int *dout;
	int size;
	float *op1;
	float *op2;
	float *op3;

	CMytest();
	CMytest(const CMytest &C);
	//openMP测试函数
	void TestOfOpenmp(const int *dina, const int *dinb, int *dout, const int &size);
	//SSE测试函数
	void TestOfSSE(const float *op1, const float *op2, float *op3, const int &size);

	//求平方根 仅保留整数位
	unsigned int QuickSqrtUN(unsigned int unRoot);

	// Carmack在QUAKE3中使用的计算平方根的函数
	float QuickSqrtF(float sqrtNum);

	//最精简的1/sqrt()函数,精度较高
	float QuickInvSqrt(float sqrtNum);



	~CMytest();
};

#endif