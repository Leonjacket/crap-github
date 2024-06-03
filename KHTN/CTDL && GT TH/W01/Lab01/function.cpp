#include "header01.h"

//1.Pointer
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* sum(int* a, int* b)
{
    int* tmp;
    *tmp = *a+*b;
    return tmp;
}

void inputArray(int* &a, int &n)
{
    for(int i = 0; i < n; i++)
    {
        printf("a[%d] = ",i);
        cin >> a[i];
    }
}

void printArray(int* a, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ",a[i]);
}

int* findMax(int* arr, int n)
{
    int* max = arr;
    for(int i = 1; i < n; i++)
    {
        if(*max < arr[i])
            max = &arr[i];
    }
    return max;
}

int* findLongestAscendingSubarray(int* a, int n, int &length)
{
    if(n==0)
    {
        length = 0;
        return NULL;
    }

    int max = 1;
    int cur = 1;
    int start = 0;
    int end = 0;
    
    for(int i = 1; i < n; i++)
    {
        if(a[i]>a[i-1])
        {
            cur++;
            if(cur > max)
            {
                max = cur;
                start = i - max + 1;
                end = i;
            }
        }
        else cur = 1;
    }
    length = max;
    int* result = new int[max];
    for(int i = start; i <= end; i++)
        result[i - start] = a[i];
    return result;
}

void swapArrays(int* &a, int* &b, int &na, int &nb)
{
    int* tmp = a;
    a = b;
    b = a;

    int tmpSize = na;
    na = nb;
    nb = tmpSize;
}

int* concatenate2Arrays(int* a, int* b, int na, int nb, int &nc)
{
    nc = na + nb;
    int* c = new int[nc];
    for(int i = 0; i < na; i++)
        c[i] = a[i];
    for(int i = 0; i < nb; i++)
        c[i + na] = b[i];
    return c;
}

int* merge2Arrays(int* a, int* b, int na, int nb, int &nc)
{
    nc = na + nb;
    int* c = new int[nc];
    int i = 0,j = 0, count = 0;
    while(i < na && j < nb)
    {
        if(a[i] < b[j])
            c[count++] = a[i++];
        else
            c[count++] = b[j++];
    }
    while(i < na)
        c[count++] = a[i++];
    while(j < nb)
        c[count++] = b[j++];
    return c;
}

void generateMatrix1(int** &a, int &length, int &width)
{
    cout << "Enter the number of rows: ";
    cin >> length;
    cout << "Enter the number of columns: ";
    cin >> width;

    a = new int*[length];
    for(int i = 0; i < length; i++)
        a[i] = new int[width];
    srand(time(NULL));
    for(int i = 0; i < length; i++)
        for(int j = 0; j < width; j++)
            a[i][j] = rand() % 50;
}

void print2D(int** a, int length, int width)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
            printf("%d ",a[i][j]);
        cout << "\n";
    }
}

void delete2D(int** a, int row)
{
    for (int i = 0; i < row; ++i) 
        delete[] a[i];
    delete[] a;
}

int** generateMatrix2(int* a, int* b, int na, int nb, int &crow, int &ccol)
{
    if(na == 0 || nb == 0)
    {
        crow = 0;
        ccol = 0;
        return NULL;
    }
    crow = na;
    ccol = nb;
    int** c = new int*[crow];
    for(int i = 0; i < crow; i++)
        c[i] = new int[ccol];

    for(int i = 0; i < crow; i++)
        for(int j = 0; j < ccol; j++)
            c[i][j] = a[i] * b[j];
    return c;
}

void swapRows(int** a, int length, int width, int ir1, int ir2)
{
    if(ir1 >= 0 && ir1 < length && ir2 >= 0 && ir2 < length)
    {
        int* tmp = a[ir1];
        a[ir1] = a[ir2];
        a[ir2] = tmp;
    }
    else cout << "Error!";
}

void swapColumns(int** a, int length, int width, int ic1, int ic2)
{
    int tmp;
    if(ic1 > 0 && ic1 < length && ic2 > 0 && ic2 < length)
    {
        for(int i = 0; i < length; i++)
        {
            tmp = a[i][ic1];
            a[i][ic1] = a[i][ic2];
            a[i][ic2] = tmp;
        }
    } else cout << "Error!\n";
}

int** transposeMatrix(int** a, int length, int width)
{
    int **c = new int*[width];
    for(int i = 0; i < width; i++)
        c[i] = new int[length];
    for(int i = 0; i < width; i++)
        for(int j = 0; j < length; j++)
            c[i][j] = a[j][i];
    return c;
}

int** concatenate2MatricesH(int** a, int** b, int length, int width, int &lres, int &wres)
{
    lres = length;
    wres = width * 2;
    int** result = new int*[length];
    for(int i = 0; i < length; i++)
    {
        result[i] = new int[wres];
        for(int j = 0; j < width; j++)
        {
            result[i][j] = a[i][j];
            result[i][j + width] = b[i][j];
        }
    }
    return result;
}

int** concatenate2MatricesV(int** a, int** b, int length, int width, int &lres, int &wres)
{
    lres = length * 2;
    wres = width;
    int** result = new int*[lres];
    for(int i = 0; i < length; i++)
    {
        result[i] = new int[width];
        result[i+length] = new int[width];
        for(int j = 0; j < width; j++)
        {
            result[i][j] = a[i][j];
            result[i + length][j] = b[i][j];
        }
    }
    return result;
}

bool multiple2Matrices(int**& res, int** a, int **b, int& lengthr, int& widthr, int lengtha, int widtha, int lengthb, int widthb)
{
    if(widtha != lengthb)
        return false;
    lengthr = lengtha;
    widthr = widthb;
    int tmp = 0;
    res = new int*[lengthr];
    for(int i = 0; i < lengthr; i++)
    {
        res[i] = new int[widthr];
        for(int j = 0; j < widthr; j++)
            res[i][j] = 0;
    }
    for(int i = 0; i < lengthr; i++)
        for(int j = 0; j < widthr; j++)
            for(int k = 0; k < widtha; k++)
                res[i][j] += a[i][k] * b[k][j];
    return true;
}

int** findSubmatrix(int** a, int length, int width, int &lres, int &wres)
{
    int max = INT_MIN;
    int startRow = 0; int startCol = 0;
    for(int i = 0; i <= length - lres; i++)
    {
        for(int j = 0; j <= width - wres; j++)
        {
            int cur = 0;
            for(int k = 0; k < lres; k++)
                for(int l = 0; l < wres; l++)
                    cur += a[i + k][j + l];
            if(cur > max)
            {
                max = cur;
                startRow = i;
                startCol = j;
            }
        }
    }
    int** result = new int*[lres];
    for(int i = 0; i < lres; i++)
    {
        result[i] = new int[wres];
        for(int j = 0; j < wres; j++)
            result[i][j] = a[startRow + i][startCol + j];
    }
    return result;
}

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

//2.Recursion
int recursionSum(int sum, int n)
{
    if(n == 0)
        return sum;
    return recursionSum(sum + n, n - 1);
}

int recursionFactorial(int result, int n)
{
    if(n == 0)
        return result;
    return recursionFactorial(result * n, n - 1);
}

double recursionExponential(double x, int n)
{
    if(n == 0)
        return 1;
    else if(n < 0)
        return 1 / recursionExponential(x, -n);
    
    double half = recursionExponential(x, n/2);

    if(n % 2 == 0)
        return half * half;
    else return x * half * half;
}

int recursionCountDigits(int n)
{
    if(n == 0)
        return 0;
    return 1 + recursionCountDigits(n/10);
}

bool recursionAllDigitsEven(int n)
{
    if (n == 0)
        return true;
    if(n % 2 == 0)
        return recursionAllDigitsEven(n/10);
    return false;
}

int recursionCountDivisor(int a, int b, int divisor)
{
    if(divisor == 0)
        return 0;
    if(a % divisor == 0 && b % divisor == 0)
        return 1 + recursionCountDivisor(a,b,divisor - 1);
    return recursionCountDivisor(a,b,divisor - 1);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, b % a);
}

int lcm(int a, int b)
{
    if (b == 0)
        return a;
    return (a*b)/gcd(a,b);
}

int recursionReverseValue(int result, int num)
{
    if(num == 0)
        return result;
    int lastDigit = num % 10;
    result = result * 10 + lastDigit;
    return recursionReverseValue(result, num/10);
}

int recursionFibonacci(int n)
{
    if(n <= 1)
        return n;
    return recursionFibonacci(n-1) + recursionFibonacci(n-2);
}

void stringPermutation(string& str, int l, int r)
{
    if(l == r)
    {
        cout << str << "\n";
        return;
    }
    
    for(int i = l; i <= r; i++)
    {
        swap(str[l],str[i]);
        stringPermutation(str,l+1,r);
        swap(str[l],str[i]);
    }
}

//3. File handling
Examinee readExaminee(string line_info)
{
    Examinee info;
    ifstream in(line_info);
    
    string ignore;
    getline(in,ignore);
    string tmp;
    getline(in,info.id,',');//1
    getline(in,tmp,',');//2
    getline(in,tmp,',');//3
    info.maths = tmp.empty() ? 0.0f : stof(tmp);
    getline(in,tmp,',');//4
    info.literature = tmp.empty() ? 0.0f : stof(tmp);
    getline(in,tmp,',');//5
    info.physics = tmp.empty() ? 0.0f : stof(tmp);
    getline(in,tmp,',');//6
    info.chemistry = tmp.empty() ? 0.0f : stof(tmp);
    getline(in,tmp,',');//7
    info.biology = tmp.empty() ? 0.0f : stof(tmp);
    getline(in,tmp,',');//8
    info.history = tmp.empty() ? 0.0f : stof(tmp);
    getline(in,tmp,',');//9
    info.geography = tmp.empty() ? 0.0f : stof(tmp);
    getline(in,tmp,',');//10
    info.civic_education = tmp.empty() ? 0.0f : stof(tmp);
    getline(in,tmp,',');//11
    getline(in,tmp,',');//12
    getline(in,tmp,',');//13
    info.foreign_language = tmp.empty() ? 0.0f : stof(tmp);
    getline(in,tmp);
    info.natural_science = info.physics + info.chemistry + info.biology;
    info.social_science = info.history + info.geography + info.civic_education;
    return info;
}

vector<Examinee> readExamineeList(string line_info)
{
    vector<Examinee> info;
    Examinee ex;
    ifstream in(line_info);
    
    string ignore;
    getline(in,ignore);
    string tmp;
    while(getline(in,ex.id,','))
    {
        getline(in,tmp,',');//2
        getline(in,tmp,',');//3
        ex.maths = tmp.empty() ? 0.0f : stof(tmp);
        getline(in,tmp,',');//4
        ex.literature = tmp.empty() ? 0.0f : stof(tmp);
        getline(in,tmp,',');//5
        ex.physics = tmp.empty() ? 0.0f : stof(tmp);
        getline(in,tmp,',');//6
        ex.chemistry = tmp.empty() ? 0.0f : stof(tmp);
        getline(in,tmp,',');//7
        ex.biology = tmp.empty() ? 0.0f : stof(tmp);
        getline(in,tmp,',');//8
        ex.history = tmp.empty() ? 0.0f : stof(tmp);
        getline(in,tmp,',');//9
        ex.geography = tmp.empty() ? 0.0f : stof(tmp);
        getline(in,tmp,',');//10
        ex.civic_education = tmp.empty() ? 0.0f : stof(tmp);
        getline(in,tmp,',');//11
        getline(in,tmp,',');//12
        getline(in,tmp,',');//13
        ex.foreign_language = tmp.empty() ? 0.0f : stof(tmp);
        getline(in,tmp);
        ex.natural_science = ex.physics + ex.chemistry + ex.biology;
        ex.social_science = ex.history + ex.geography + ex.civic_education;
        info.push_back(ex);
    }
    return info;
}

void writeScores(vector<Examinee> examinee_list, string out_file_name)
{
    ofstream out(out_file_name);
    out << left << setw(15) << "SBD" << setw(10) << "BB" << setw(10) << "KHTN" << "KHXH\n";
    for(int i = 0; i < examinee_list.size(); i++)
    {
        float BB = examinee_list[i].maths + examinee_list[i].literature + examinee_list[i].foreign_language;
        out << left << setw(15) << examinee_list[i].id << setw(10) << BB << setw(10) << examinee_list[i].natural_science << setw(10) << examinee_list[i].social_science << "\n"; 
    }
}

//4. Linked list
node* createNode(int data)
{
    node* tmp = new node;
    tmp->key = data;
    tmp->next = NULL;
    return tmp;
}

list createList(node* pNode)
{
    list l;
    if(pNode)
    {
        l.head = pNode;
        while(!pNode->next)
            pNode = pNode->next;
        l.tail = pNode;
    }
    else
    {
        l.head = NULL;
        l.tail = NULL;
    }
    return l;
}

void addHead(list &L, int data)
{
    if(!L.head)
        L.head = createNode(data);
    else
    {
        node* tmp = createNode(data);
        tmp->next = L.head;
        L.head = tmp;
    }
}

void addTail(list &L, int data)
{
    if(!L.tail)
        L.tail = createNode(data);
    else
    {
        node* tmp = createNode(data);
        L.tail->next = tmp;
        L.tail = tmp;
    }
}

void removeHead(list &L)
{
    if(!L.head->next)
    {
        delete L.head;
        L.head = NULL;
    }
    else
    {
        node* tmp = L.head->next;
        delete L.head;
        L.head = tmp;
    }
}

void removeTail(list &L)
{
    if(L.head == L.tail)
    {
        delete L.tail;
        L.head = L.tail = NULL;
        return;
    }
    node* tmp = L.head;
    while(tmp->next != L.tail)
        tmp = tmp->next;
    delete L.tail;
    L.tail = tmp;
}

void removeAll(list &L)
{
    while(L.head)
    {
        node* tmp = L.head;
        L.head = L.head->next;
        delete tmp;
    }
    L.head = L.tail = NULL;
}

void removeBefore(list& L, int val)
{
    node* tmp = L.head;
    if(tmp->next->key == val)
    {
        L.head = L.head->next;
        delete tmp;
        return;
    }
    while(tmp->next->next->key != val)
        tmp = tmp->next;
    node* ptr = tmp->next;
    tmp->next = ptr->next;
    delete ptr;
}

void removeAfter(list& L, int val)
{
    node* tmp = L.head;
    while(tmp->key != val)
        tmp = tmp->next;
    
    node* ptr = tmp->next;
    tmp->next = ptr->next;
    if(ptr == L.tail)
        L.tail = tmp;
    delete ptr;
}

void addPos(list &L, int data, int pos)
{
    node* tmp = createNode(data);
    if(pos == 1)
    {
        tmp->next = L.head;
        L.head = tmp;
        if(!L.tail)
            L.tail = tmp;
        return;
    }
    node* ptr = L.head;
    while(pos != 2)
    {
        ptr = ptr->next;
        pos--;
    }        
    tmp->next = ptr->next->next;
    ptr->next = tmp;
    if(tmp->next == NULL)
        L.tail = tmp;
}

void removePos(list &L, int pos)
{
    if(pos == 1)
    {
        node* tmp = L.head;
        L.head = L.head->next;
        delete tmp;
        return;
    }
    node* tmp = L.head;
    while(pos != 2)
    {
        tmp = tmp->next;
        pos--;
    }
    node* ptr = tmp->next;
    tmp->next = ptr->next;
    if(!ptr->next)
        L.tail = tmp;
    delete ptr;
}

void addBefore(list& L, int data, int val)
{
    node* tmp = createNode(data);
    if(!L.head)
    {
        cout << "Error!";
        return;
    }
    if(L.head->key == val)
    {
        tmp->next = L.head;
        L.head = tmp;
        return;
    }
    node* ptr = L.head;
    while(ptr->next->key != val && ptr->next)
        ptr = ptr->next;
    if(ptr->next)
    {
        tmp->next = ptr->next;
        ptr->next = tmp;
    }
    else cout << "Error!";
}

void addAfter(list& L, int data, int val)
{
    node* ptr = L.head;
    while(ptr->key != val && ptr)
        ptr = ptr->next;
    if(ptr)
    {
        node* tmp = createNode(data);
        tmp->next = ptr->next;
        ptr->next = tmp;
        if(ptr = L.tail)
            L.tail = tmp;
    }
}

void printList(list L)
{
    while(L.head)
    {
        printf("%d ", L.head->key);
        L.head = L.head->next;
    }
}

int countElements(list L)
{
    int count = 0;
    while(L.head)
    {
        count++;
        L.head = L.head->next;
    }
    return count;
}

list reverseList(list L)
{
    node* prev = NULL;
    node* cur = L.head;
    node* next = L.head;
    L.tail = L.head;
    while(cur)
    {
        next = next->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    L.head = prev;
    return L;
}

void removeDuplicate(list &L)
{
    vector<int> a;
    node* prev = L.head;
    node* cur = prev->next;
    a.push_back(prev->key);
    while(cur)
    {
        if(find(a.begin(),a.end(), cur->key) != a.end())
        {
            if(cur == L.tail)
                prev = L.tail;
            prev = cur->next;
            delete cur;
            cur = prev;
        }
        else a.push_back(cur->key);
        prev = cur;
        cur = cur->next;
    }
}

bool removeElement(list &L, int key)
{
    node* prev = L.head;
    if(!prev)
    {
        cout << "Error!";
        return 0;
    }
    bool remove = false;
    while(prev->key == key)
    {
        prev = prev->next;
        delete L.head;
        L.head = prev;
        remove = true;
    }
    if(!prev)
    {
        L.tail = NULL;
        return remove;
    }
        
    node* cur = prev->next;
    while(cur->next)
    {
        if(cur->key == key)
        {
            if(cur == L.tail)
                L.tail = NULL;  
            prev->next = cur->next;
            delete cur;
            cur = prev;
            remove = true;
        }
        prev = cur;
        cur = cur->next;
    }
    return remove;
}

//5. Doubly Linkedlist
dnode* createDnode(int data)
{
    dnode* tmp = new dnode;
    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->key = data;
    return tmp;
}

dList createDList(dnode* pNode)
{
    dList l;
    if(pNode)
    {
        l.head = pNode;
        while(pNode->next)
            pNode = pNode->next;
        l.tail = pNode;
    }
    else l.head = l.tail = NULL;
    return l;
}

void DaddHead(dList &L, int data)
{
    if(!L.head)
    {
        cout << "Error!";
        return;
    }
    dnode* tmp = createDnode(data);
    tmp->next = L.head;
    L.head->prev = tmp;
    L.head = tmp;
}

void DaddTail(dList &L, int data)
{
    if(!L.head)
    {
        cout << "Error!";
        return;
    }
    dnode* tmp = createDnode(data);
    tmp->prev = L.tail;
    L.tail->next = tmp;
    L.tail = tmp;
}

void DremoveHead(dList &L)
{
    if(!L.head)
    {
        cout << "Error!";
        return;
    }
    L.head = L.head->next;
    delete L.head->prev;
    L.head -> prev = NULL;
}

void DremoveDTail(dList &L)
{
    if(!L.head)
    {
        cout << "Error!";
        return;
    }
    L.tail = L.tail->prev;
    delete L.tail->next;
    L.tail->next = NULL;
}

void DremoveAll(dList &L)
{
    if(!L.head)
    {
        cout << "Error!";
        return;
    }
    while(L.head)
    {
        dnode* tmp = L.head->next;
        delete L.head;
        L.head = tmp;
    }
    L.tail = NULL;
}

void DremoveBefore(dList& L, int val)
{
    if(!L.head)
    {
        cout << "Error!";
        return;
    }
    dnode* ptr = L.head;
    if(ptr->next->key == val)
    {
        L.head = L.head->next;
        L.head->prev = NULL;
        delete ptr;
        return;
    }
    while(ptr->next && ptr->next->next)
    {
        if(ptr->next->next->key == val && ptr->next->next)
        {
            dnode* tmp = ptr->next;
            ptr->next = tmp->next;
            if(ptr == L.head)
            {
                L.head = tmp;
                L.head->prev = NULL;
            }
            if(tmp->next)
                tmp->next->prev = ptr;
            delete tmp;
            return;
        }
        ptr = ptr->next;
    }
}

void DremoveAfter(dList& L, int val)
{
    if(!L.head)
    {
        cout << "Error!";
        return;
    }
    dnode* ptr = L.head;
    while(ptr->next && ptr->next->key != val)
        ptr = ptr->next;
    dnode* tmp = ptr->next;
    ptr->next = tmp->next;
    if(tmp != L.tail)
        ptr->next->prev = ptr;
    else
        L.tail = ptr->next;
    delete tmp;
}

void DaddPos(dList &L, int data, int pos)
{
    if(pos < 1)
    {
        cout << "Error!";
        return;
    }
    dnode* tmp = createDnode(data);
    dnode* ptr = L.head;
    if(pos == 1)
    {
        tmp->next = ptr;
        if(L.head)
            ptr->prev = tmp;
        if(!L.tail)
            L.tail = tmp;
        L.head = tmp;
        return;
    }
    while(pos != 2 && ptr)
    {
        ptr = ptr->next;
        pos--;
    }
    if(!ptr)
    {
        cout << "Error!";
        return;
    }
    dnode* next = ptr->next;
    tmp->next = next;
    if(!next)
        next->prev = tmp;
    else L.tail = tmp;
    tmp->prev = ptr;
    ptr->next = tmp;
}

void DremovePos(dList &L, int pos)
{
    if(pos < 1)
    {
        cout << "Error!";
        return;
    }
    if(pos == 1)
    {
        DremoveHead(L);
        return;
    }
    dnode* tmp = L.head;
    while(pos != 2)
    {
        tmp = tmp->next;
        pos--;
    }
    dnode* next = tmp->next;
    if(next == L.tail)
        L.tail = tmp;
    else 
        next->next->prev = tmp;
    tmp->next = next->next;
    delete next;
}

void DaddBefore(dList& L, int data, int val)
{
    dnode* tmp = createDnode(data);
    if(!L.head)
    {
        cout << "Error!";
        return;
    }
    if(L.head->key == val)
    {
        tmp->next = L.head;
        L.head = tmp;
        return;
    }
    dnode* ptr = L.head;
    while(ptr->next->key != val && ptr->next)
        ptr = ptr->next;
    if(!ptr->next)
    {
        cout << "Value not found!";
        return;
    }
    tmp->next = ptr->next;
    ptr->next = tmp;
    tmp->next->prev = tmp;
}

void DaddAfter(dList& L, int data, int val)
{
    if(!L.head)
    {
        cout << "Error!";
        return;
    }
    dnode* ptr = L.head;
    while(ptr->key != val && ptr->next)
        ptr = ptr->next;
    if(!ptr->next)
    {
        cout << "Value not found!";
        return;
    }
    dnode* tmp = createDnode(data);
    tmp->next = ptr->next;
    tmp->prev = ptr;
    ptr->next = tmp;
}

void DprintList(dList L)
{
    while(L.head)
    {
        printf("%d ",L.head->key);
        L.head = L.head->next;
    }
}

int DcountElements(dList L)
{
    int count = 0;
    while(L.head)
    {
        count++;
        L.head = L.head->next;
    }
    return count;
}

dList DreverseList(dList& L)
{
    dnode* prev = NULL, * cur = L.head, * next = L.head;
    L.tail = cur;
    while(cur)
    {
        cur->prev = next;
        next = next->next;
        cur->next = prev;
        if(prev)
            prev->prev = cur;
        prev = cur;
        cur = next;
    }
    L.head = prev;
}

void DremoveDuplicate(dList &L)
{
    vector<int> a;
    a.push_back(L.head->key);
    dnode* cur = L.head;
    while(cur->next)
    {
        if(find(a.begin(),a.end(), cur->key) != a.end())
        {
            dnode* next = cur->next;
            cur->next = next->next;
            if(!next->next)
                L.tail = cur;
            else
                next->next->prev = cur;
            delete next;
        }
        else a.push_back(cur->key);
        cur = cur->next;
    }
}

bool DremoveElement(dList &L, int key)
{
    if(!L.head)
    {
        cout << "Error!";
        return 0;
    }
    bool remove = 0;
    dnode* cur = L.head;
    while(cur->key == key)
    {
        DremoveHead(L);
        remove = 1;
    }
    while(cur->next)
    {
        if(cur->next->key == key)
        {
            dnode* next = cur->next;
            cur->next = next->next;
            if(!next->next)
                L.tail = cur;
            else next->next->prev = cur;
            delete next;
        }
    }
}

//6. Stack - Queue

void push(stack& a,int data)
{
    if(!a.head)
    {
        a.head = createNode(data);
        a.tail = a.head;
        return;
    }
    node* tmp = createNode(data);
    tmp->next = a.head;
    a.head = tmp;
}

void pop(stack& a)
{
    if(!a.head)
    {
        cout << "Error!";
        return;
    }
    node* tmp = a.head->next;
    delete tmp;
    a.head = tmp;
}

int countStack(stack a)
{
    node* tmp = a.head;
    int count = 0;
    while(tmp)
    {
        count++;
        tmp = tmp->next;
    }
}

bool isStackEmpty(stack a)
{
    if(!a.head)
        return true;
    return false;
}

void enqueue(queue& a, int data)
{
    if(!a.head)
    {
        a.head = createNode(data);
        a.tail = a.head;
        return;
    }
    node* tmp = createNode(data);
    a.tail->next = tmp;
    a.tail = tmp;
}

void dequeue(queue& a)
{
    if(!a.head)
    {
        cout << "Error!";
        return;
    }
    node* tmp = a.head->next;
    delete tmp;
    a.head = tmp;
}

int countQueue(queue a)
{
    node* tmp = a.head;
    int count = 0;
    while(tmp)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

bool isQueueEmpty(queue a)
{
    if(!a.head)
        return true;
    return false;
}