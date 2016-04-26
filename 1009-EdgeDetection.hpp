#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

struct RLE
{
	int pixel;
	int length;
};

int g_width, g_height, g_tail;
RLE g_in_pair[1000];
RLE g_out_pair[1000];

// 0   1   2
// 3  pos  4
// 5   6   7
int get_pos(int pos, int index)
{
	int ret = -1;
	int x = pos % g_width;
	int y = pos / g_width;
	switch (index)
	{
	case 0:	
		if (x > 0 && y > 0) 
			ret = pos - g_width - 1;
		break;
	case 1:	
		if (y > 0) 
			ret = pos - g_width;
		break;
	case 2:	
		if (x < g_width - 1 && y > 0) 
			ret = pos - g_width + 1;
		break;
	case 3:	
		if (x > 0)
			ret = pos - 1;
		break;
	case 4:	
		if (x < g_width - 1)
			ret = pos + 1;
		break;
	case 5:	
		if (x > 0 && y < g_height - 1)
			ret = pos + g_width - 1;
		break;
	case 6:	
		if (y < g_height - 1)
			ret = pos + g_width;
		break;
	case 7:	
		if (x < g_width - 1 && y < g_height - 1)
			ret = pos + g_width + 1;
		break;
	default:
		break;
	}
	return ret;
}

int get_value(int pos)
{
	int i = 0, len = 0;
	while (true)
	{
		len += g_in_pair[i].length;
		if (len > pos)
			break;
		i++;
	}
	return g_in_pair[i].pixel;
}

int cal_value(int pos)
{
	int value = get_value(pos);
	int max = 0;
	for (int i = 0; i < 8; i++)
	{
		int cmp_pos = get_pos(pos, i);
		if (cmp_pos < 0)
			continue;
		int d = abs(value - get_value(cmp_pos));
		if (d > max)
			max = d;
	}
	return max;
}

void push_back_answer(int value, int num = 1)
{
	if (value != g_out_pair[g_tail].pixel || -1 == g_tail)
	{
		++g_tail;
		g_out_pair[g_tail].pixel = value;
		g_out_pair[g_tail].length = num;
	}
	else
		g_out_pair[g_tail].length += num;
}

void dispose(const RLE& in, int begin)
{
	if (in.length < g_width * 3)
		for (int i = 0; i < in.length; i++)
			push_back_answer(cal_value(i + begin));
	else
	{
		for (int i = 0; i < g_width + 1; i++)
			push_back_answer(cal_value(i + begin));
		push_back_answer(0, in.length - 2 * g_width - 2);
		for (int i = in.length - g_width - 1; i < in.length; i++)
			push_back_answer(cal_value(i + begin));
	}
}

void print()
{
	cout << g_width << endl;
	for (int i = 0; i <= g_tail; i++)
		cout << g_out_pair[i].pixel << " " << g_out_pair[i].length << endl;
	cout << "0 0" << endl;
}

int test()
{
	
	while (cin >> g_width)
	{
		if (0 == g_width)
			break;

		memset(g_in_pair, 0, sizeof(g_in_pair));
		memset(g_out_pair, 0, sizeof(g_out_pair));
		int pix, repeat, len = 0, index = 0;
		while (cin >> pix >> repeat)
		{
			if (0 == pix + repeat)
				break;
			g_in_pair[index].pixel = pix;
			g_in_pair[index].length = repeat;
			len += repeat;
			index++;
		}
		g_height = len / g_width;

		g_tail = -1;
		
		int begin = 0;
		for (int i = 0; i <= index; i++)
		{
			dispose(g_in_pair[i], begin);
			begin += g_in_pair[i].length;
		}

		print();

	}
	cout << "0" << endl;

	return 0;
}
