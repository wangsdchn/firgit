#include<omp.h>
#include "mytest.h"
#include "fileOps.h"
#include<time.h>
#include<vector>
<<<<<<< HEAD
#include <windows.h>
=======
//#include <windows.h>
#define _AFXDLL
#include <afxtempl.h>
#include <assert.h>
using namespace cv;
>>>>>>> 6aceb2d8e26b980b7693ececf0aaf4196b40576c
using namespace std;
typedef int(*ApiAdd)(int, int);	//add function
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
<<<<<<< HEAD
	HINSTANCE hdll = LoadLibrary("..\\Debug\\add.dll");
	if (hdll == NULL)
	{
		FreeLibrary(hdll);
	}
	ApiAdd add=(ApiAdd)GetProcAddress(hdll, "add");
	if (add == NULL)
	{
		FreeLibrary(hdll);
	}
	int a, b, c;
	cout << "Input two numbers:";
	cin >> a >> b;
	c = add(a, b);
	cout << c << endl;
 	system("pause");
=======
	//string fileName = "E:\\gamma.txt";
	//float gamma = 1.25;
	//FileOps::CFileOp file(gamma,fileName);
	//file.getResult();
	int i = 10;
	std::ostringstream s(std::ios::binary);
	s << i << endl;
	cout << s.str() << endl;

	system("pause");
>>>>>>> 6aceb2d8e26b980b7693ececf0aaf4196b40576c
	return 0;
}