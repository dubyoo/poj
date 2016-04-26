#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
using namespace std;

int num[] =
{
	2, 2, 2,
	3, 3, 3,
	4, 4, 4,
	5, 5, 5,
	6, 6, 6,
	7, 0, 7, 7,
	8, 8, 8,
	9, 9, 9, 0
};

int test()
{
	int n;
	cin >> n;
	vector<string> inputs;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		inputs.push_back(s);
	}
	
	map<int, int> numbers;

	for (int i = 0; i < n; i++)
	{
		int phone_number = 0;
		for (int j = 0; j < inputs[i].length(); j++)
		{
			char c = inputs[i][j];
			if (c >= 'A' && c < 'Z' && c != 'Q')
				phone_number = phone_number * 10 + num[c - 'A'];
			else if (c >= '0' && c <= '9')
				phone_number = phone_number * 10 + c - '0';
		}
		if (numbers.find(phone_number) != numbers.end())
			numbers[phone_number] ++;
		else
			numbers[phone_number] = 1;
	}

	if (numbers.size() == n)
	{
		cout << "No duplicates." << endl;
		return 0;
	}

	map<int, int>::iterator iter = numbers.begin();
	for (; iter != numbers.end(); iter++)
	{
		if (iter->second > 1)
			printf("%03d-%04d %d\n", iter->first / 10000, iter->first % 10000, iter->second);
	}
	
	return 0;
}
