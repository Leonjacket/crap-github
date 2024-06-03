#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int data;
    node* link;
};

node* createNode(int data)
{
    node* tmp = new node;
    tmp->data = data;
    tmp->link = NULL;
    return tmp;
}

void createList(node*& head)
{
    int n;
    cin >> n;
    if (!head)
        head = createNode(n);
    node* ptr = head;
    while(cin >> n && n != 0)
    {
        node* tmp = createNode(n);
        ptr->link = tmp;
        ptr = ptr->link;
    }
}

bool isPalindrome(node* head)
{
    node* slow = head, *fast = head;
    node* prev= NULL, *next = head;
    while(fast && fast->link)
    {
        fast = fast->link->link;
        slow = slow->link;

        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }

    if (fast)
        slow = slow->link;
    fast = prev;
    while(slow)
    {
        if(fast->data != slow->data)
            return 0;
        fast = fast->link;
        slow = slow->link;
    }
    return 1;
}

int main()
{
    return 0;
}
