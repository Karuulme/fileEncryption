#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
void ColumnSize(int columnSize) {
    if (columnSize!=0) {
        for (int i = 0; i < columnSize; i++) {
            for (int k = 0; k < 7;k++) {
                cout << "-";
            }
            
        }
    }
}
void fileSubdirectories(string firstFilePath,int columnSize = 0) {
    WIN32_FIND_DATAA fileInformation;
    HANDLE firstFile = FindFirstFileExA((firstFilePath+ "/*").c_str(), FindExInfoStandard, &fileInformation, FindExSearchNameMatch, NULL, 0);
    do {
        if ((string)fileInformation.cFileName !="." && (string)fileInformation.cFileName != "..") {
            ColumnSize(columnSize);
            if (GetFileAttributesA((firstFilePath + "/" + fileInformation.cFileName).c_str()) == FILE_ATTRIBUTE_DIRECTORY) {
                cout << fileInformation.cFileName <<" + " << endl;
                fileSubdirectories(firstFilePath + "/" + fileInformation.cFileName, columnSize + 1);
            }
            else {
                cout << fileInformation.cFileName << endl;
            }
        }       
    } while (FindNextFileA(firstFile, &fileInformation));

    FindClose(firstFile);
}
int main()
{
    /*
    fstream dosya;
    dosya.open("C:/Users/Karuu/Desktop/test/Yeni klasör/.");
    if (dosya.is_open()) { 
        cout << "Dosya basari ile acildi." << endl;
    }
    else { // Dosya açılırken bir hata oluşursa.
        cout << "Hata: Dosya acilamadi!\n" << endl;
    }*/


    fileSubdirectories("C:/Users/Karuu/Desktop/socket uygulaması");
   // fileSubdirectories("C:/Users/Karuu/Desktop/test/Yeni klasör");
    //FindClose(lpFindFileData);
    return 0;
}
