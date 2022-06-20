#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Task
{
    long long index;
    long long time_started;
    long long length;
};

struct Time_Sort
{
    bool operator()(const Task& t1, const Task& t2)
    {
        return t1.time_started > t2.time_started;
    }
};

struct Time_Length
{
    bool operator()(const Task& t1, const Task& t2)
    {
        if (t1.length == t2.length)
            return t1.index > t2.index;
        return t1.length > t2.length;
    }
};

int main()
{
    long long task_count;
    cin >> task_count;

    priority_queue <Task, vector<Task>, Time_Sort> tasks_by_time;

    priority_queue <Task, vector<Task>, Time_Length> tasks_by_length;


    for (size_t i = 0; i < task_count; i++)
    {
        long long time, length;
        cin >> time >> length;

        Task current;
        current.index = i;
        current.time_started = time;
        current.length = length;

        tasks_by_time.push(current);
    }

    long long current_time = 0;
    while (tasks_by_time.empty() == false)
    {
        if (tasks_by_time.top().time_started <= current_time)
        {
            while (tasks_by_time.empty() == false && tasks_by_time.top().time_started <= current_time)
            {
                tasks_by_length.push(tasks_by_time.top());
                tasks_by_time.pop();
            }
        }
        else if(tasks_by_length.empty())
        {
            tasks_by_length.push(tasks_by_time.top());
            current_time = tasks_by_time.top().time_started;
            tasks_by_time.pop();
            while (tasks_by_time.empty() == false && tasks_by_time.top().time_started <= current_time)
            {
                tasks_by_length.push(tasks_by_time.top());
                tasks_by_time.pop();
            }
        }
        cout << tasks_by_length.top().index << " ";
        current_time += tasks_by_length.top().length;
        tasks_by_length.pop();
        
    }

    while (tasks_by_length.empty() == false)
    {
        cout << tasks_by_length.top().index << " ";
        tasks_by_length.pop();
    }

    return 0;
}
