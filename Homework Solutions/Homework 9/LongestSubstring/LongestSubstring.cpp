#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1;
    string str2;
    cin >> str1 >> str2;

    int length1 = str1.size() + 1;
    int length2 = str2.size() + 1;

    int** table = new int*[2];

    for (size_t rows = 0; rows < 2; rows++)
    {
        table[rows] = new int[length2];
    }

    int max_length = 0;

    for (size_t rows = 0; rows < length1; rows++)
    {
        for (size_t cols = 0; cols < length2; cols++)
        {
            if (rows == 0 || cols == 0)
            {
                table[rows % 2][cols] = 0;
            }
            else if (str1[rows - 1] == str2[cols - 1])
            {
                table[rows % 2][cols] = table[(rows - 1) % 2][cols - 1] + 1;
                if (max_length <= table[rows % 2][cols])
                    max_length = table[rows % 2][cols];
            }
            else
            {
                table[rows % 2][cols] = 0;
            }
        }
    }

    for (size_t rows = 0; rows < 2; rows++)
    {
        delete[] table[rows];
    }

    delete[] table;

    cout << max_length;

    return 0;
}
