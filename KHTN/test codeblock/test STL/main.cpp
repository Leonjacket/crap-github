#include<iostream>

using namespace std;

void printList(int* num, int n)
{
    cout << "{ ";
    for(int i = 0; i < n; i++)
        printf("%d ", num[i]);
    cout << "}\n";
}

void backtrack(int* a, int n, int* num, int index, bool* notUsed)
{
    if(index == n)
    {
        printList(num,n);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(notUsed[i])
        {
            notUsed[i] = false;
            num[index] = a[i];
            backtrack(a,n,num,index + 1,notUsed);
            notUsed[i] = true;
        }
    }
}

void permutation(int n)
{
    int *a = new int[n], *num = new int[n];
    bool* notUsed = new bool[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        notUsed[i] = true;
    }
    backtrack(a,n,num,0,notUsed);
    delete[] a;
    delete[] notUsed;
    delete[] num;
}

int main()
{
    cout << "Nhap n: ";
    int n; cin >> n;
    permutation(n);
}
