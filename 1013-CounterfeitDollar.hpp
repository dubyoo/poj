#include <iostream>
#include <string>

using namespace std;

int test()
{
	int case_num;
	cin >> case_num;
	while (case_num--)
	{
		int coin[12] = { 0 };
		int bad = 0;
		for (int line = 0; line < 3; line++)
		{
			string left, right, judge;
			cin >> left >> right >> judge;
			if ("even" == judge)
				for (int i = 0; i < left.size(); i++)
				{
					coin[left[i] - 'A'] = 100;
					coin[right[i] - 'A'] = 100;
				}
			if ("up" == judge)
			{
				for (int i = 0; i < left.size(); i++)
				{
					coin[left[i] - 'A']++;
					coin[right[i] - 'A']--;
				}
				bad++;
			}
			else if ("down" == judge)
			{
				for (int i = 0; i < left.size(); i++)
				{
					coin[left[i] - 'A']--;
					coin[right[i] - 'A']++;
				}
				bad++;
			}
		}
		for (int i = 0; i < 12; i++)
		{
			if (coin[i] == bad && bad != 0)
				cout << char(i + 'A') << " is the counterfeit coin and it is heavy." << endl;
			if (coin[i] == -bad && bad != 0)
				cout << char(i + 'A') << " is the counterfeit coin and it is light." << endl;
		}

	}
	

	return 0;
}
