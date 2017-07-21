#include "fileOps.h"
using namespace FileOps;

CFileOp::CFileOp(float gammaIn, std::string fileNameIn):
gamma(gammaIn),
fileName(fileNameIn)
{
}
CFileOp::~CFileOp()
{}

void CFileOp::gammaCorrect()
{
	float result;
	for (int i = 0; i < 256; i++)
	{
		result = powf(i, gamma);
		result = result>255 ? 255 : result;
		gammaResult.push_back((unsigned char)result);
	}
}
void CFileOp::saveResult2File()
{
	char cResult[20];
	fileOut.open(fileName,std::ios::out);
	if (fileOut.is_open())
	{
		for (size_t i=0; i < gammaResult.size(); i++)
		{
			sprintf_s(cResult, "%d", gammaResult[i]);
			fileOut << cResult<<",";
			if (0 == i % 32 && 0!=i)
				fileOut << "\n";
		}
		fileOut.close();
	}
	else
		std::cout << "file open error" << std::endl;
}

void CFileOp::getResult()
{
	gammaCorrect();
	saveResult2File();
}