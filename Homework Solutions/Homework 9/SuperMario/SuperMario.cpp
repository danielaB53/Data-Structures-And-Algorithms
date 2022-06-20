#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int door_count;
    cin >> door_count;

    vector<int> initial_keys(door_count);
    int key;
    for (size_t i = 0; i < door_count; i++)
    {
        cin >> key;
        initial_keys[i] = key;
    }

    unordered_map<int, int> keys;

    int smashed_doors = 0;
    int current_door;
    for (size_t i = 0; i < door_count; i++)
    {
        cin >> current_door;
        int current_key = initial_keys[i];
        auto current = keys.find(current_key);
        if (current == keys.end())
        {
            int current_key_count = 1;
            keys[current_key] = current_key_count;
            keys.insert(make_pair(current_key, current_key_count));
        }
        else
        {
            int old_count = keys[current_key];
            old_count++;
            keys[current_key] = old_count;
        }

        auto door = keys.find(current_door);
        if (door == keys.end())
        {
            smashed_doors++;
        }
        else
        {
            int count = keys[current_door];
            count--;
            keys[current_door] = count;
            if (count == 0)
                keys.erase(current_door);
        }
    }

    cout << smashed_doors;

    return 0;
}
