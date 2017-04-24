#include <vector>
#include <iostream>
using namespace std;
extern "C" __declspec(dllimport) void GetPublicKeys(int &key1, int &key2);
extern "C" __declspec(dllimport) int Decrypt(int num);
extern "C" __declspec(dllimport) int Encrypt(int num, std::vector<int> &publicKeys);

void main()
{
	vector<int> vec(2);
	GetPublicKeys(vec[0], vec[1]);

	cout << "Public keys:" << endl << vec[0] << " " << vec[1] << endl;

	cout << "Write number to process:" << endl;

	int num;
	cin >> num;

	int encrypted = Encrypt(num, vec);

	cout << "Encrypted number:" << endl << encrypted << endl;

	int decrypted = Decrypt(encrypted);

	cout << "Decrypted number:" << endl << decrypted << endl;
}