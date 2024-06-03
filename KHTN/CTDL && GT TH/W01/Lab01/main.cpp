#include "header01.h"

int main()
{
    list l;
    node* tmp = createNode(1);
    l.head = tmp;
    node* ptr = l.head;
    for(int i = 2; i < 6; i++)
    {
        tmp = createNode(i);
        ptr->next = tmp;
        ptr = ptr->next;
    }
    l.tail = tmp;
    list c = reverseList(l);
    printList(c);
    return 0;
}