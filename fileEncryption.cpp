#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    char firstFilePath[MAX_PATH] = "C:/Users/Karuu/Desktop/fileEncryption/*";
    WIN32_FIND_DATAA fileInformation;
    HANDLE firstFile =FindFirstFileExA(firstFilePath,FindExInfoStandard,&fileInformation, FindExSearchNameMatch,NULL, 0);
    cout << "error." << GetLastError()<<endl;
    do {
        cout << fileInformation.cFileName << endl;
    } while (FindNextFileA(firstFile, &fileInformation));
    
    FindClose(firstFile);
    //FindClose(lpFindFileData);

    
    return 0;

}
