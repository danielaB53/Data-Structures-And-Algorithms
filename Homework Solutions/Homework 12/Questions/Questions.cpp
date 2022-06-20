#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void depth_first_search(long long start, long long component_marker, vector<long long>& components,
    vector<vector<long long>>& graph, vector<bool>& visited)
{
    visited[start] = true;
    components[start] = component_marker;

    for (auto iter : graph[start])
    {
        if (visited[iter] == false)
        {
            depth_first_search(iter, component_marker, components, graph, visited);
        }
    }
}


void make_equal(long long previous_component, long long new_component, vector<long long>& components)
{
    long long new_component_num = components[new_component];
    long long previous_component_num = components[previous_component];
    for (size_t i = 0; i < components.size(); i++)
    {
        if (components[i] == new_component_num)
            components[i] = previous_component_num;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long edge_count;
    cin >> edge_count;

    vector<vector<long long>> graph(edge_count + 1);
    vector<long long> components(edge_count + 1, 0);

    long long roads;
    cin >> roads;

    long long currend_edge, current_child;
    for (size_t i = 0; i < roads; i++)
    {
        cin >> currend_edge >> current_child;
        graph[currend_edge].push_back(current_child);
        graph[current_child].push_back(currend_edge);
    }

    vector<bool> visited(graph.size(), false);
    for (size_t i = 1; i <= edge_count; i++)
    {
        if (visited[i] == false)
        {
            depth_first_search(i, i, components, graph, visited);
        }
    }

    long long questions;
    cin >> questions;

    vector <bool> results;

    long long question_count = 0;

    long long question_type, city, connection;
    for (size_t i = 0; i < questions; i++)
    {
        cin >> question_type >> city >> connection;
        if (question_type == 1)
        {
            bool result = (components[city] == components[connection]);
            results.push_back(result);
        }
        else if (question_type == 2 && components[city] != components[connection])
        {
            make_equal(city, connection, components);
        }
    }

    for (size_t i = 0; i < results.size(); i++)
    {
        cout << results[i];
    }

    return 0;
}