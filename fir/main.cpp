
#include<omp.h>
#include "mytest.h"
#include "fileOps.h"
#include<time.h>
#include<vector>
//#include <windows.h>
#define _AFXDLL
#include <afxtempl.h>
#include <assert.h>
using namespace cv;
using namespace std;
typedef int(*AddDll)(int, int);
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
#ifdef _DEBUG
	HINSTANCE hdll = LoadLibrary("../x64/Debug/addDll.dll");
#else
	HINSTANCE hdll = LoadLibrary("./addDll.dll");
#endif
	if (hdll == NULL)
	{
		FreeLibrary(hdll);
		return 1;
	}
	AddDll add = (AddDll)GetProcAddress(hdll, "add");
	if (add == NULL)
	{
		FreeLibrary(hdll);
		return 2;
	}
	while (true)
	{
		int a, b;
		cout << "Pelease input two numbers:";
		cin >> a >> b;
		int c = add(a, b);
		cout << "Add Result:" << c << endl;
	}
	if (hdll!=NULL)
		FreeLibrary(hdll);
	system("pause");
	return 0;
} 