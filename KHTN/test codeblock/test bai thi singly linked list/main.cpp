#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* createNode(int data)
{
    node* tmp = new node;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void createList(node*& head)
{
    int n;
    cin >> n;
    if(n==0) return;
    if(!head)
        head = createNode(n);
    node* tmp = head;
    while(cin >> n && n != 0)
    {
        tmp->next = createNode(n);
        tmp = tmp->next;
    }
}

void printList(node* head)
{
    while(head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}

node* findSmallest(node* head)
{
    if(!head)
        return NULL;
    node* ptr = head;
    node* tmp = head;
    while(ptr)
    {
        if(tmp->data > ptr->data)
            tmp = ptr;
        ptr = ptr->next;
    }
    return tmp;
}

void swapSmallest2First(node*& head)
{
    if(!head) return;
    node* tmp = findSmallest(head);
    int k = head->data;
    head->data = tmp->data;
    tmp->data = k;
}

node* greaterNode(node* ptr)
{
    node* tmp = ptr;
    while(ptr)
    {
        if(tmp->data < ptr->data)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void printGreaterNode(node* head)
{
    while(head)
    {
        node* tmp = greaterNode(head);
        if(!tmp)
            cout << "null ";
        else
            printf("%d ", tmp->data);
        head = head->next;
    }
}

node* findOdd(node* head)
{
    while(head)
    {
        if(head->data % 2 == 1)
            return head;
        head = head->next;
    }
    return NULL;
}

void oddLeftEvenRight(node*& head)
{
    if(!head && !head->next)
        return;
    node *ptr = head;
    while(ptr)
    {
        if(ptr->data % 2 == 0)
        {
            node* tmp = findOdd(ptr);
            if(!tmp)
                return;
            else
            {
                int k = ptr->data;
                ptr->data = tmp->data;
                tmp->data = k;
            }
        }
        ptr = ptr->next;
    }
}

bool isPalindrome(node* head)
{
    node* slow = head, *fast = head,
    *prev = NULL, *next = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        next = next->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    if(fast)
        slow = slow->next;
    fast = prev;
    while(slow)
    {
        if(fast->data != slow->data)
            return 0;
        fast = fast->next;
        slow = slow->next;
    }
    return 1;
}

int main()
{
    node* head = NULL;
    createList(head);
    cout << isPalindrome(head);
//    printList(head);
    return 0;
}
