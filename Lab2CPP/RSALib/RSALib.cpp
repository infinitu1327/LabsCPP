#include "RSALib.h"

int RSA::n = 0;
int RSA::d = 0;

std::vector<int> RSA::GetPublicKeys(int num)
{
	int p = 2;
	int q = 2;
	while (p * q < num)
	{
		if (p != q)
		{
			p++;
			q++;
		}
		else
		{
			p++;
		}

		while (!IsPrime(p))
		{
			p++;
		}
		while (!IsPrime(q) && q != p)
		{
			q++;
		}
	}

	n = p * q;
	int f = (p - 1) * (q - 1);
	int e = 2;
	while (GCD(e, f) != 1)
	{
		e++;
	}

	d = 0;
	while ((d*e) % f != 1)
	{
		d++;
	}

	return { e, n };
}

int RSA::Decrypt(int num)
{
	int res = 1;

	for (int i = 0; i < d; i++)
	{
		res = (res * num) % n;
	}

	return res;
}

int RSA::Encrypt(int num, std::vector<int> &publicKeys)
{
	int res = 1;

	for (int i = 0; i < publicKeys[0]; i++)
	{
		res = (res*num) % n;
	}

	return res;
}

int RSA::GCD(int m, int n)
{
	if (n == 0)
	{
		return m;
	}
	else
	{
		while (m % n != 0)
		{
			int t = m % n;
			m = n;
			n = t;
		}
		return n;
	}
}

bool RSA::IsPrime(int m)
{
	for (int i = 2; i < std::sqrt(m); i++)
	{
		if (m % i == 0)
		{
			return false;
		}
	}
	return true;
}
