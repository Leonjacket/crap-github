#include <iostream>

using namespace std;

struct Stack
{
    int *data;
    int top;
    int capacity;
};

bool isEmpty(Stack s)
{
    if(s.top < 0)
        return 1;
    return 0;
}

void init(Stack& s, int capacity)
{
    s.capacity = capacity;
    s.data = new int[capacity];
    s.top = -1;
}

bool push(Stack& s, int x)
{
    if (s.top == s.capacity - 1)
    {
        printf("Overflow\n");
        return 0;
    }
    s.top++;
    s.data[s.top] = x;
    return 1;
}

bool pop(Stack& s, int& value)
{
    if (isEmpty(s))
    {
        printf("Underflow\n");
        return 0;
    }
    value = s.data[s.top];
    s.top--;
    printf("%d \n",s.top);
    return 1;
}

void empty(Stack& s)
{
    if(isEmpty(s))
    {
        cout << "Stack is already empty\n";
        return;
    }
    s.top = -1;
}

int size(Stack s)
{
    return s.top+1;
}

void printStack(Stack s)
{
    cout << "Stack's value:\n";
    while(s.top >= 0)
    {
        printf("%d ", s.data[s.top]);
        s.top--;
    }
}

int main()
{
    Stack s;
    int n = 0;
    while (n != 1)
    {
        cout << "1. Create an empty Stack\n2. Exit\n\n";
        cin >> n;
        if (n == 2)
            return 0;
        if (n != 1)
            cout << "Stack has not been created yet. Input again\n\n";
    }
    int capacity;
    cout << "Input capacity: ";
    cin >> capacity;
    init(s, capacity);

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
            if (checkPop)
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
            printStack(s);

        case 7:
            break;
        }
        cout << "\n------\n";
    }
    return 0;
}
