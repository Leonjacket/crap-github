#include <iostream>

using namespace std;

struct node
{
    node* prev;
    int data;
    node* next;
};

node* addToEmpty(node* head, int data)
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp->prev = NULL;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

node* addAtBeg(node* head, int data)
{
    node*tmp = (node*)malloc(sizeof(node));
    tmp->next = head;
    tmp->data = data;
    tmp->prev = NULL;
    if (head)
        head->prev = tmp;
    return tmp;
}

node* addAtEnd(node* head, int data)
{
    node* ptr = head;
    while(ptr->next)
        ptr = ptr->next;
    node* tmp = new node;
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = ptr;
    ptr->next = tmp;
    return head;
}

node* addAFterPos(node* head, int data, int pos)
{
    node* tmp = head;
    node* newNode = addToEmpty(newNode, data);
    while (pos != 1)
    {
        tmp = tmp->next;
        pos--;
    }

    if(tmp->next == NULL)
    {
        tmp->next = newNode;
        newNode->prev = tmp;
    }
    else
    {
        node* tmp2 = tmp->next;
        tmp->next = newNode;
        tmp2->prev = newNode;
        newNode->prev = tmp;
        newNode->next = tmp2;
    }
    return head;
}

node* addBeforePos(node* head,int data, int pos)
{
    node* newNode = addToEmpty(newNode, data);
    node* tmp = head;
    while(pos > 2)
    {
        tmp = tmp->next;
        pos--;
    }
    if (pos == 1)
        head = addAtBeg(head,data);
    else
    {
        node* tmp2 = tmp->next;
        tmp->next = newNode;
        tmp2->prev = newNode;
        newNode->next = tmp2;
        newNode->prev = tmp;
    }
    return head;
}

node* createList(node* head)
{
    int n, data;
    cout << "Enter the number of nodes: ";
    cin >> n;
    if (n == 0) return head;
    cout << "Enter the element for the node 1: ";
    cin >> data;
    head = addToEmpty(head,data);
    for(int i = 2; i<=n; i++)
    {
        printf("Enter the element for the node %d: ",i);
        cin >> data;
        head = addAtEnd(head,data);
    }
    return head;
}

node* delFirst(node* head)
{
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

node* delLast(node* head)
{
    node* tmp1 = head;
    while (tmp1->next)
        tmp1 = tmp1->next;
    node* tmp2 = tmp1->prev;
    tmp2->next = NULL;
    free(tmp1);
    return head;
}

node* delPos(node* head, int pos)
{
    if(pos == 1)
    {
        head = delFirst(head);
        return head;
    }
    node* tmp = head;
    while(pos > 1)
    {
        tmp = tmp->next;
        pos--;
    }
    if (tmp->next == NULL)
        head = delLast(head);
    else
    {
        node* tmp2 = tmp->prev;
        tmp2->next = tmp->next;
        tmp->next->prev = tmp2;
        free(tmp);
        tmp = NULL;
    }
    return head;
}

node* reverseNode(node* head)
{
    node* ptr1 = head;
    node* ptr2 = head->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}

void printNode(node* head)
{
    node* ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

void insertAfterDatak(node*& head, int data, int k)
{
    if(!head) return;

    node* tmp = head;
    while ((tmp->next) && (tmp->data != k))
        tmp = tmp->next;

    if(tmp-> data != k)
        return;
    else if (tmp->next == NULL)
        head = addAtEnd(head,data);
    else if (tmp->data == k)
    {
        node* tmp2 = tmp->next;
        node* new_node = new node;
        new_node->data = data;
        new_node->next = tmp2;
        new_node->prev = tmp;
        tmp->next = new_node;
        tmp2->prev = new_node;

    }

}

int main()
{
    node* head = NULL;
    head = createList(head);
    insertAfterDatak(head, 100,3);
    node* ptr = head;
    printNode(head);
    return 0;
}
