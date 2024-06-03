#include <iostream>

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

void inputNode(node*& head) // whether head has data or not
{
    int data;
    cin >> data;
    if (data == 0)
        return;
    if (!head)
    {
        head = createNode(data);
        cin >> data;
    }
    node* ptr = head;
    while (data != 0)
    {
        node* tmp = createNode(data);
        ptr->link = tmp;
        ptr = ptr->link;
        cin >> data;
    }
}

void displayNode(node* head)
{
    node* cur = head;
    while (cur != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->link;
    }
}

void push(node*& head, int x)
{
    node* tmp = createNode(x);
    tmp->link = head;
    head = tmp;
}

int pop(node*& head)
{
    if (!head) return -1;
    int data = head->data;
    node* tmp = head->link;
    delete head;
    head = tmp;
    return data;
}

void enQ(node*& head, node*& tail, int x)
{
    if (!head)
    {
        head = createNode(x);
        tail = head;
        return;
    }
    node* tmp = createNode(x);
    tail->link = tmp;
    tail = tmp;
}

bool deQ(node*& head, node*& tail, int& x)
{
    if (!head)
        return false;
    node*tmp = head->link;
    x = head->data;
    delete head;
    head = tmp
    if (!head)
        tail = NULL;
    return true;
}

int main()
{
    int x;
    node* head = NULL;
    inputNode(head);
    node* tail = head;
    if (head)
        while (tail->link)
            tail = tail->link;
    enQ(head,tail, 100);
    deQ(head,tail, x);
    cout << x;
    displayNode(head);
    return 0;
}
