	//测试指针开辟空间，复制构造函数指针释放问题
	CMytest test1;
	clock_t time1 = clock();
	int size = N;
	int a[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int b[N] = { 5, 6, 7, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int c[N] = { 0 };

	memcpy(test1.dina,b,sizeof(int)*N);
	cout << test1.dina[1] << endl;

	clock_t time2 = clock();
	cout << endl << (double)(time2 - time1) / CLOCKS_PER_SEC << endl;
	
//===================================测试SSE===========================================
	CMytest test1;
	_MM_ALIGN16 float src1[N] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 };
	_MM_ALIGN16 float src2[N] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 };
	_MM_ALIGN16 float src3[N] = { 0.0 };
	int size = N;
	test1.op1 = src1;
	test1.op2 = src2;
	test1.op3 = src3;
	clock_t time1 = clock();

	test1.TestOfSSE(test1.op1, test1.op2, test1.op3, size);
	clock_t time2 = clock();
	cout << endl << (double)(time2 - time1) / CLOCKS_PER_SEC << endl;
//===================================测试quake开方===============================================	
	CMytest test1;
	test1.unRoot = 50;
	test1.sqrtNum = 3.0;
	int a;
	float b;

	clock_t time1 = clock();
	for (int i = 0; i < 10000000; i++)
		b = test1.QuickInvSqrt(test1.sqrtNum);
	clock_t time2 = clock();
	cout << b << " "<<(double)(time2 - time1) << endl;

	time1 = clock();
	for (int i = 0; i < 10000000; i++)
		b = 1/sqrtf(test1.sqrtNum);
	time2 = clock();
	cout << b << " " << (double)(time2 - time1) << endl;