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
    tmp->link = NULL;
    return tmp;
}

void inputNode(node*& head) // whether head has data or not
{
    int n;
    node* cur = head;
    if (head == NULL)
    {
        cin >> n;
        head = new node;
        cur = head;
        if (n == 0)
            return;
        cur->data = n;
        cur->link = NULL;
    }
    while (cur->link)
       cur = cur->link;
    while(cin >> n)
    {
        if (n==0) break;
        cur->link = new node;
        cur = cur->link;
        cur->data = n;
        cur->link = NULL;
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

void insertAfterNodeK(node*& head, int x, int k)
{
    if (head == NULL)   return;
    node* cur = head;
    while (k != 1)
    {
        cur = cur->link;
        k--;
    }
    node* tmp = new node;
    tmp->data = x;
    tmp->link = cur->link;
    cur->link = tmp;
}

void insertBeforeNodeK(node*& head, int x, int k)
{
    node* ptr = new node;
    ptr->data = x;
    if (k == 1)
    {
        ptr->link = head;
        head = ptr;
        return;
    }
    node* tmp = head;
    while (k != 2)
    {
        tmp = tmp->link;
        k--;
    }
    ptr->link = tmp->link;
    tmp->link = ptr;
}

void deleteNode(node*& head)
{
    while(head != NULL)
    {
        node* tmp = head->link;
        delete head;
        head = tmp;
    }
}

void reverseList(node*& head)
{
    node* next = head, *prev = NULL;
    if(!head) return;
    while(head)
    {
        next = next->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
}

void reverseListRecursion(node* head)
{
    if(!head)
        return;
    else
    {
        reverseListRecursion(head->link);
        printf("%d ", head->data);
    }
}

node* findX(node* head, int x)
{
    node* tmp = head;
    while(tmp->data != x && tmp != NULL)
        tmp = tmp->link;
    if (tmp == NULL)
        return NULL;
    else return tmp;
}

void mergeOrderedLists(node*& head1, node*& head2)
{
    if(head1 == NULL)
    {
        head1 = head2;
        head2 = NULL;
        return;
    }
    if(head2 == NULL) return;
    node* ptr = NULL, *tail = NULL;
    while(!head1 && !head2)
    {
        if(head1->data <= head2->data)
        {
            if(ptr == NULL)
            {
                ptr = head1;
                tail = head1;
            }
            else
            {
                tail->link = head1;
                tail = tail->link;
            }
            head1 = head1->link;
        }
        else
        {
            if(ptr == NULL)
            {
                ptr = head2;
                tail = head2;
            }
            else
            {
                tail->link = head2;
                tail = tail->link;
            }
            head2 = head2->link;
        }
    }
    if(head1 == NULL)
        tail->link = head2;
    else
        tail->link = head1;
    head1 = ptr;
    head2 = NULL;
}

void insertInOrder(node*& head, int data)
{
    node* tmp = createNewNode(data);
    if (!head || head->data > data)
    {
        tmp->link = head;
        head = tmp;
    }
    else
    {
        node* ptr = head;
        while(ptr->link && ptr->link->data < data)
            ptr = ptr->link;

        tmp->link = ptr->link;
        ptr->link = tmp;
    }
}

int main()
{
    node* head = NULL;
    inputNode(head);
    reverseListRecursion(head);
//    node* tmp = head;
//    while(tmp)
//    {
//        printf("%d ", tmp->data);
//        tmp = tmp->link;
//    }

    return 0;
}

