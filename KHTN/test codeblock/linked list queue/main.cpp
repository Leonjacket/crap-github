#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Queue
{
    Node* head;
    Node* tail;
    int capacity;
};

Node* createNode(int data)
{
    Node* tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void init(Queue& s, int capacity)
{
    s.head = NULL;
    s.tail = NULL;
    s.capacity = capacity;
}

bool isEmpty(Queue& s)
{
    if(!s.head && !s.tail)
        return 1;
    return 0;
}

bool enqueue(Queue& s, int x)
{
    if(isEmpty(s))
    {
        s.head = createNode(x);
        s.tail = s.head;
        cout << "Input successfully\n";
        return 1;
    }
    Node* tmp = s.head;
    int k = 0;
    while(tmp)
    {
        tmp = tmp->next;
        k++;
    }
    if(k == s.capacity)
    {
        cout << "Queue is full\n";
        return 0;
    }

    s.tail->next = createNode(x);
    s.tail = s.tail->next;
    cout << "Input successfully\n";
    return 1;
}

bool dequeue(Queue& s, int& value)
{
    if(isEmpty(s))
    {
        cout << "queue is already empty\n";
        return 0;
    }
    value = s.head->data;
    Node* tmp = s.head;
    if(s.head == s.tail)
    {
        s.head = NULL;
        s.tail = NULL;
    }
    else s.head = s.head->next;
    delete tmp;
    return 1;
}

void empty(Queue& s)
{
    s.tail = NULL;
    while(s.head)
    {
        Node* tmp = s.head;
        s.head = s.head->next;
        delete tmp;
    }
}

void printQueue(Queue s)
{
    if(isEmpty(s))
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue's value:\n";
    while(s.head)
    {
        printf("%d ",s.head->data);
        s.head = s.head->next;
    }
}

int size(Queue s)
{
    int k = 0;
    while(s.head)
    {
        k++;
        s.head = s.head->next;
    }
    return k;
}

int main()
{
    Queue s;
    int n = 0;
    while(n != 1)
    {
        printf("1. Create an empty queue\n2. Exit\n\n");
        cin >> n;
        if (n == 2)
            return 0;
        if (n != 1)
            cout << "queue has not been created yet. Input again\n\n";
    }
    cout << "Input capacity: ";
    int capacity;
    cin >> capacity;
    init(s,capacity);
    cout << "\n\n";

    while(n != 7)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Check if Queue is empty\n4. Empty Queue\n5. Print Queue's size\n6. Print Queue's data\n7. Exit\n\n");
        cin >> n;
        switch(n)
        {
        case 1:
            {
            int x;
            cout << "Input value: ";
            cin >> x;
            bool checkEnqueue = enqueue(s,x);
            break;
            }
        case 2:
            {
            int value;
            bool checkDequeue = dequeue(s,value);
            if (checkDequeue)
                printf("Dequeue's value is: %d", value);
            break;
            }
        case 3:
            {
            bool check = isEmpty(s);
            if (check)
                printf("Queue is empty\n");
            else printf("Queue is not empty\n");
            break;
            }
        case 4:
            {
            empty(s);
            break;
            }

        case 5:
            {
            int sizeQueue = size(s);
            printf("Queue size is: %d\n", sizeQueue);
            break;
            }

        case 6:
            printQueue(s);

        case 7:
            break;
        }
        cout << "\n------\n";
    }
    return 0;
}
