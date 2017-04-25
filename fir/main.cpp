
#include<omp.h>
#include "mytest.h"
#include "add.h"
#include<time.h>
#include<vector>
#include <windows.h>
using namespace cv;
using namespace std;
void ch(int *p){ cout << *p << endl; int *p1; p1 = p; *p1 = 4; cout << *p << endl; };
int main()
{
	LARGE_INTEGER m_StartTime;
	LARGE_INTEGER m_EndTime;
	LARGE_INTEGER m_Freq;
	QueryPerformanceFrequency(&m_Freq);
	CMytest test1;
	test1.unRoot = 50;
	test1.sqrtNum = 3.0;
	int a = 1;
	float b;
	////======================================
	//QueryPerformanceCounter(&m_StartTime);
	//for (int i = 0; i < 1000000; i++)
	//	b = test1.QuickInvSqrt(test1.sqrtNum);
	//QueryPerformanceCounter(&m_EndTime);
	//cout << b << " "<<(double)(m_EndTime.QuadPart-m_StartTime.QuadPart)/m_Freq.QuadPart << endl;

	////=======================================
	//QueryPerformanceCounter(&m_StartTime);
	//for (int i = 0; i < 1000000; i++)
	//	b = 1/sqrtf(test1.sqrtNum);
	//QueryPerformanceCounter(&m_EndTime);
	//cout << b << " " << (double)(m_EndTime.QuadPart - m_StartTime.QuadPart) / m_Freq.QuadPart << endl;
	Mat src = imread("E:\\BIN.BMP",0);
	system("pause");
	return 0;
}