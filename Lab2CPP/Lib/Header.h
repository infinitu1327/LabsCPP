#include <vector>
#ifndef __HEADER_H
#define __HEADER_H
extern "C" void __declspec(dllexport) GetPublicKeys(int &key1,int &key2);
extern "C" int __declspec(dllexport) Decrypt(int num);
extern "C" int __declspec(dllexport) Encrypt(int num, std::vector<int> &publicKeys);
#endif

int GCD(int m, int n);
bool IsPrime(int m);