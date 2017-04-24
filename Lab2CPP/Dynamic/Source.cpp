#include <stdio.h>
#include <Windows.h>
#include <vector>
#include <iostream>

using namespace std;
typedef void* (*GPK)(int &key1, int &key2);
typedef int(*Dec)(int num);
typedef int(*Enc)(int num, std::vector<int> &publicKeys);

void main()
{
	HINSTANCE hDll = LoadLibrary(L"Lib.dll");
	if (hDll != NULL)
	{
		cout << "Lib loaded" << endl;
	}
	else
	{
		cout << "Failed loading library" << endl;
		return;
	}

	GPK gpk = (GPK)GetProcAddress(hDll, "GetPublicKeys");
	Dec dec = (Dec)GetProcAddress(hDll, "Decrypt");
	Enc enc = (Enc)GetProcAddress(hDll, "Encrypt");	

	vector<int> vec(2);
	gpk(vec[0], vec[1]);

	cout << "Public keys:" << endl << vec[0] << " " << vec[1] << endl;

	cout << "Write number to process:" << endl;

	int num;
	cin >> num;

	int encrypted = enc(num, vec);

	cout << "Encrypted number:" << endl << encrypted << endl;

	int decrypted = dec(encrypted);

	cout << "Decrypted number:" << endl << decrypted << endl;

	FreeLibrary(hDll);
}