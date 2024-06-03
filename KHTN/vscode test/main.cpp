#include <iostream>
#include <ctime>

using namespace std;

int*** createArray(int m, int n, int p)
{
    srand(time(0));
    int*** a = new int**[m];
    for(int i = 0; i < m; i++)
    {
        a[i] = new int*[n];
        for(int j = 0; j < n; j++)
        {
            a[i][j] = new int[p];
            for(int k = 0; k < p; k++)
                a[i][j][k] = rand() % 10;
        }
    }
    return a;
}
//{ {{0, 3, 0}, {7, 7, 8}, {3, 0, 5}}, {{}}}
void printArray(int*** a, int m, int n, int p)
{
    cout << "{ ";
    for(int i = 0; i < m; i++)
    {
        cout << "{";
        for(int j = 0; j < n; j++)
        {
            cout << "{";
            for(int k = 0; k < p; k++)
            {
                cout << a[i][j][k];
                if(k < p - 1)
                    cout << ", ";
            }
            cout << "}";
            if(j < n - 1)
                cout << ", ";
        }
        cout << "} ";
        if(i < m - 1)
            cout << "| ";
    }
    cout << " }";
}

void print(int*** a, int m, int n, int p)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < p; k++)
                printf("%d ",a[i][j][k]);
            cout << "\n";
        }
        cout << "\n";
    }
}

int** find_largest_UxV(int*** a, int m, int n, int p, int u, int v)
{
    if(u > n || v > p)
    {
        cout << "Error!";
        return NULL;
    }
    int start_x = 0, start_y = 0, start_z = 0, value = 0;
    int** tmp = new int*[u];
    for(int i = 0; i < u; i++)
        tmp[i] = new int[v];
    int max = INT_MIN;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j <= n - u; j++)
        {
            for(int k = 0; k <= p - v; k++)
            {
                value = 0;
                for(int x = 0; x < u; x++)
                    for(int y = 0; y < v; y++)
                        value += a[i][j+x][k+y];
                if(max < value)
                {
                    max = value;
                    start_x = i;
                    start_y = j;
                    start_z = k;
                }
            }
        }
    }
    
    for(int i = 0; i < u; i++)
        for(int j = 0; j < v; j++)
            tmp[i][j] = a[start_x][start_y+i][start_z+j];
    return tmp;
}

int** find_smallest_UxV(int*** a, int m, int n, int p, int u, int v)
{
    int start_x = 0, start_y = 0, start_z = 0, value = 0, min = INT_MAX;
    int** tmp = new int*[u];
    for(int i = 0; i < u; i++)
        tmp[i] = new int[v];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j <= n - u; j++)
        {
            for(int k = 0; k <= p - v; k++)
            {
                for(int x = 0; x < u; x++)
                    for(int y = 0; y < v; y++)
                        value += a[i][j+x][k+y];
                if(min > value)
                {
                    min = value;
                    start_x = i;
                    start_y = j;
                    start_z = k;
                }
                value = 0;
            }
        }
    }

    for(int i = 0; i < u; i++)
        for(int j = 0; j < v; j++)
            tmp[i][j] = a[start_x][start_y+i][start_z+j];
    return tmp;
}

void print2D(int** a, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ",a[i][j]);
        cout << "\n";
    }
}

int main()
{
    int*** a = createArray(3,3,3);
    print(a,3,3,3);
    cout << "\n";
    int** b = find_smallest_UxV(a,3,3,3,2,3);
    print2D(b,2,3);
    return 0;
}