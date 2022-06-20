#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool are_equal(vector <int>& vec)
{
    bool equal = true;
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] != vec[i + 1])
            equal = false;
    }
    return equal;
}

int main()
{
    int team_members;
    cin >> team_members;

    vector <int> team;

    for (size_t i = 0; i < team_members; i++)
    {
        int current_member;
        cin >> current_member;
        if (current_member > 0)
        {
            team.push_back(current_member);
        }
    }

    if (team.size() == 0)
    {
        cout << 1;
        return 0;
    }

    sort(team.begin(), team.begin() + team.size());
    
    int searched_min_num = 0;

    if (team[0] > 1)
    {
        searched_min_num = 1;
    }
    else if (are_equal(team))
    {
        searched_min_num = 2;
    }
    else
    {
        for (size_t i = 0; i < team.size() - 1; i++)
        {
            if (team[i] != team[i + 1] && team[i] != team[i + 1] - 1)
            {
                searched_min_num = team[i] + 1;
                break;
            }
        }
    }
    
    if (searched_min_num == 0)
        searched_min_num = team[team.size() - 1] + 1;

    cout << searched_min_num;
    
    return 0;
}