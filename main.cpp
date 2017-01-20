#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include<windows.h>

int main (int argc, char** argv)
{
	cout << "hello XPDF " << argc << endl;
	if (argc < 2)
		return 1;
	
	string sp = " ";
	string srcFileName = "1202607471.PDF";
	string dstFileName = "1202607471.txt";
	string path = "C:/Users/ekngcen/Desktop/xpdfbin-win-3.04/bin32/";
	string xpdftotextPath = sp + path + "pdftotext.exe";
	cout << "xpdftotextPath " << xpdftotextPath << endl;
	string configString = sp + "-cfg" + sp + path + "add-to-xpdfrc -enc GBK -table";
	string sourceFile = sp + path + srcFileName;
	string targetFile = sp + path + dstFileName;
	
	string cmd = xpdftotextPath + configString + sourceFile + targetFile;
	cout << cmd << endl;
	
	system("dir");
	system(cmd.c_str());
	//system((string("cat ")+targetFile).c_str());
	
	string targetFile_2 = path + dstFileName;	
	cout << targetFile_2 << endl;
	ifstream inFile;
	inFile.open(targetFile_2); 
	if(!inFile.is_open()) {
		cout << "open file failed:" << targetFile << endl;
        return 0;
	}		
  
    string strLine;  
    while(getline(inFile, strLine))  
    {  
		if(strLine.empty())  
			continue;  
  
		cout << strLine <<endl;                
    }
	
	return 0;
}