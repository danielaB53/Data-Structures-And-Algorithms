#include <iostream>
#include <vector>

using namespace std;

void merge(vector<long>& vec, int start, int middle, int end)
{
    vector <long> vec1;
    vector <long> vec2;

    for (size_t i = start; i <= middle; i++)
    {
        vec1.push_back(vec[i]);
    }

    for (size_t i = middle + 1; i <= end; i++)
    {
        vec2.push_back(vec[i]);
    }

    int i = 0;
    int j = 0;
    int sorting_index = start;
    while (i <= middle && j <= end - middle && sorting_index < vec.size() && j < vec2.size() && i < vec1.size())
    {
        if (vec1.empty()==false && vec1[i] < vec2[j])
        {
            vec[sorting_index] = vec1[i];
            i++;
        }
        else
        {
            if (vec2.empty() == true)
                break;
            vec[sorting_index] = vec2[j];
            j++;
        }
        sorting_index++;
    }

    while (i <= middle && sorting_index<vec.size() && i<vec1.size())
    {
        vec[sorting_index] = vec1[i];
        i++;
        sorting_index++;
    }
    while (j <= end - middle && j < vec2.size() && sorting_index<vec.size())
    {
        vec[sorting_index] = vec2[j];
        j++;
        sorting_index++;
    }
}

void merge_sort(vector<long>& vec, int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;

        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);

        merge(vec, left, middle, right);
    }
}

int main()
{
    int number_of_presents;
    cin >> number_of_presents;

    vector <long> presents;

    for (size_t i = 0; i < number_of_presents; i++)
    {
        long current_present;
        cin >> current_present;
        presents.push_back(current_present);
    }

    int employees;
    cin >> employees;

    merge_sort(presents, 0, presents.size() - 1);
    
    long min_sum = 0;
    for (size_t i = 0; i < employees; i++)
    {
        min_sum += presents[i];
    }

    cout << min_sum;

    return 0;
}
