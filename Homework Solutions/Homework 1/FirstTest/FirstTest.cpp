#include <iostream>
#include <string>
#include <vector>

using namespace std;

int places_to_letter_before(string& str, int position, char letter)
{
	if (position == 0)
		return 0;

	int distance = 0;
	bool exists = false;
	for (size_t i = position; i > 0; i--)
	{
		if (str[i - 1] == letter)
		{
			exists = true;
			break;
		}
		else
			distance++;
	}

	distance++;

	if (exists == false)
		return 0;
	
	return distance;
}

int places_to_letter_after(string& str, int position, char letter)
{
	if (position == str.size() - 1)
		return 0;

	int distance = 0;
	bool exists = false;
	for (size_t i = position; i < str.size(); i++)
	{
		if (str[i] == letter)
		{
			exists = true;
			break;
		}
		else
			distance++;
	}

	if (exists == false)
		return 0;
	return distance;
}

int main() 
{
	string word;
	cin >> word;

	char leftover_test;
	cin >> leftover_test;

	vector <int> places;

	for (size_t i = 0; i < word.size(); i++)
	{
		if (word[i] == leftover_test)
		{
			places.push_back(0);
		}
		else
		{
			int left_distance = places_to_letter_before(word, i, leftover_test);
			int right_distance = places_to_letter_after(word, i, leftover_test);

			if (left_distance == 0 && right_distance == 0)
				places.push_back(0);
			else if (left_distance == 0)
				places.push_back(right_distance);
			else if (right_distance == 0)
				places.push_back(left_distance);
			else
			{
				int less_distance = (left_distance < right_distance) ? (left_distance) : (right_distance);
				places.push_back(less_distance);
			}
		}
	}

	for (size_t i = 0; i < places.size(); i++)
	{
		cout << places[i] << " ";
	}

	return 0;
}