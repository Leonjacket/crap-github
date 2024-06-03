#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *head;
    int capacity;
};

Node* createNode(int data)
{
    Node* tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

bool isEmpty(Stack s)
{
    if(!s.head)
        return 1;
    return 0;
}

void init(Stack& s, int capacity)
{
    s.head = NULL;
    s.capacity = capacity;
}

bool push(Stack& s, int x)
{
    int k = 0;
    Node *ptr = s.head;
    while(ptr)
    {
        ptr = ptr->next;
        k++;
    }
    if (k == s.capacity)
    {
        cout << "Overflow";
        return 0;
    }
    Node* tmp = createNode(x);
    tmp->next = s.head;
    s.head = tmp;
    return 1;
}

bool pop(Stack& s, int& value)
{
    if (isEmpty(s))
    {
        cout << "Underflow";
        return 0;
    }
    value = s.head->data;
    Node* tmp = s.head;
    s.head = s.head->next;
    delete tmp;
    return 1;
}

void empty(Stack& s)
{
    if(isEmpty(s))
    {
        cout << "Is already empty\n";
        return;
    }
    while(s.head)
    {
        Node* tmp = s.head->next;
        delete s.head;
        s.head = tmp;
    }
}

int size(Stack s)
{
    int count = 0;
    while(s.head)
    {
        count++;
        s.head = s.head->next;
    }
    return count;
}

int main()
{
    Stack s;
    int n;
    while(n != 1)
    {
        printf("1. Create an empty stack\n2. Exit\n\n");
        cin >> n;
        if (n == 2)
            return 0;
        if (n != 1)
            cout << "Stack has not been created yet. Input again";
    }
    cout << "Input capacity: ";
    int capacity;
    cin >> capacity;
    init(s,capacity);
    cout << "\n";

    while(n != 7)
    {
        printf("1. Push\n2. Pop\n3. Check if stack is empty\n4. Empty stack\n5. Print stack's size\n6. Print stack's data\n7. Exit\n\n");
        cin >> n;
        switch(n)
        {
        case 1:
            {
            int x;
            cout << "Input value: ";
            cin >> x;
            bool checkPush = push(s,x);
            break;
            }
        case 2:
            {
            int value;
            bool checkPop = pop(s,value);
            printf("Pop's value is: %d", value);
            break;
            }
        case 3:
            {
            bool check = isEmpty(s);
            if (check)
                printf("Stack is empty\n");
            else printf("Stack is not empty\n");
            break;
            }
        case 4:
            {
            empty(s);
            break;
            }

        case 5:
            {
            int sizeStack = size(s);
            printf("Stack size is: %d\n", sizeStack);
            break;
            }

        case 6:
            {
            Node* tmp = s.head;
            cout << "Stack's value:\n";
            while(tmp)
            {
                printf("%d ", tmp->data);
                tmp = tmp->next;
            }
            break;
            }

        case 7:
            break;
        }
        cout << "\n------\n";
    }
    return 0;
}
