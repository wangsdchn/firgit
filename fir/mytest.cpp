#include "mytest.h"

void CMytest::TestOfOpenmp(const int *dina,const int *dinb,int *dout,const int &size){
#ifdef USE_OPENMP
#pragma omp parallel for
#endif
	for (int j = 0; j < 200; j++){
		for (int i = 0; i < size; i++){
			dout[i] = dina[i] * dinb[i];
			cout << "i*i=" << dout[i] << " " << "ThreadID=" << omp_get_thread_num() << endl;
		}
	}
}

void CMytest::TestOfSSE(const float *op1,const float *op2, float *op3,const int &size){
#ifdef USE_SSE
	//cout << "SSE" << endl;
	__m128 m1, m2, m3, m4;
	__m128* pSrc1 = (__m128*)op1;
	__m128* pSrc2 = (__m128*)op2;
	__m128* pDst = (__m128*)op3;
	__m128 m0_5 = _mm_set_ps1(0.5f);
	int Loop = size / 4;
	for (int i = 0; i < Loop; i++){
		m1 = _mm_mul_ps(*pSrc1, *pSrc1);
		m2 = _mm_mul_ps(*pSrc2, *pSrc2);
		m3 = _mm_add_ps(m1, m2);
		m4 = _mm_sqrt_ps(m3);
		*pDst = _mm_add_ps(m4, m0_5);
		pSrc1++;
		pSrc2++;
		pDst++;
	}
#else
	float m1,m2,m3,m4;
	const float* pSrc1 = op1;
	const float* pSrc2 = op2;
	float* pDst = op3;
	float m0_5 = 0.5f;
	int Loop = size;
	for (int i = 0; i < Loop; i++){
		m1 = *pSrc1 * *pSrc1;
		m2 = *pSrc2 * *pSrc2;
		m3 = m1 + m2;
		m4 = sqrt(m3);
		*pDst = m4 + m0_5;
		pSrc1++;
		pSrc2++;
		pDst++;
	}
#endif

}

//求平方根 仅保留整数位
unsigned int CMytest::QuickSqrtUN(unsigned int unRoot)
{
	unsigned int unSqrt = 0;
	unsigned int unTemp;
	unsigned int i;

	for (i = 0x10000000; i != 0; i >>= 2)
	{
		unTemp = unSqrt + i;
		unSqrt >>= 1;
		if (unTemp <= unRoot)
		{
			unRoot -= unTemp;
			unSqrt += i;
		}
	}
	return unSqrt;
}

//
// Carmack在QUAKE3中使用的计算平方根的函数
//
float CMytest::QuickSqrtF(float x)
{
	long i;
	float xHalf, y;

	xHalf = x*0.5f;
	y = x;
	i = *(long *)&y;							// get bits for floating VALUE
	i = 0x5f3759df - (i >> 1);  //0x5f375a86		// gives initial guess y0
	y = *(float *)&i;							// convert bits BACK to float
	y = y * (1.5f - (xHalf*y*y));			// Newton step, repeating increases accuracy		1st iteration
	//y  = y * ( f - ( xHalf * y * y ) );			// 2nd iteration, this can be removed
	return x*y;
}

//最精简的1/sqrt()函数,精度较高
float CMytest::QuickInvSqrt(float x)
{
	long i;
	float xhalf, y;

	xhalf = 0.5f*x;
	i = *(long*)&x;
	i = 0x5f375a86 - (i >> 1);
	y = *(float*)&i;
	y = y*(1.5f - xhalf*y*y);
	return y;
}