#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

char input[81];
char inventory[16][81];
int current;
bool classifiable;

void trans()
{
	current++;
	int num[10] = { 0 };
	for (int i = 0; i < strlen(inventory[current - 1]); i++)
		num[inventory[current - 1][i] - '0'] ++;
	strcpy(inventory[current], "");
	for (int i = 0; i < 10; i++)
	{
		if (num[i] > 0)
		{
			char tmp[8] = "";
			sprintf(tmp, "%d%d", num[i], i);
			strcat(inventory[current], tmp);
		}
	}
}

void check_answer(int step)
{
	if (0 == strcmp(inventory[current], inventory[current - 1]))
	{
		classifiable = true;
		cout << input << " is self-inventorying";
		if (step > 0)
			cout << " after " << step << " steps";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < current; i++)
		{
			for (int j = i + 1; j <= current; j++)
			{
				if (0 == strcmp(inventory[i], inventory[j]))
				{
					cout << input << " enters an inventory loop of length " << j - i << endl;
					classifiable = true;
					break;
				}
			}
			if (classifiable)
				break;
		}
	}
}

int test()
{
	while (cin >> input)
	{
		if (0 == strcmp(input, "-1"))
			break;

		classifiable = false;
		current = 0;
		strcpy(inventory[current], input);
		for (int i = 0; i < 15; i++)
		{
			trans();
			check_answer(i);

			if (classifiable)
				break;
		}
		if (!classifiable)
			cout << input << " can not be classified after 15 iterations" << endl;
	}
	return 0;
}
