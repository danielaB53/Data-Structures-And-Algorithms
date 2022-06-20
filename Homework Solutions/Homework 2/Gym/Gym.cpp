#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Boys_Gym_Capacity
{
    double weight_diameter;
    int time;
    int id_index;
    double efficiency;
};

bool compare_capacity(Boys_Gym_Capacity& boy1, Boys_Gym_Capacity& boy2)
{
    if (boy1.efficiency == boy2.efficiency)
        return boy1.weight_diameter > boy2.weight_diameter;
    return boy1.efficiency > boy2.efficiency;
}

int main()
{
    int number_of_boys;
    cin >> number_of_boys;

    vector <Boys_Gym_Capacity> gym;

    int id = 1;
    for (size_t i = 0; i < number_of_boys; i++)
    {
        double current_diameter;
        cin >> current_diameter;
        int current_time;
        cin >> current_time;

        Boys_Gym_Capacity current_boy;
        current_boy.weight_diameter = current_diameter;
        current_boy.time = current_time;
        current_boy.id_index = id;
        current_boy.efficiency = ((current_diameter / 2.0) * (current_diameter / 2.0)) / current_time;
        id++;

        gym.push_back(current_boy);
    }

    sort(gym.begin(), gym.end(), compare_capacity);

    for (size_t i = 0; i < gym.size(); i++)
    {
        cout << gym[i].id_index << " ";
    }

    return 0;
}
