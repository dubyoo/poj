#include <iostream>
#include <string>
#include <string.h>

using namespace std;

#define MAXSIZE 1000000

char a[MAXSIZE], b[MAXSIZE], tmp[MAXSIZE];
int len_a, len_b;

void mul()
{
	memset(tmp, 0, MAXSIZE);
	for (int i = 0; i < len_a; i++)
	{
		for (int j = 0; j < len_b; j++)
		{
			tmp[i + j] += a[i] * b[j];
			if (tmp[i + j] > 9)
			{
				tmp[i + j + 1] += tmp[i + j] / 10;
				tmp[i + j] %= 10;
			}
		}
	}

	len_a += len_b;
	for (int i = 0; i < len_a; i++)
		a[i] = tmp[i];
}


int test()
{
	string s;
	int n;
	while (cin >> s >> n)
	{
		memset(a, 0, MAXSIZE);
		memset(b, 0, MAXSIZE);

		int dot = -1;
		for (int i = s.length() - 1, j = 0; i >= 0; i--)
		{
			if ('.' == s[i])
				dot = i;
			else
			{
				a[j] = s[i] - '0';
				b[j] = a[j];
				j++;
			}
		}
		if (-1 == dot)
			len_a = len_b = 6;
		else
			len_a = len_b = 5;

		// 计算
		for (int i = 0; i < n - 1; i++)
			mul();

		if (-1 != dot)
		{
			dot = 5 - dot;
			dot *= n;
			dot--;
		}

		// 去除前后0
		int up = len_a - 1, down = 0;
		for (int i = len_a - 1; i >= 0; i--)
		{
			if (0 != a[i])
			{
				up = i;
				break;
			}
		}
		if (up < dot)
			up = dot;
		for (int i = 0; i < len_a; i++)
		{
			if (0 != a[i])
			{
				down = i;
				break;
			}
		}
		if (down > dot)
			down = dot + 1;

		// 输出
		for (int i = up; i >= down; i--)
		{
			if (i == dot)
				cout << '.';
			cout << (int)a[i];
		}
		cout << endl;
	}
	return 0;
}

