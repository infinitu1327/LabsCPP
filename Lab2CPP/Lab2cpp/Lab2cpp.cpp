// Lab2cpp.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "../RSALib/RSALib.h"

using namespace std;


int main()
{
	vector<int> keys = RSA::GetPublicKeys(101);
	cout << RSA::Encrypt(101, keys);
    return 0;
}

