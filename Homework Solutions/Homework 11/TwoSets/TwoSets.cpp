#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

void distance(vector<vector<pair<long long, long long>>>& graph, vector<long long>& distance,
    long long start)
{
    distance[start] = 0;
    queue<pair<long long, long long>> unvisited;
    unvisited.push({ start, 0 });

    while (unvisited.empty() == false)
    {
        pair<long long, long long> next_vertex;
        next_vertex.first = unvisited.front().first;
        next_vertex.second = unvisited.front().second;
        unvisited.pop();

        for (auto iter : graph[next_vertex.first])
        {
            long long alt_distance = distance[next_vertex.first] + iter.second;

            if (alt_distance < distance[iter.first])
            {
                distance[iter.first] = alt_distance;
                unvisited.push({ iter.first, alt_distance });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long vertice_count, edge_count;
    cin >> vertice_count >> edge_count;

    vector <vector<pair<long long, long long>>> graph(vertice_count);

    long long current_vertex, current_edge, current_distance;
    for (long long i = 0; i < edge_count; i++)
    {
        cin >> current_vertex >> current_edge >> current_distance;
        graph[current_vertex].push_back({ current_edge, current_distance });
        graph[current_edge].push_back({ current_vertex, current_distance });
    }

    long long t_elements;
    cin >> t_elements;

    vector<long long> distance_from_start(graph.size(), LLONG_MAX);

    long long current_element;
    for (size_t i = 0; i < t_elements; i++)
    {
        cin >> current_element;
        distance(graph, distance_from_start, current_element);
    }

    long long query_count;
    cin >> query_count;

    vector<long long> result(query_count);
    long long current_query;
    for (size_t i = 0; i < query_count; i++)
    {
        cin >> current_query;

        result[i] = distance_from_start[current_query];
    }

    for (size_t i = 0; i < query_count; i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}
