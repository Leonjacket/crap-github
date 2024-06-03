#include <iostream>

using namespace std;

struct node
{
    node* prev;
    int data;
    node* next;
};

node* createNode(int data)
{
    node* tmp = new node;
    tmp->data = data;
    tmp->next = tmp;
    tmp-> prev = tmp;
    return tmp;
}

void createList(node*& tail) // chua dung
{
    int data;
    cin >> data;
    if (data == 0) return;
    if(!tail)
    {
        tail = createNode(data);
        cin >> data;
    }

    node* ptr = tail;
    while (data != 0)
    {
        node* tmp = createNode(data);
        tmp->next = tail;
        tmp->prev = ptr;

        tail->prev = tmp;
        ptr->next = tmp;
        ptr = ptr->next;

        cin >> data;
    }
    tail = tail->prev;
}

void addAtBeginning(node*& tail, int data)
{
    if (!tail)
    {
        tail = createNode(data);
        return;
    }
    node* tmp = createNode(data);

    node* head = tail->next;
    head->prev = tmp;
    tail->next = tmp;
    tmp->next = head;
    tmp->prev = tail;

}

void addAtEnd(node*& tail, int data)
{
    if (!tail)
    {
        tail = createNode(data);
        return;
    }
    node* tmp = createNode(data);
    tmp->next = tail->next;
    tmp->prev = tail;
    tail->next->prev = tmp;
    tail->next = tmp;
    tail = tmp;
}

void addAfterPos(node*& tail, int data, int pos)
{
    node* tmp = createNode(data);
    node* ptr = tail->next;
    while(pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    tmp->prev = ptr;
    tmp->next = ptr->next;
    ptr->next = tmp;
    tmp->next->prev = tmp;
    if (ptr = tail)
        tail = tmp;
}

void delFirst(node*& tail)
{
    if (!tail) return;
    if (tail == tail->next)
    {
        delete tail;
        tail = NULL;
        return;
    }
    node* tmp = tail->next;
    tail->next = tmp->next;
    tmp->next->prev = tail;
    delete tmp;
}

void delLast(node*& tail)
{
    if(!tail) return;
    if(tail == tail->next)
    {
        delete tail;
        tail = NULL;
        return;
    }
    node* tmp = tail->prev;
    tmp->next = tail->next;
    tail->next->prev = tmp;
    delete tail;
    tail = tmp;
}

void delPos(node*& tail, int pos)
{
    if (!tail) return;
    node* ptr = tail->next;
    if (pos == 1)
    {
        ptr->next->prev = tail;
        tail->next = ptr->next;
        delete ptr;
        return;
    }

    while (pos != 2)
    {
        ptr = ptr->next;
        pos--;
    }
    node* tmp = ptr->next;
    tmp->next->prev = ptr;
    ptr->next = tmp->next;
    delete tmp;
}

void printList(node* tail)
{
    node* tmp = tail->next;
    if (!tail) return;
    do
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while(tmp != tail->next);
}

int main()
{
    node* tail = NULL;
    addAtEnd(tail,1);
    addAtEnd(tail,2);
    addAtEnd(tail,3);


    if (!tail) return 0;
    node* tmp = tail->next;
    if(!tail) return 0;
    printList(tail);

    return 0;
}
