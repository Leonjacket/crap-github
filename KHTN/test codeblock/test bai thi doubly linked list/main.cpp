#include <iostream>

using namespace std;

struct Dnode
{
    Dnode* prev;
    int data;
    Dnode* next;
};

Dnode* createNode(int data)
{
    Dnode* tmp = new Dnode;
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

void createList(Dnode*& head)
{
    int n;
    cin >> n;
    if(n==0) return;
    if(!head)
        head = createNode(n);
    Dnode* ptr = head;
    while(cin >> n && n != 0)
    {
        Dnode* tmp = createNode(n);
        tmp->prev = ptr;
        tmp->next = NULL;
        ptr->next = tmp;
        ptr = ptr->next;
    }
}

Dnode* findBiggest(Dnode* head)
{
    if(!head) return NULL;
    Dnode* tmp = head;
    while(head)
    {
        if(tmp->data < head->data)
            tmp = head;
        head = head->next;
    }
    return tmp;
}

void removeBiggest(Dnode*& head)
{
    int k = head->data;
    Dnode* ptr = head;
    while(ptr)
    {
        Dnode* tmp = findBiggest(ptr);
        if(tmp->data >= k)
        {
            k = tmp->data;
            if (tmp == head)
            {
                if(ptr == head)
                    ptr = ptr->next;
                head = head->next;
                head->prev = NULL;
                delete tmp;
            }
            else
            {
                ptr = tmp->prev;
                ptr->next = tmp->next;
                tmp->next->prev = ptr;
            }
        }
        else return;
    }
}

Dnode* elementKthFromEnd(Dnode* head, int k)
{
    int x = 1;
    while(head->next)
    {
        head = head->next;
        x++;
    }
    if(k > x) return NULL;
    while(k != 1)
    {
        head = head->prev;
        k--;
    }
    return head;
}

void removeElementKthFromEnd(Dnode*& head, int k)
{
    int x = 1;
    Dnode* ptr = head;
    while(ptr->next)
    {
        ptr = ptr->next;
        x++;
    }
    if(k > x) return;
    while(k != 1)
    {
        ptr = ptr->prev;
        k--;
    }

    Dnode* prev = ptr->prev;
    Dnode* next = ptr->next;

    if(prev == NULL)
    {
        delete ptr;
        ptr = next;
        ptr->prev = NULL;
        head = ptr;
        return;
    }

    if(next == NULL)
    {
        delete ptr;
        ptr = prev;
        ptr->next = NULL;
        return;
    }
    prev->next = next;
    next->prev = prev;
    delete ptr;
}

void rotateK(Dnode*& head, int k)
{
    if(k==0) return;
    int x = 1;
    Dnode* ptr = head;
    while(ptr->next)
    {
        ptr = ptr->next;
        x++;
    }
    if(k >= x) return;
    while(k != 1)
    {
        ptr = ptr->prev;
        k--;
    }

    ptr->prev->next = NULL;
    ptr->prev = NULL;
    Dnode* tmp = ptr;
    while(ptr->next)
        ptr = ptr->next;
    ptr->next = head;
    head = tmp;
}

void reverseList(Dnode*& head)
{
    Dnode* prev= NULL;
    Dnode* next = head;
    while(next)
    {
        next->prev = next->next;
        next->next = prev;
        prev = next;
        next = next->prev;
    }
    head = prev;
}

void printList(Dnode* head)
{
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    Dnode* head = NULL;
    createList(head);

    reverseList(head);

    printList(head);

    return 0;
}
