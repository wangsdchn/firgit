#include "mytest.h"

void CMytest::TestOfOpenmp(const int *dina,const int *dinb,int *dout,const int &size){
	int j;
//#ifdef USE_OPENMP
//#pragma omp parallel for
//#endif
	for (int i = 0; i < size; i++){
		dout[i] = dina[i] * dinb[i];
		cout << "i*i=" << dout[i] << " " << "ThreadID=" << omp_get_thread_num() << endl;
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