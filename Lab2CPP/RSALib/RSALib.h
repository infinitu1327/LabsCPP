#include <vector>
#include <cmath>

class RSA final
{
private:
	static int n;
	static int d;

public:
	static std::vector<int> GetPublicKeys(int num);

	static int Decrypt(int num);

	static int Encrypt(int num, std::vector<int> &publicKeys);

private:
	static int GCD(int m, int n);

	static bool IsPrime(int m);
};
