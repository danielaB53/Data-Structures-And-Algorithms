#include <iostream>
#include <string>

using namespace std;

static int element_count = 0;

struct Cheatsheet
{
    int answer;
    Cheatsheet* previous_answer;
    Cheatsheet* next_answer;

    Cheatsheet(int answer, Cheatsheet* previous_answer = nullptr, Cheatsheet* next_answer = nullptr)
    {
        this->answer = answer;
        this->previous_answer = previous_answer;
        this->next_answer = next_answer;
    }
};

class List_Cheatsheets
{
private:
    Cheatsheet* head;
    Cheatsheet* middle;
    Cheatsheet* tail;

public:
    List_Cheatsheets(Cheatsheet* head = nullptr, Cheatsheet* middle = nullptr, Cheatsheet* tail = nullptr)
    {
        this->head = head;
        this->middle = middle;
        this->tail = tail;
    }

    void add_element(int data)
    {
        Cheatsheet* new_answer = new Cheatsheet(data);
        if (head == nullptr)
        {
            head = new_answer;
            middle = head;
            tail = head;
            element_count++;
            return;
        }
        else
        {
            Cheatsheet* old_tail = tail;
            old_tail->next_answer = new_answer;
            new_answer->previous_answer = old_tail;
            tail = new_answer;
            tail->next_answer = nullptr;
            element_count++;
            if (element_count % 2 == 0)
                middle = middle->next_answer;

            if (element_count == 2)
            {
                middle = tail;
                middle->next_answer = nullptr;
            }

        }
    }

    void remove_last_element()
    {
        if (head == tail)
        {
            delete head;
            head = nullptr;
            middle = head;
            tail = head;
            element_count = 0;
        }
        else
        {
            Cheatsheet* old_tail = tail;
            tail = old_tail->previous_answer;
            delete old_tail;
            tail->next_answer = nullptr;
            element_count--;
            if (element_count % 2 == 1)
                middle = middle->previous_answer;
            if (element_count == 1)
                middle = head;
            
        }
    }

    void place_back_number_of_elements()
    {
        Cheatsheet* old_head = head;
        Cheatsheet* old_middle = middle;
        Cheatsheet* old_tail = tail;

        if (head == tail || element_count == 0)
            return;
        
        old_tail->next_answer = old_head;
        old_head->previous_answer = old_tail;
        tail = old_middle->previous_answer;
        tail->next_answer = nullptr;
        head = old_middle;
        head->previous_answer = nullptr;
        
        if (element_count % 2 == 1)
        {
            middle = old_tail;
            middle->next_answer = old_head;
        }
        else
        {
            middle = old_head;
            middle->previous_answer = old_tail;
        }

    }

    void print() const
    {
        Cheatsheet* current_element = head;
        while (current_element != nullptr)
        {
            cout << current_element->answer << " ";
            current_element = current_element->next_answer;
        }
    }
};

int main()
{
    int cheatsheet_number;
    cin >> cheatsheet_number;

    List_Cheatsheets test_answers;

    for (size_t i = 0; i < cheatsheet_number; i++)
    {
        string current_request;
        cin >> current_request;
        if (current_request == "add")
        {
            int input_answer;
            cin >> input_answer;
            test_answers.add_element(input_answer);
        }
        else if (current_request == "gun")
        {
            test_answers.remove_last_element();
        }
        else if (current_request == "milen")
        {
            test_answers.place_back_number_of_elements();
        }
    }

    cout << element_count << "\n";

    test_answers.print();

    return 0;
}
