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
	int *dina = NULL;
	int *dinb = NULL;
	int *dout = NULL; 
	int size;
	float *op1 = NULL;
	float *op2 = NULL;
	float *op3 = NULL;

	CMytest(int *a = 0, int *b = 0, int *c = 0, int N = 0, float *p1 = 0, float *p2 = 0, float*p3 = 0)
	{
		dina = a; dinb = b; dout = c; size = N;
		op1 = p1; op2 = p2; op3 = p3;
	}
	//openMP²âÊÔº¯Êý
	void TestOfOpenmp(const int *dina, const int *dinb, int *dout, const int &size);
	//SSE²âÊÔº¯Êý
	void TestOfSSE(const float *op1, const float *op2, float *op3, const int &size);

	~CMytest()
	{
		if (NULL != dina) dina = NULL;
		if (NULL != dinb) dinb = NULL;
		if (NULL != dout) dout = NULL;
		if (NULL != op1)  op1 = NULL;
		if (NULL != op2)  op2 = NULL;
		if (NULL != op3)  op3 = NULL;
	};
};

#endif