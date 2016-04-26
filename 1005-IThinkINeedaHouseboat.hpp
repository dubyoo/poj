#include <iostream>
#include <math.h>

#define PI 3.1415926

using namespace std;

int test()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		double area = PI * (x * x + y * y) / 2 ;
		for (int j = 1; ; j++)
		{
			if (50.0 * j >= area)
			{
				cout << "Property " << i + 1 << ": This property will begin eroding in year " << j << "." << endl;
				break;
			}
		}
	}

	cout << "END OF OUTPUT." << endl;

	return 0;
}
