
#include<omp.h>
#include "mytest.h"
#include "fileOps.h"
#include<time.h>
#include<vector>
//#include <windows.h>
#define _AFXDLL
#include <afxtempl.h>
#include <assert.h>

#include <WinInet.h>
#include <SensAPI.h>
using namespace cv;
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	size_t size1 = nums1.size();
	size_t size2=nums2.size();
	size_t newsize=0,midloc=0,sortedsize=0,index1=0,index2=0;
	int tempnum=0;
	double midnum = 0.0;

	newsize = size1 + size2;
	bool bfind = false;
	midloc = newsize >> 1;
	int tempnum1 = 0, midindex = 0;
	while (true)
	{
		while (index1 < size1 && index2<size2 && !bfind)
		{
			if (nums1[index1] >= nums2[index2])
			{
				tempnum1 = tempnum;
				tempnum = nums2[index2];
				if (midindex == midloc)
				{
					bfind = true;
					break;
				}
				else
				{
					index2++;
					midindex++;
				}
			}
			else
			{
				tempnum1 = tempnum;
				tempnum = nums1[index1];
				if (midindex == midloc)
				{
					bfind = true;
					break;
				}
				else
				{
					index1++;
					midindex++;
				}
			}
		}
		while (index2 < size2 && !bfind)
		{
			tempnum1 = tempnum;
			tempnum = nums2[index2];
			if (midindex == midloc)
			{
				bfind = true;
				break;
			}
			else
			{
				index2++;
				midindex++;
			}
		}
		while (index1 < size1 && !bfind)
		{
			tempnum1 = tempnum;
			tempnum = nums1[index1];
			if (midindex == midloc)
			{
				bfind = true;
				break;
			}
			else
			{
				index1++;
				midindex++;
			}
		}
		if (bfind)
			break;
	}
	cout << (newsize & 0x1) << endl;
	if (0==(newsize & 0x1))
		midnum = 1.0*(tempnum + tempnum1) / 2;
	else
		midnum = tempnum;

	return midnum;
}
int main()
{
	int x;
	int bit1num = 0;
	while (1)
	{
		bit1num = 0;
		cin >> x;
		while (x)
		{
			x = x&(x - 1);
			bit1num++;
		}
		cout << bit1num << endl;
	}
	system("pause");
	return 0;
} 