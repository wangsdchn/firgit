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
	int *dina;
	int *dinb;
	int *dout;
	int size;
	float *op1;
	float *op2;
	float *op3;

	CMytest()
	{
		dina = new int[N];
		memset(dina,0,sizeof(int)*N);
		dinb = new int[N];
		memset(dinb, 0, sizeof(int)*N);
		dout = new int[N];
		memset(dout, 0, sizeof(int)*N);
		size = 0;
		op1 = NULL;
		op2 = NULL;
		op3 = NULL;
	}
	/*CMytest(const CMytest &C)
	{
		dina = new int;
		*dina = *(C.dina);
		dinb = new int;
		*dinb = *(C.dinb);
		dout = new int;
		*dout = *(C.dout);
		size = C.size;
		op1 = C.op1;
		op2 = C.op2;
		op3 = C.op3;
	}*/
	//openMP²âÊÔº¯Êý
	void TestOfOpenmp(const int *dina, const int *dinb, int *dout, const int &size);
	//SSE²âÊÔº¯Êý
	void TestOfSSE(const float *op1, const float *op2, float *op3, const int &size);

	~CMytest()
	{
		if (dina) { delete []dina; dina = NULL; }
		if (dinb) { delete []dinb; dinb = NULL; }
		if (dout) { delete []dout; dout = NULL; }
		if (NULL != op1)  op1 = NULL;
		if (NULL != op2)  op2 = NULL;
		if (NULL != op3)  op3 = NULL;
	};
};

#endif