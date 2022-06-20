#include <iostream>

using namespace std;

int main()
{
    int n_rows, m_cols;
    cin >> n_rows >> m_cols;

    int movie_time, sick_students;
    cin >> movie_time >> sick_students;

    long long sick_covid = 0;

    int** cinema = new int* [n_rows];
    for (size_t i = 0; i < n_rows; i++)
    {
        cinema[i] = new int[m_cols];
    }

    for (size_t i = 0; i < n_rows; i++)
    {
        for (size_t j = 0; j < m_cols; j++)
        {
            cinema[i][j] = -1;
        }
    }

    int at_row, at_col;
    for (size_t i = 0; i < sick_students; i++)
    {
        cin >> at_row >> at_col;
        cinema[at_row - 1][at_col - 1] = 0;
        sick_covid++;
    }

    for (size_t i = 0; i < movie_time; i++)
    {
        for (size_t j = 0; j < n_rows; j++)
        {
            for (size_t h = 0; h < m_cols; h++)
            {
                if (cinema[j][h] <= i)
                {
                    if (j > 0 && cinema[j - 1][h] == -1)
                    {
                        cinema[j - 1][h] = cinema[j][h] + 1;
                        sick_covid++;
                    }
                    if (j < (n_rows - 1) && cinema[j + 1][h] == -1)
                    {
                        cinema[j + 1][h] = cinema[j][h] + 1;
                        sick_covid++;
                    }
                    if (h > 0 && cinema[j][h - 1] == -1)
                    {
                        cinema[j][h - 1] = cinema[j][h] + 1;
                        sick_covid++;
                    }
                    if (h < (m_cols - 1) && cinema[j][h + 1] == -1)
                    {
                        cinema[j][h + 1] = cinema[j][h] + 1;
                        sick_covid++;
                    }
                }
            }
        }
    }

    for (size_t i = 0; i < n_rows; i++)
    {
        delete[] cinema[i];
    }
    delete[] cinema;

    cout << (n_rows * m_cols) - sick_covid;

    return 0;
}
