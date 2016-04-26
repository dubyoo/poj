#include <iostream>
#include <string>
#include <map>

using namespace std;

const char tzolkin_day_words[20][10] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
map<string, int> haab_month;

void init()
{
	haab_month.clear();
	haab_month["pop"] = 0;
	haab_month["no"] = 20;
	haab_month["zip"] = 40;
	haab_month["zotz"] = 60;
	haab_month["tzec"] = 80;
	haab_month["xul"] = 100;
	haab_month["yoxkin"] = 120;
	haab_month["mol"] = 140;
	haab_month["chen"] = 160;
	haab_month["yax"] = 180;
	haab_month["zac"] = 200;
	haab_month["ceh"] = 220;
	haab_month["mac"] = 240;
	haab_month["kankin"] = 260;
	haab_month["muan"] = 280;
	haab_month["pax"] = 300;
	haab_month["koyab"] = 320;
	haab_month["cumhu"] = 340;
	haab_month["uayet"] = 360;
}

int test()
{
	init();

	int num;
	cin >> num;
	int * total_days = new int[num];
	for (int i = 0; i < num; i++)
	{
		int day, year;
		string dot, month;
		cin >> day >> dot >> month >> year;
		total_days[i] = day + haab_month[month] + year * 365;
	}

	cout << num << endl;
	for (int i = 0; i < num; i++)
	{
		int year = total_days[i] / 260;
		int day_num = total_days[i] % 260 % 13 + 1;
		string day_word = tzolkin_day_words[ total_days[i] % 260 % 20 ];
		cout << day_num << " " << day_word << " " << year << endl;
	}

	delete[] total_days;
	return 0;
}
