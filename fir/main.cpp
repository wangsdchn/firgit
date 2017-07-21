
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
int main()
{
	string fileName = "E:\\gamma.txt";
	float gamma = 1.25;
	FileOps::CFileOp file(gamma,fileName);
	file.getResult();
 	system("pause");
	return 0;
} 