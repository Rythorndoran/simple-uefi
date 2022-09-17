// simple_uefi.cpp: 定义应用程序的入口点。
//

#include "simple_uefi.h"

EFI_STATUS EfiMain(EFI_HANDLE ImageHandle [[maybe_unused]], EFI_SYSTEM_TABLE* SystemTable)
{
	uint64_t key_event;

	SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
	
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_GREEN);

	SystemTable->ConOut->OutputString(SystemTable->ConOut, reinterpret_cast<CHAR16*>(const_cast<wchar_t*>(L"Hello World!\n")));

	SystemTable->BootServices->WaitForEvent(1, &SystemTable->ConIn->WaitForKey, &key_event);

	return EFI_SUCCESS;
}
