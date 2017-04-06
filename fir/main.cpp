#include "mytest.h"
#include "add.h"
#include "define.h"
#include<time.h>
#include<omp.h>
#include<vector>
using namespace std;

int main()
{
	CMytest test1;
	test1.unRoot = 50;
	test1.sqrtNum = 3.0;
	int a;
	float b;
	//======================================
	clock_t time1 = clock();
	for (int i = 0; i < 10000000; i++)
		b = test1.QuickInvSqrt(test1.sqrtNum);
	clock_t time2 = clock();
	cout << b << " "<<(double)(time2 - time1) << endl;
	//=======================================
	time1 = clock();
	for (int i = 0; i < 10000000; i++)
		b = 1/sqrtf(test1.sqrtNum);
	time2 = clock();
	cout << b << " " << (double)(time2 - time1) << endl;

	system("pause");
	return 0;
}