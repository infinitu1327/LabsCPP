// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <string.h>
#include <tchar.h>
#include <Windows.h>
#include <stringapiset.h>
using namespace std;
#ifdef UNICODE
typedef wchar_t TCHAR;
#define TEXT(a) L##a
#else
typedef char TCHAR;
#define TEXT(a) a
#endif

int compare(const void* ch1, const void* ch2) {
	return wcscmp((wchar_t*)ch1, (wchar_t*)ch2);
}

int main()
{
	_tsetlocale(LC_ALL, _T("Russian"));

	if (sizeof(TCHAR) == 2) {
		cout << "UNICODE\n";
	}
	else {
		cout << "ASCII\n";
	}

	const char* familyAscii[] = {
		"Цомкалов Олег Андреевич",
		"Цомкалов Андрей Олегович",
		"Макарова Надежда Олеговна"
	};	

	//6
	wchar_t familyUnicode[size(familyAscii)][50];

	for (int i = 0; i < size(familyAscii); i++)
	{
		MultiByteToWideChar(CP_ACP, 0, familyAscii[i], strlen(familyAscii[i]) + 1, familyUnicode[i], strlen(familyAscii[i]) + 1);
	}

	//7
	for (size_t i = 0; i < size(familyUnicode); i++)
	{
		_tprintf(familyUnicode[i]);
		cout << endl;
		MessageBox(0, familyUnicode[i], familyUnicode[i], MB_OK);
	}
	
	//8
	qsort(familyUnicode, size(familyUnicode), sizeof(familyUnicode[0]), compare);

	//9 
	char newFamilyAscii[size(familyUnicode)][50];
	char symbol = ' ';
	for (int i = 0; i < size(familyAscii); i++)
	{
		WideCharToMultiByte(CP_ACP, 0, familyUnicode[i], wcslen(familyUnicode[i]) + 1, newFamilyAscii[i], wcslen(familyUnicode[i]) + 1, &symbol, false);
	}

	//10
	for (size_t i = 0; i < size(newFamilyAscii); i++)
	{
		cout << newFamilyAscii[i] << endl;
	}

    return 0;
}



