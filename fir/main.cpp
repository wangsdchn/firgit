
#include<omp.h>
#include "mytest.h"
#include "add.h"
#include "fileOps.h"
#include<time.h>
#include<vector>
//#include <windows.h>
#define _AFXDLL
#include <afxtempl.h>
#include <assert.h>
using namespace cv;
using namespace std;
void ch(int *p){ cout << *p << endl; int *p1; p1 = p; *p1 = 4; cout << *p << endl; };
void allocateMemory()
{
	int *p = new int[4000];
	ZeroMemory(p, 16000);
	Sleep(1);
}
void sizeOfPtr(char *p)
{
	assert(p != NULL);
	cout << strlen(p) << " " << sizeof(p) << endl;
}
int main()
{
	//string fileName = "E:\\gamma.txt";
	//float gamma = 1.25;
	//FileOps::CFileOp file(gamma,fileName);
	//file.getResult();
	CList<int, int&> CInt;
	for (int i = 0; i < 10; i++)
	{
		CInt.AddTail(i);
	}


	system("pause");
	return 0;
} 