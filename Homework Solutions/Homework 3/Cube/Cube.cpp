#include <iostream>

using namespace std;

long double absolute_val(double number)
{
    if (number < 0)
        return -number;
    return number;
}

long find_cube(long number)
{
    long double start = 0.0;
    long double end = number;

    while (true)
    {
        long double middle = (start + end) / 2;
        long double difference = (number - middle * middle * middle);
        if (0.0 <= absolute_val(difference) && abs(difference)<=1.0)
            return long(middle);
        else if ((middle * middle * middle) > number)
            end = middle;
        else if (middle * middle * middle < number)
            start = middle;
    }
}

long long presents_counter(long long points)
{
    long long presents_count = 0;
    long long counter = 0;
    while (points > 0)
    {
        long long current_cube = find_cube(points);
        long long current_largest = current_cube * current_cube * current_cube;
        presents_count++;
        if (current_cube == 0)
            break;

        points -= current_largest;
    }
    return presents_count;
}

int main()
{
    long long points;
    cin >> points;

    cout << presents_counter(points);

    return 0;
}