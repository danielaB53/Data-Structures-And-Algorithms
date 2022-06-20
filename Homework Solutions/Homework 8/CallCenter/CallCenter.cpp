#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int index = 0;
struct Operator
{
    int op_index;
    int time_available;
    int clients_count;

    Operator()
    {
        this->op_index = index;
        this->time_available = 0;
        this->clients_count = 0;
        index++;
    }
};

bool more_clients(Operator& op1, Operator& op2)
{
    if(op1.clients_count != op2.clients_count)
        return op1.clients_count > op2.clients_count;
    return op1.op_index < op2.op_index;
}

int main()
{
    int clients, workers;
    cin >> clients >> workers;

    vector <Operator> operators(workers);

    for (size_t i = 0; i < clients; i++)
    {
        int current_start, current_length;
        cin >> current_start >> current_length;

        for (size_t j = 0; j < workers; j++)
        {
            if (operators[(i + j) % workers].time_available <= current_start)
            {
                operators[(i + j) % workers].time_available = current_start + current_length;
                operators[(i + j) % workers].clients_count++;
                break;
            }
        }
    }

    sort(operators.begin(), operators.end(), more_clients);

    int most_clients = operators[0].clients_count;
    for (size_t i = 0; i < operators.size(); i++)
    {
        if (operators[i].clients_count == most_clients)
            cout << operators[i].op_index << " ";
    }

    return 0;
}