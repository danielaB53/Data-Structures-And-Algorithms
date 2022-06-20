#include <iostream>
#include <vector>
#include <list>

using namespace std;

long abs_value(long number)
{
	if (number < 0)
		return -number;
	return number;
}

class Warrior_Stack
{
private:
	list<long> warriors;

public:
	void push(long element)
	{
		warriors.push_back(element);
	}

	void pop()
	{
		if (warriors.size() == 0)
			return;
		warriors.pop_back();
	}

	bool is_empty() const
	{
		return warriors.size() == 0;
	}

	long peek_front() const
	{
		if (warriors.size() == 0)
			return -1;
		return warriors.back();
	}

	long length() const
	{
		return warriors.size();
	}
};

int main()
{
	long warrior_count;
	cin >> warrior_count;

	vector<long> bridge;

	for (size_t i = 0; i < warrior_count; i++)
	{
		long current;
		cin >> current;
		bridge.push_back(current);
	}

	Warrior_Stack war;

	for (size_t i = 0; i < bridge.size(); i++)
	{
		if (bridge[i] > 0)
			war.push(bridge[i]);
		else
		{
			if (war.is_empty() == true || war.peek_front() < 0)
				war.push(bridge[i]);
			else
			{
				while (war.peek_front() > 0 && abs_value(bridge[i])>=war.peek_front())
				{
					if (abs_value(bridge[i]) == war.peek_front())
					{
						war.pop();
						break;
					}
					if (abs_value(bridge[i]) > war.peek_front())
						war.pop();
				}
				if (war.peek_front() < 0)
					war.push(bridge[i]);

			}
		}
	}

	bridge.clear();

	while (war.is_empty() == false)
	{
		bridge.push_back(war.peek_front());
		war.pop();
	}

	if (bridge.size() == 0)
		return 0;


	for (size_t i = bridge.size() - 1; i >= 0; i--)
	{
		cout << bridge[i] << " ";
		if (i == 0)
			break;
	}

	return 0;
}
