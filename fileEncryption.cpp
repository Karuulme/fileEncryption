#include <iostream>
#include <windows.h>
using namespace std;
string fileAppendage(char fileName[]) {
    int i = 0;
    bool control=false;
    string sAppendage;
    do {
       if (fileName[i] == '.')
            control = true;
        if (control)
            sAppendage+=fileName[i];
        i++;
    } while (fileName[i] != '\0');
    return sAppendage;
}
void ColumnSize(int columnSize) {
    if (columnSize!=0) {
        for (int i = 0; i < columnSize; i++) {
            cout << '\t';
        }
    }
}
void fileSubdirectories(string firstFilePath,int columnSize = 0) {
    firstFilePath += "/*";
    WIN32_FIND_DATAA fileInformation;
    HANDLE firstFile = FindFirstFileExA(firstFilePath.c_str(), FindExInfoStandard, &fileInformation, FindExSearchNameMatch, NULL, 0);
    do {
        ColumnSize(columnSize);
        cout << "file Name : " << fileInformation.cFileName << endl;
        if (fileAppendage(fileInformation.cFileName) == "") {
            firstFilePath.erase(firstFilePath.length()-1,1);
            fileSubdirectories(firstFilePath +"/" + fileInformation.cFileName, columnSize + 1);
        }
    } while (FindNextFileA(firstFile, &fileInformation));

    FindClose(firstFile);
}
int main()
{
    fileSubdirectories("C:/Users/Karuu/Desktop/fileEncryption");
    //FindClose(lpFindFileData);
    return 0;
}
