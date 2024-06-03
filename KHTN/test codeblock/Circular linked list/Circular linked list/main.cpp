#include <iostream>

using namespace std;

struct node
{
    int data;
    node* link;
};

node* createNewNode(int data)
{
    node* tmp = new node;
    tmp->data = data;
    tmp->link = tmp;
    return tmp;
}

void createCirucularLinkedList(node*& tail)
{
    int n;
    cin >> n;
    if (n == 0)
        return;
    if (tail == NULL)
    {
        tail = createNewNode(n);
        cin >> n;
    }
    node* head = tail;
    while (n != 0)
    {
        node* tmp = createNewNode(n);
        tmp->link = head;
        tail->link = tmp;
        tail = tail->link;
        cin >> n;
    }
}

void addAtEnd(node*& tail, int data)
{
    node* tmp = createNewNode(data);
    tmp->link = tail->link;
    tail->link = tmp;
    tail = tmp;
}

void addAfterPos(node*& tail, int data, int pos)
{
    node* cur = tail->link;
    while (pos != 1)
    {
        cur = cur->link;
        pos--;
    }
    node* tmp = createNewNode(data);
    tmp->link = cur->link;
    cur->link = tmp;
    if (cur == tail)
        tail = tmp;
}

void deleteFirstNode(node*& tail)
{
    if (!tail) return;
    if (tail->link == tail)
    {
        free (tail);
        tail = NULL;
        return;
    }
    node* tmp = tail->link;
    tail->link = tmp->link;
    delete tmp;
    tmp = NULL;
}

void deleteLastNode(node*& tail)
{
    if (!tail) return;
    if (tail->link == tail)
    {
        delete tail;
        tail = NULL;
        return;
    }
    node* ptr = tail->link;
    while (ptr->link != tail)
        ptr = ptr->link;

    ptr->link = tail->link;
    delete(tail);
    tail = ptr;
}

void deleteAtPos(node*& tail, int pos)
{
    if (!tail) return;
    node* ptr = tail->link;
    if (pos == 1)
    {
        tail->link = ptr->link;
        delete ptr;
        return;
    }
    while (pos != 2)
    {
        ptr = ptr->link;
        pos--;
    }
    node* tmp = ptr->link;
    ptr->link = tmp->link;
    if (tmp == tail)
        tail = ptr;
    delete tmp;
    tmp = NULL;
}

int countElement(node* tail)
{
    node* tmp = tail->link;
    int count = 0;
    do
    {
        tmp = tmp->link;
        count++;
    } while(tmp != tail->link);
    return count;
}

int searchElement(node* tail, int data)
{
    node* tmp = tail->link;
    int index = 1;
    if (!tail) return -2;
    do
    {
        if (tmp->data == data)
            return index;
        tmp = tmp->link;
        index++;
    } while(tmp != tail->link);
    return -1;
}

void insertAtBeginning(node*& tail, int data)
{
    if (!tail)
    {
        tail = createNewNode(data);
        return;
    }
    node*tmp = createNewNode(data);
    tmp->link = tail->link;
    tail->link = tmp;
}

int main()
{
    node* tail = NULL;
    createCirucularLinkedList(tail);
    insertAtBeginning(tail, 100);
    if (tail == NULL) return 0;

    node* tmp = tail->link;
    do
    {
        if (!tmp) return 0;
        printf("%d ",tmp->data);
        tmp = tmp->link;
    }
    while(tmp!=tail->link);

    return 0;
}

