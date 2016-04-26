#include <iostream>
#include <algorithm>

using namespace std;


int  sticks[64] = { 0 };
int  stickCnt = 0;
char used[64] = { 0 };
int  len = 0;

int dfs(int usedCnt, int curLen, int pos)
{
	int i = 0;

	if (curLen == len)
	{
		if (usedCnt == stickCnt)
			return 1;

		pos = 0;
		curLen = 0;
	}

	for (i = pos; i < stickCnt; i++)
	{
		if (used[i])
			continue;

		if (curLen + sticks[i] > len)
			continue;

		used[i] = 1;
		if (dfs(usedCnt + 1, curLen + sticks[i], i + 1))
			return 1;
		used[i] = 0;

		if (0 == curLen)
			return 0;

		while ((i < stickCnt) && (sticks[i + 1] == sticks[i]))
			i++;
	}

	return 0;
}

int test()
{
	int  i = 0;
	int  sum = 0;

	while (cin >> stickCnt && stickCnt)
	{
		sum = 0;
		for (i = 0; i < stickCnt; i++)
		{
			cin >> sticks[i];
			sum += sticks[i];
		}

		sort(sticks, sticks + stickCnt);

		for (len = sticks[0]; len <= sum; len++)
		{
			if (sum % len == 0)
			{
				for (i = 0; i < stickCnt; i++)
					used[i] = 0;

				if (dfs(0, 0, 0))
					break;
			}
		}
		cout << len << endl;
	}

	return 0;
}