#include <iostream>
#include <algorithm>

using namespace std;

int g_num;		// stamps' num
int g_target;	// customer require

int g_stamps[100];
int g_answer_now[5];	// answer_num, stamp1, stamp2, ...
int g_best_answer[5];	// answer_num, stamp1, stamp2, ...

bool g_none;
bool g_tie;


int calc_sum()
{
	int sum = 0;
	for (int i = 1; i <= g_answer_now[0]; i++)
		sum += g_stamps[g_answer_now[i]];
	return sum;
}

void print()
{
	cout << g_target << ": ";
	for (int i = 1; i <= g_answer_now[0]; i++)
		cout << g_stamps[g_answer_now[i]] << " ";
	cout << endl;
}

int calc_species(int * ans)
{
	int ret = 1;
	if (ans[0] < 2)
		ret = ans[0];
	for (int i = 2; i <= ans[0]; i++)
		if (ans[i] != ans[i - 1])
			ret++;
	return ret;
}

int calc_amount(int * ans)
{
	return ans[0];
}

int highest_single(int *ans)
{
	int ret = 0;
	
	for (int i = 1; i <= ans[0]; i++)
		if (g_stamps[ans[i]] > ret)
			ret = g_stamps[ans[i]];
	return ret;
}

void store_best_answer()
{
	for (int i = 0; i <= g_answer_now[0]; i++)
		g_best_answer[i] = g_answer_now[i];
	g_tie = false;
}

void cmp_answers()
{
	int species_now = calc_species(g_answer_now);
	int species_best = calc_species(g_best_answer);
	if (species_now > species_best)				// the maximum number of different stamp types is best
		store_best_answer();
	else if (species_now == species_best)
	{
		int amount_now = calc_amount(g_answer_now);
		int amount_best = calc_amount(g_best_answer);
		if (amount_now < amount_best)			// fewest total stamps is best
			store_best_answer();
		else if (amount_now == amount_best)
		{
			int highest_now = highest_single(g_answer_now);
			int highest_best = highest_single(g_best_answer);
			if (highest_now > highest_best)				//  the set with the highest single-value stamp is best
				store_best_answer();
			else if (highest_now == highest_best)
				g_tie = true;
		}
	}
}

void handle(int deep, int begin)
{
	g_answer_now[0] = deep++;

	if (calc_sum() == g_target)
	{
		g_none = false;
		cmp_answers();
		return;
	}

	if (deep > 4)
		return;

	for (int i = begin; i < g_num; i++)
	{
		g_answer_now[deep] = i;
		handle(deep, i);
	}
}

void out_put()
{
	cout << g_target;
	if (g_none)
		cout << " ---- none" << endl;
	else if (g_tie)
		cout << " (" << calc_species(g_best_answer) << "): tie" << endl;
	else
	{
		cout << " (" << calc_species(g_best_answer) << "):";

		int answer[4];
		for (int i = 0; i < g_best_answer[0]; i++)
			answer[i] = g_stamps[g_best_answer[i + 1]];

		sort(answer, answer + g_best_answer[0]);

		for (int i = 0; i < g_best_answer[0]; i++)
			cout << " " << answer[i];
		cout << endl;
	}
}

int test()
{
	while (cin >> g_stamps[0])
	{
		g_num = 0;
		while (g_stamps[g_num])
			cin >> g_stamps[++g_num];

		while (cin >> g_target, g_target)
		{
			g_best_answer[0] = 0;
			g_none = true;

			handle(0, 0);
			out_put();
		}
	}
	return 0;
}
