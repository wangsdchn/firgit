#include "mytest.h"
#include "add.h"
#include<time.h>
using namespace cv;
using namespace std;

#define N 16
int main()
{
	CMytest test1;
	_MM_ALIGN16 float src1[N] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 };
	_MM_ALIGN16 float src2[N] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 };
	_MM_ALIGN16 float src3[N] = { 0.0 };
	int size = N;
	test1.op1 = src1;
	test1.op2 = src2;
	test1.op3 = src3;
	clock_t time1 = clock();
	//for (int j = 0; j < 10000000; j++){
		//cout << j << endl;
	test1.TestOfSSE(test1.op1, test1.op2, test1.op3, size);
	//}
	for (auto i : src3)
		cout << i << endl;
	clock_t time2 = clock();
	cout << (double)(time2 - time1) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}