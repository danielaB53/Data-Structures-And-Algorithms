#include <iostream>
#include <vector>
#include <string>

const int MAX_SIZE = 100001;

using namespace std;

void depth_first_search(int start, vector<int>& vertices, vector<bool>& visited, vector<vector<int>>& graph)
{
    if (visited[start] == false)
        vertices.push_back(start);

    visited[start] = true;

    for (auto iter : graph[start])
    {
        if (visited[iter] == false)
        {
            depth_first_search(iter, vertices, visited, graph);
        }
    }
}

int main()
{
    int queries;
    cin >> queries;

    vector<string> query_answers;

    for (size_t i = 0; i < queries; i++)
    {
        int vertice_count, edge_count;
        cin >> vertice_count >> edge_count;

        vector<vector<int>> graph(MAX_SIZE);
        vector<int> deg(MAX_SIZE, 0);

        int current_from, current_to;
        for (size_t j = 0; j < edge_count; j++)
        {
            cin >> current_from >> current_to;
            graph[current_from].push_back(current_to);
            graph[current_to].push_back(current_from);
            deg[current_from]++;
            deg[current_to]++;
        }

        vector<bool> visited(MAX_SIZE, false);
        int num_of_vertices = 0;
        vector<int> connected_vertices;

        depth_first_search(current_from, connected_vertices, visited, graph);

        if (connected_vertices.size() != vertice_count)
        {
            query_answers.push_back("none");
            continue;
        }

        int odd_deg_count = 0;
        for (size_t h = 0; h < MAX_SIZE; h++)
        {
            if (deg[h] % 2 == 1)
                odd_deg_count++;
        }

        if (odd_deg_count > 2)
            query_answers.push_back("none");
        else if (odd_deg_count == 0)
            query_answers.push_back("ecycle");
        else if (odd_deg_count == 2)
            query_answers.push_back("epath");
    }

    for (size_t i = 0; i < query_answers.size(); i++)
    {
        cout << query_answers[i] << "\n";
    }

    return 0;
}
