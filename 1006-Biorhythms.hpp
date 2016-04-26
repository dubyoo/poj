#include <iostream>

using namespace std;

int test()
{
	int p, e, i, d, case_num = 0;
	while (++case_num, cin >> p >> e >> i >> d)
	{
		if (-1 == p && -1 == e && -1 == i && -1 == d)
			break;
		for (int days = d + 1; days <= 21252 + d; days++)
		{
			if ((days - p) % 23 == 0 && (days - e) % 28 == 0 && (days - i) % 33 == 0)
			{
				cout << "Case " << case_num << ": the next triple peak occurs in " << days - d << " days." << endl;
				break;
			}
		}
	}
	return 0;
}
