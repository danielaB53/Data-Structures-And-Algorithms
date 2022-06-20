#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct First
{
    bool operator()(const int& first, const int& second)
    {
        return first < second;
    }
};

struct Second
{
    bool operator()(const int& first, const int& second)
    {
        return first > second;
    }
};

int main()
{
    int citizens;
    cin >> citizens;

    priority_queue<int, vector<int>, First> first;
    priority_queue<int, vector<int>, Second> second;

    vector<double> medians;

    for (size_t i = 0; i < citizens; i++)
    {
        int current_citizen;
        cin >> current_citizen;
        
        if (first.size() == 0 && second.size() == 0)
        {
            first.push(current_citizen);
        }
        else if (current_citizen >= first.top())
        {
            second.push(current_citizen);
            if (first.size() + 1 < second.size())
            {
                first.push(second.top());
                second.pop();
            }
        }
        else
        {
            first.push(current_citizen);
            if (second.size() + 1 < first.size())
            {
                second.push(first.top());
                first.pop();
            }
        }

        double current_med = 0.0;
        if (first.size() == second.size())
        {
            current_med = ((double)first.top() + (double)second.top()) / 2.0;
        }
        else if (first.size() > second.size())
        {
            current_med = (double)first.top();
        }
        else if (second.size() > first.size())
        {
            current_med = (double)second.top();
        }

        medians.push_back(current_med);
    
    }

    for (size_t i = 0; i < medians.size(); i++)
    {
        cout << medians[i] << "\n";
    }

    return 0;
}
