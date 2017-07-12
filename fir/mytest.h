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
	//openMP���Ժ���
	void TestOfOpenmp(const int *dina, const int *dinb, int *dout, const int &size);
	//SSE���Ժ���
	void TestOfSSE(const float *op1, const float *op2, float *op3, const int &size);

	//��ƽ���� ����������λ
	unsigned int QuickSqrtUN(unsigned int unRoot);

	// Carmack��QUAKE3��ʹ�õļ���ƽ�����ĺ���
	float QuickSqrtF(float sqrtNum);

	//����1/sqrt()����,���Ƚϸ�
	float QuickInvSqrt(float sqrtNum);



	~CMytest();
};

#endif