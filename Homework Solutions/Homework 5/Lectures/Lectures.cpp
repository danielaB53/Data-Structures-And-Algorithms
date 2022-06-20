#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Letter
{
    int symbol_count;
    int index;

    Letter(int symbol_count = 0, int index = 0)
    {
        this->symbol_count = symbol_count;
        this->index = index;
    }
};

int main()
{
    Letter lowercase[26];
    Letter uppercase[26];
    Letter nums[10];
    
    string lectures;
    cin >> lectures;

    bool contains_lowercase = false;
    bool contains_uppercase = false;
    bool contains_nums = false;

    vector <int> index;

    for (size_t i = 0; i < lectures.size(); i++)
    {
        int ind = 0;
        if (lectures[i] >= 'a' && lectures[i] <= 'z')
        {
            contains_lowercase = true;
            ind = lectures[i] - 97;
            lowercase[ind].symbol_count++;
            lowercase[ind].index = i;
        }
        else if (lectures[i] >= 'A' && lectures[i] <= 'Z')
        {
            contains_uppercase = true;
            ind = lectures[i] - 65;
            uppercase[ind].symbol_count++;
            uppercase[ind].index = i;
        }
        else if (lectures[i] >= '0' && lectures[i] <= '9')
        {
            contains_nums = true;
            ind = lectures[i] - 48;
            nums[ind].symbol_count++;
            nums[ind].index = i;
        }
    }

    if (contains_lowercase == true)
    {
        for (size_t i = 0; i < 26; i++)
        {
            if (lowercase[i].symbol_count == 1)
                index.push_back(lowercase[i].index);
        }
    }
    
    if (contains_uppercase == true)
    {
        for (size_t i = 0; i < 26; i++)
        {
            if (uppercase[i].symbol_count == 1)
                index.push_back(uppercase[i].index);
        }
    }

    if (contains_nums == true)
    {
        for (size_t i = 0; i < 10; i++)
        {
            if (nums[i].symbol_count == 1)
                index.push_back(nums[i].index);
        }
    }

    sort(index.begin(), index.begin() + index.size());

    for (size_t i = 0; i < index.size(); i++)
    {
        cout << index[i] << " ";
    }

    return 0;
}
