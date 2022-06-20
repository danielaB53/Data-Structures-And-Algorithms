#include <iostream>
#include <vector>
#include<algorithm>
#include <list>

using namespace std;

struct Node_Child
{
    long long data;
    Node_Child* left;
    Node_Child* right;

    Node_Child(long long data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree
{
private:
    Node_Child* root;

    Node_Child* add_element(long long value, Node_Child* current_root)
    {
        if (current_root == nullptr)
            return new Node_Child(value);

        if (value < current_root->data)
            current_root->left = add_element(value, current_root->left);
        else
            current_root->right = add_element(value, current_root->right);

        return current_root;
    }

    Node_Child* find_min_element(Node_Child* current_node)
    {
        if (current_node->left != nullptr)
            return find_min_element(current_node->left);
        return current_node;
    }

    Node_Child* remove_leaf(long long value, Node_Child* current_root)
    {
        if (current_root == nullptr)
            return nullptr;

        if (value > current_root->data)
            current_root->right = remove_leaf(value, current_root->right);
        else if (value < current_root->data)
            current_root->left = remove_leaf(value, current_root->left);
        else
        {

            if (current_root->right == nullptr)
            {
                Node_Child* old_left = current_root->left;
                delete current_root;
                return old_left;
            }

            Node_Child* min_in_right_subtree = find_min_element(current_root->right);
            current_root->data = min_in_right_subtree->data;
            current_root->right = remove_leaf(current_root->data, current_root->right);
        }
        return current_root;
    }

    long long get_height(Node_Child* current) const
    {
        if (current == nullptr)
            return 0;

        long long height_left = get_height(current->left);
        long long height_right = get_height(current->right);

        return (max(height_left, height_right) + 1);
    }


    void level_print(Node_Child* current, long long level)
    {
        if (current == nullptr)
            return;

        if (level == 0)
            cout << current->data << " ";
        else if (level > 0)
        {
            level_print(current->left, level - 1);
            level_print(current->right, level - 1);
        }
    }

public:

    Tree()
    {
        root = nullptr;
    }

    void add_element(int value)
    {
        if (root == nullptr)
            root = new Node_Child(value);
        else
            root = add_element(value, root);
    }

    void remove_element(int value)
    {
        root = remove_leaf(value, root);
    }

    long long get_height() const
    {
        return get_height(root);
    }

    void level_order_print()
    {
        for (size_t i = 0; i < get_height(); i++)
        {
            level_print(root, i);
        }
    }
};

int main()
{
    long long number_count;
    cin >> number_count;

    long long k_largest;
    cin >> k_largest;

    vector <long long> sorted;

    Tree input_nums;

    long long curr_num;
    for (size_t i = 0; i < number_count; i++)
    {
        cin >> curr_num;
        input_nums.add_element(curr_num);
        sorted.push_back(curr_num);
    }

    sort(sorted.begin(), sorted.begin() + number_count, greater<>());

    long long to_be_removed = sorted[k_largest - 1];

    input_nums.remove_element(to_be_removed);

    input_nums.level_order_print();

    return 0;
}