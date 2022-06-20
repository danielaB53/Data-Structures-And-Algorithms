#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    cin >> word;

    int written_symbols;
    cin >> written_symbols;

    char searched_symbol;
    cin >> searched_symbol;

    int letter_in_word_counter = 0;
    for (size_t i = 0; i < word.size(); i++)
    {
        if (word[i] == searched_symbol)
            letter_in_word_counter++;
    }

    int leftover_symbols = written_symbols % word.size();

    int symbol_counter = 0;

    for (size_t i = 0; i < leftover_symbols; i++)
    {
        if (word[i] == searched_symbol)
            symbol_counter++;
    }

    symbol_counter += ((written_symbols / word.size()) * letter_in_word_counter);
    cout << symbol_counter;

    return 0;
}
