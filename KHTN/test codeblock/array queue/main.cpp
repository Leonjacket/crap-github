#include <iostream>

using namespace std;

struct Queue
{
    int *data;
    int in;
    int out;
    int capacity;
};

void init(Queue& s, int capacity)
{
    s.data = new int[capacity];
    s.capacity = capacity;
    s.in = -1;
    s.out = -1;
}

bool isEmpty(Queue s)
{
    if(s.in == -1)
        return 1;
    return 0;
}

bool enqueue(Queue& s, int x)
{
    if((s.in + 1) % s.capacity == s.out)
    {
        cout << "Queue is full\n";
        return 0;
    }
    if(isEmpty(s))
    {
        s.in++;
        s.out++;
        s.data[s.in] = x;
        cout << "Input successfully\n";
        return 1;
    }
    s.in = (s.in + 1) % s.capacity;
    s.data[s.in] = x;
    cout << "Input successfully\n";
    return 1;
}

bool dequeue(Queue& s, int& value)
{
    if (isEmpty(s))
    {
        cout << "queue is already empty\n";
        return 0;
    }
    value = s.data[s.out];
    if(s.out == s.in)
    {
        s.out = -1;
        s.in = -1;
    }
    else s.out = (s.out + 1) % s.capacity;
    return 1;
}

void empty(Queue& s)
{
    s.in = -1;
    s.out = -1;
}

int size(Queue s)
{
    if(isEmpty(s))
        return 0;
    return abs(s.in - s.out) + 1;
}

void printQueue(Queue s)
{
    if(isEmpty(s))
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue's value:\n";
    if(s.in == s.out)
    {
        cout << s.data[s.out];
        return;
    }

    while(s.in != s.out)
    {
        printf("%d ", s.data[s.out]);
        s.out = (s.out + 1) % s.capacity;
    }
    printf("%d\n", s.data[s.out]);
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
