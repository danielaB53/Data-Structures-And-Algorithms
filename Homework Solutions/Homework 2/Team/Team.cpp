#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_nums(char num1, char num2)
{
    return num1 < num2;
}

bool compare_letters(char letter1, char letter2)
{
    return letter1 < letter2;
}

int main()
{
    int number_of_players;
    cin >> number_of_players;

    vector <char> players_nums;
    vector <char> players_lowercase;
    vector <char> players_uppercase;

    for (size_t i = 0; i < number_of_players; i++)
    {
        char current_player;
        cin >> current_player;

        if (current_player >= '0' && current_player <= '9')
            players_nums.push_back(current_player);
        else if (current_player >= 'a' && current_player <= 'z')
            players_lowercase.push_back(current_player);
        else
            players_uppercase.push_back(current_player);

    }

    sort(players_nums.begin(), players_nums.end(), compare_nums);
    sort(players_lowercase.begin(), players_lowercase.end(), compare_letters);
    sort(players_uppercase.begin(), players_uppercase.end(), compare_letters);

    for (size_t i = 0; i < players_nums.size(); i++)
    {
        cout << players_nums[i];
    }

    for (size_t i = 0; i < players_lowercase.size(); i++)
    {
        cout << players_lowercase[i];
    }

    for (size_t i = 0; i < players_uppercase.size(); i++)
    {
        cout << players_uppercase[i];
    }

    return 0;
}

