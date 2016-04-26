#include <iostream>
#include <algorithm>

using namespace std;

struct DNA
{
	int unsorted;
	char str[51];
};

int count_unsortedness(char* str, int len)
{
	int A = 0, C = 0, G = 0, cnt = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		switch (str[i])
		{
		case 'A':
			A++;
			break;
		case 'C':
			C++;
			cnt += A;
			break;
		case 'G':
			G++;
			cnt += A + C;
			break;
		case 'T':
			cnt += A + C + G;
			break;
		}
	}
	return cnt;
}

int cmp(const void* left, const void* right)
{
	DNA* x = (DNA*)left;
	DNA* y = (DNA*)right;
	return x->unsorted - y->unsorted;
}

int test()
{
	int n, m;
	cin >> n >> m;

	DNA * dnas = new DNA[m];
	for (int i = 0; i < m; i++)
	{
		cin >> dnas[i].str;
		dnas[i].unsorted = count_unsortedness(dnas[i].str, n);
	}
	
	qsort(dnas, m, sizeof(DNA), cmp);
	
	for (int i = 0; i < m; i++)
		cout << dnas[i].str << endl;

	delete[] dnas;
	return 0;
}
