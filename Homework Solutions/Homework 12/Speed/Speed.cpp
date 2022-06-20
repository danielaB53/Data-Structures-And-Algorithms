#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Road
{
    long long from;
    long long to;
    long long opt_speed;

    Road(long long from = 0, long long to = 0, long long speed = 0) : from(from), to(to), opt_speed(speed)
    {
    }

    bool operator<(const Road& rhs) const
    {
        return opt_speed < rhs.opt_speed;
    }
};

long long find_parent(long long town, vector<long long>& parents)
{
    if (town != parents[town])
        parents[town] = find_parent(parents[town], parents);
    return parents[town];
}

void connect(long long first_town, long long second_town, vector<long long>& parents)
{
    if (parents[first_town] != parents[second_town])
    {
        long long old_parent = parents[first_town];
        parents[old_parent] = second_town;
    }
}

vector<long long> kruskal(long long start, vector<Road>& graph, long long town_size, long long min_diff)
{
    vector<long long> parents(town_size + 1);
    for (int i = 1; i <= town_size; i++)
    {
        parents[i] = i;
    }

    long long current_size = graph.size() - start;
    vector<long long> result(3);

    long long min_speed = graph[start].opt_speed;
    long long max_speed = graph[start].opt_speed;

    int roads_count = 0;
    for (size_t i = 0; i < current_size && roads_count < town_size - 1; i++)
    {

        auto road = graph[start + i];

        if (find_parent(road.from, parents) == find_parent(road.to, parents))
            continue;

        roads_count++;

        if (road.opt_speed < min_speed)
            min_speed = road.opt_speed;

        if (road.opt_speed > max_speed)
            max_speed = road.opt_speed;

        connect(road.from, road.to, parents);
    }

    if (roads_count < town_size - 1)
    {
        result[0] = 0;
        result[1] = 0;
        result[2] = -1;
        return result;
    }

    long long diff = max_speed - min_speed;
    result[0] = min_speed;
    result[1] = max_speed;
    result[2] = diff;

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long town_count, road_count;
    cin >> town_count >> road_count;

    vector<Road> roads(road_count);

    int current_from, current_to, current_speed;
    for (size_t i = 0; i < road_count; i++)
    {
        cin >> current_from >> current_to >> current_speed;
        roads[i].from = current_from;
        roads[i].to = current_to;
        roads[i].opt_speed = current_speed;
    }

    sort(roads.begin(), roads.end());

    long long min_diff = -1;
    long long min_start = roads[0].opt_speed;
    long long min_end = roads[0].opt_speed;
    for (size_t i = 0; i < roads.size(); i++)
    {
        vector<long long> result = kruskal(i, roads, town_count, min_diff);
        if (result[2] == -1)
            break;

        if (min_diff == -1 || result[2] < min_diff || (result[2] == min_diff && result[0] < min_start))
        {
            min_diff = result[2];
            min_start = result[0];
            min_end = result[1];
        }
    }

    cout << min_start << " " << min_end;

    return 0;
}