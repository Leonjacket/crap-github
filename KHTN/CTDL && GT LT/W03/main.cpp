#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

void heapRebuild(int start, int a[], int n)
{
    int left = start * 2 + 1;
    if(left >= n)
        return;
    int right = start * 2 + 2;
    int larger = left;
    if(right < n)
        if(a[left] < a[right])
            larger = right;
    if(a[larger] > a[start])
    {
        swap(a[larger],a[start]);
        heapRebuild(larger,a,n);
    }
}

void heapSort(int a[], int n)
{
    for(int i = (n-1)/2; i >= 0; i--)
        heapRebuild(i,a,n);
    swap(a[0],a[n-1]);
    int heapSize = n - 1;
    while(heapSize > 1)
    {
        heapRebuild(0,a,heapSize);
        heapSize--;
        swap(a[0],a[heapSize]);
    }
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

void merge(int a[], int f, int m, int l)
{
    int f1 = f, l1 = m, f2 = m + 1, l2 = l, index = f1;
    int* tmp = new int[l-f + 1];
    while((f1<=l1) && (f2<=l2))
        if(a[f1] <= a[f2])
            tmp[index++] = a[f1++];
        else tmp[index++] = a[f2++];

    while(f1 <= l1)
        tmp[index++] = a[f1++];

    while(f2 <= l2)
        tmp[index++] = a[f2++];

    for(int i = f; i <= l; i++)
        a[i] = tmp[i];
    delete []tmp;
}

void mergeSort(int a[], int f, int l)
{
    if(f < l)
    {
        int m = (f + l)/2;
        mergeSort(a,f,m);
        mergeSort(a,m+1,l);
        merge(a,f,m,l);
    }
}

void quickSortV1(int a[], int f, int l)
{
    int pivot = (f+l)/2;
    int i = f, j = l;
    do
    {
        while(a[i] < a[pivot]) i++;
        while(a[j] > a[pivot]) j--;
        if(i <= j)
        {
            swap(a[i],a[j]);
            i++;j--;
        }
    } while (i <= j);
    if(f < j) quickSortV1(a,f,j);
    if(i < l) quickSortV1(a,i,l);
}

int sortFML(int a[], int f, int l)
{
    int m = f + (l-f)/2;
    if(a[m] < a[f])
        swap(a[m],a[f]);
    if(a[m] > a[l])
        swap(a[m],a[l]);
    if(a[m] < a[f])
        swap(a[m],a[f]);
    return m;
}

int partition(int a[], int f, int l)
{
    int pivotIndex = sortFML(a,f,l);
    swap(a[pivotIndex],a[l-1]);
    pivotIndex = l - 1;
    int pivot = a[pivotIndex];
    int indexL = f + 1, indexR = l - 2;
    bool done = false;
    while(!done)
    {
        while(a[indexL] < pivot)
            indexL++;
        while(a[indexR] > pivot)
            indexR--;
        if(indexL < indexR)
        {
            swap(a[indexR],a[indexL]);
            indexL++;indexR--;
        }
        else done = true;
    }
    swap(a[indexL],a[pivotIndex]);
    pivotIndex = indexL;
    return pivotIndex;
}

void quickSortV2(int a[], int f, int l)
{
    if(f < l)
    {
        int pivotIndex = partition(a,f,l);
        quickSortV2(a,f,pivotIndex - 1);
        quickSortV2(a,pivotIndex + 1, l);
    }   
}

int main()
{
    int* a = createArray(5);
    printArray(a,5);
    quickSortV2(a,0,4);
    printArray(a,5);
}