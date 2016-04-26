#include <iostream>

using namespace std;

int test()
{
	double input;
	while (cin >> input)
	{
		if (0.0 == input)
			break;

		double len = 0.0;
		for (int i = 1; ; i++)
		{
			len += 1 / (double)(i + 1);
			if (len >= input)
			{
				cout << i << " card(s)" << endl;
				break;
			}
		}
	}
	return 0;
}
