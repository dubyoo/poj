#include <iostream>

using namespace std;

int value[7];
int half_value;
bool dividable;


void dfs(int sum, int index)
{
	if (dividable)
		return;

	if (sum == half_value)
	{
		dividable = true;
		return;
	}

	for (int i = index; i >= 1; i--)
	{
		if (value[i])
		{
			if (sum + i <= half_value)
			{
				value[i]--;
				dfs(sum + i, i);
				if (dividable)
					return;
			}
		}
	}
	return;
}

void out_put(int num)
{
	cout << "Collection #" << num << ":\n" << (dividable ? "Can" : "Can't") << " be divided.\n" << endl;
}

int test()
{
	int case_num = 0;
	while (++case_num)
	{
		int sum = 0;
		dividable = false;

		for (int i = 1; i <= 6; i++)
		{
			cin >> value[i];
			sum += value[i] * i;
		}

		if (0 == sum)
			break;

		if (0 != sum % 2)
		{
			out_put(case_num);
			continue;
		}

		half_value = sum / 2;

		dfs(0, 6);
		out_put(case_num);
	}
	return 0;
}
