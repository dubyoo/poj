#include <iostream>
#include <stdio.h>

using namespace std;

int test()
{
	double balance, total = 0.0;
	for (int i = 0; i < 12; i++)
	{
		cin >> balance;
		total += balance;
	}

	int average100 = int(total * 100 / 12 + 0.5);
	printf("$%.2f\n", double(average100) / 100.0);

	return 0;
}
