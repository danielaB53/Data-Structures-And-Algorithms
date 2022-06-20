#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

void to_binary(int number, vector <int>& current_num)
{
    if (current_num.empty() == false)
        current_num.clear();

	while (number > 0)
	{
		int remainder = number % 2;
		current_num.push_back(remainder);
		number /= 2;
	}

	reverse(current_num.begin(), current_num.end());
}

int to_int(vector<int>& binary)
{
    int int_value = 0;
    int length = binary.size() - 1;
    for (size_t i = 0; i < binary.size(); i++)
    {
        int_value += (binary[i] * pow(2, length));
        length--;
    }
    return int_value;
}

void get_masks(int position, vector <int>& binary_num, set <int>& unique_masks)
{
    if (position == binary_num.size())
    {
        unique_masks.insert(to_int(binary_num));
        return;
    }

    if (binary_num[position] == 1)
    {
        get_masks(position + 1, binary_num, unique_masks);
        binary_num[position] = 0;
        get_masks(position + 1, binary_num, unique_masks);
        binary_num[position] = 1;
        return;
    }

    get_masks(position + 1, binary_num, unique_masks);
    binary_num[position] = 0;
}

int main()
{
    int number_count;
    cin >> number_count;

    vector <int> nums;

    int current_num;
    for (size_t i = 0; i < number_count; i++)
    {
        cin >> current_num;
        nums.push_back(current_num);
    }

    set <int> submasks;

    vector <int> binary_num;
    for (size_t i = 0; i < nums.size(); i++)
    {
        to_binary(nums[i], binary_num);
        get_masks(0, binary_num, submasks);
    }

    cout << submasks.size();

    return 0;
}