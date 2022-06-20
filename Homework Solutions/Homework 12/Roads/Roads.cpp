#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Town
{
    long long from;
    long long to;
    long long effort;
    long long price;
    long long num;

    Town(long long from, long long to, long long effort, long long price, long long num) : from(from), to(to),
        effort(effort), price(price), num(num) {}

    bool operator<(const Town& rhs) const
    {
        if (effort == rhs.effort)
            return price <= rhs.price;

        return effort >= rhs.effort;
    }
};

int main()
{
    long long town_count, road_count;
    cin >> town_count >> road_count;

    vector<vector<Town>> road(town_count + 1);

    long long current_from, current_to, current_effort, current_price;
    for (size_t i = 0; i < road_count; i++)
    {
        cin >> current_from >> current_to >> current_effort >> current_price;
        Town current = Town(current_from, current_to, current_effort, current_price, i + 1);
        road[current_from].push_back(current);
        Town other = Town(current_to, current_from, current_effort, current_price, i + 1);
        road[current_to].push_back(other);
    }

    vector<long long> road_nums;
    vector <bool> visited(town_count + 1, false);
    priority_queue<Town> next_destination;

    next_destination.push({ -1, 1, 0, 0, 0 });

    while (next_destination.empty() == false)
    {
        Town next = next_destination.top();
        next_destination.pop();

        if (visited[next.to] == true)
        {
            continue;
        }

        visited[next.to] = true;

        long long town_num = next.num;
        long long next_town = next.to;
        long long town_parent = next.from;

        if (town_parent != -1)
            road_nums.push_back(town_num);

        for (auto iter : road[next_town])
            next_destination.push(iter);
    }

    sort(road_nums.begin(), road_nums.end());

    for (size_t i = 0; i < road_nums.size(); i++)
    {
        cout << road_nums[i] << "\n";
    }

    return 0;
}