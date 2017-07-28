
#include<omp.h>
#include "mytest.h"
#include "add.h"
#include "fileOps.h"
#include<time.h>
#include<vector>
#include <windows.h>
using namespace cv;
using namespace std;
void ch(int *p){ cout << *p << endl; int *p1; p1 = p; *p1 = 4; cout << *p << endl; };
void allocateMemory()
{
	int *p = new int[4000];
	ZeroMemory(p, 16000);
	Sleep(1);
}
int main()
{
	//string fileName = "E:\\gamma.txt";
	//float gamma = 1.25;
	//FileOps::CFileOp file(gamma,fileName);
	//file.getResult();
 //	system("pause");
	while (1)
	{
		allocateMemory();
	}
	return 0;
} 