#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int LinearSearch(int* a, int n, int key)
{
    for(int i = 0; i < n; i++)
        if(a[i] == key)
            return i;
    return -1;
}

int SentinelLinearSearch(int* a, int n, int key) // gán cho giá trị cuối mảng = key
{
    int last = a[n-1];
    a[n-1] = key;
    int i = 0;
    while(a[i] != key)
        i++;
    a[n-1] = last;
    if((i < n - 1) || (key == a[n-1]))
        return i;
    return -1;
}

int BinarySearch(int* a, int n, int key)
{
    int l = 0, r = n-1, m;
    while(l <= r)
    {
        m = (l+r)/2;
        if(a[m] == key)
            return m;
        else if(key > a[m])
            l = m + 1;
        else r = m-1;
    }
    return -1;
}

int RecursiveBinarySearch(int* a, int left, int right, int key)
{
    if (left > right)
        return -1;
    int m = (left + right) / 2;
    if(a[m] == key)
        return m;
    else if(key > a[m])
        return RecursiveBinarySearch(a, m + 1, right, key);
    else return RecursiveBinarySearch(a,left, m - 1, key);
}

int* createArray(int n)
{
    int* a = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        a[i] = rand() % 10;
    return a;
}

void printArray(int* a, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ",a[i]);
    cout << "\n";
}

int* selectionSort(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
            if(a[min] > a[j])
                min = j;
        swap(a[min],a[i]);
    }
    return a;
}

int* insertionSort(int *a, int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    return a;
}

int* binaryInsertionSort(int* a, int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = a[i];
        int pos = 0, last = i - 1;
        while(pos <= last) // tìm vị trí pos sao cho key > a[pos] để sắp xếp từ (i - 1) -> pos (trái sang phải)
        {
            int m = (pos + last) / 2;
            if(key > a[m])
                pos = m + 1;
            else last = m - 1;
        }
        for(int j = i - 1; j >= pos; j--)
            a[j + 1] = a[j];
        a[pos] = key;
    }
    return a;
}

int* bubbleSort(int* a, int n)
{
    for(int i = 1; i < n; i++)
        for(int j = 0; j < n - i; j++)
            if(a[j] > a[j+1])
                swap(a[j],a[j+1]);
    return a;
}

int* flagBubbleSort(int* a, int n)
{
    bool unsorted = true;
    int pass = 0;
    while(unsorted)
    {
        pass++;
        unsorted = false;
        for(int i = 0; i < n - pass; i++)
            if(a[i] > a[i+1])
            {
                swap(a[i],a[i+1]);
                unsorted = true;
            }
    }
    return a;
}

int* shakerSort(int* a, int n)
{
    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for(int i = right; i >= left; i--)
            if(a[i-1] > a[i])
            {
                swap(a[i-1],a[i]);
                k = i;
            }
        left = k + 1;
        for(int i = left; i <= right; i++)
            if(a[i-1] > a[i])
            {
                swap(a[i-1],a[i]);
                k = i;
            }
        right = k - 1;
    } while (left <= right);
    return a;
}

int* interchangeSort(int* a, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] > a[j])
                swap(a[i],a[j]);
    return a;
}

int main()
{
    int* a = createArray(5);
    printArray(a,5);
    int* b = interchangeSort(a,5);
    printArray(b,5);
    return 0;
}