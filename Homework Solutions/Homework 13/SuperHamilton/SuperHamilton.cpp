#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX_SIZE = 26;

int valid_path_count = 0;

void hamilton(int start, int end, int current_length, int vertice_count,
    vector<vector<int>>& graph, vector<bool>& visited)
{
    if (start == end && current_length == vertice_count)
    {
        valid_path_count++;
        return;
    }
    else if (current_length == vertice_count && start != end)
    {
        current_length--;
        return;
    }

    visited[start] = true;
    for (auto iter : graph[start])
    {
        if (visited[iter] == false)
        {
            hamilton(iter, end, current_length + 1, vertice_count, graph, visited);
        }
    }
    visited[start] = false;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int vertice_count = rows * cols;

    int graph[MAX_SIZE][MAX_SIZE];

    vector<vector<int>> neighbours(vertice_count);

    pair<int, int> start_coordinates = { -1, -1 };
    pair<int, int> end_coordinates = { -1, -1 };

    int counter = 0;

    char current_symbol;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cin >> current_symbol;

            if (current_symbol == 's')
            {
                start_coordinates.first = i;
                start_coordinates.second = j;
            }
            else if (current_symbol == 'e')
            {
                end_coordinates.first = i;
                end_coordinates.second = j;
            }
            else if (current_symbol == 'x')
            {
                graph[i][j] = -1;
                continue;
            }

            graph[i][j] = i * cols + j;
            if (current_symbol != 'x')
            {
                counter++;
            }

        }
    }

    int start = graph[start_coordinates.first][start_coordinates.second];
    int end = graph[end_coordinates.first][end_coordinates.second];

    int current = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (i - 1 != -1 && graph[i - 1][j] != -1)
            {
                neighbours[current].push_back(graph[i - 1][j]);
            }
            if (i + 1 != rows && graph[i + 1][j] != -1)
            {
                neighbours[current].push_back(graph[i + 1][j]);
            }
            if (j - 1 != -1 && graph[i][j - 1] != -1)
            {
                neighbours[current].push_back(graph[i][j - 1]);
            }
            if (j + 1 != cols && graph[i][j + 1] != -1)
            {
                neighbours[current].push_back(graph[i][j + 1]);
            }
            current++;
        }
    }

    vector<bool> visited(vertice_count, false);
    hamilton(start, end, 1, counter, neighbours, visited);

    cout << valid_path_count;

    return 0;
}
