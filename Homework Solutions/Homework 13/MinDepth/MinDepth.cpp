#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int dfs(int start, vector<vector<int>>& graph, vector<bool>& visited, int current_depth, int min_depth)
{
    if (current_depth > min_depth)
        return -1;

    int result = current_depth;

    visited[start] = true;

    for (auto iter : graph[start])
    {
        if (visited[iter] == false)
        {
            int ret = dfs(iter, graph, visited, current_depth + 1, min_depth);
            if (ret == -1)
                return -1;
            result = max(result, ret);
        }
    }
    return result;
}

bool sort_depths(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main()
{

    int vertice_count;
    cin >> vertice_count;

    vector<vector<int>> graph(vertice_count);
    vector<int> parents(vertice_count, -1);

    int current_from, current_to;
    for (size_t i = 0; i < vertice_count - 1; i++)
    {
        cin >> current_from >> current_to;
        graph[current_from].push_back(current_to);
        graph[current_to].push_back(current_from);
    }

    vector<pair<int, int>> results;

    vector<bool> visited1(vertice_count, false);

    int previous_depth = dfs(0, graph, visited1, 0, INT_MAX);
    results.push_back({ 0, previous_depth });

    for (size_t i = 1; i < vertice_count; i++)
    {
        vector<bool> visited(vertice_count, false);
        int current_depth = dfs(i, graph, visited, 0, previous_depth);
        if (current_depth == -1)
            continue;
        if (current_depth < previous_depth)
            previous_depth = current_depth;
        results.push_back({ i, current_depth });
    }

    sort(results.begin(), results.end(), sort_depths);

    int min_depth = results[0].second;

    int counter = 0;
    while (counter < results.size() && results[counter].second == min_depth)
    {
        cout << results[counter].first << " ";
        counter++;
    }

    return 0;
}
