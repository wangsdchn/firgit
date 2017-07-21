#include <fstream>
#include <iostream>
#include <vector>
namespace FileOps
{
	class CFileOp
	{
	public:
		explicit CFileOp(float gamma, std::string fileName);
		~CFileOp();
		void getResult();
	private:
		std::vector<unsigned char> gammaResult;
		float gamma;
		std::string fileName;
		std::ofstream fileOut;
		void gammaCorrect();
		void saveResult2File();
	};
	
}