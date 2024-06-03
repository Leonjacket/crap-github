#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
struct node
{
    int x;
    int day;
    int month;
    int year;
    float y;
    node* next;
};

struct List
{
    node* head;
    node* tail;
};

node* createNode(int x, int day, int month, int year, float y)
{
    node* tmp = new node;
    tmp->x = x;
    tmp->day = day;
    tmp->month = month;
    tmp->year = year;
    tmp->y = y;
    tmp->next = NULL;
    return tmp;
}

List readFile(string path)
{
    List a;
    ifstream in(path);
    string x,day,month,year,y;
    getline(in,x,'\n');
    getline(in,x,' ');
    getline(in,day,'/');
    getline(in,month,'/');
    getline(in,year,' ');
    getline(in, y);
    a.head = createNode(stoi(x),stoi(day),stoi(month),stoi(year),stof(y));
    node* ptr = a.head;
    while(getline(in,x,' '))
    {
        getline(in,day,'/');
        getline(in,month,'/');
        getline(in,year,' ');
        getline(in, y);
        node* tmp = createNode(stoi(x),stoi(day),stoi(month),stoi(year),stof(y));
        ptr->next = tmp;
        ptr = ptr->next;
    }
    a.tail = ptr;
    in.close();
    return a;
}

void printList(List a)
{
    node* tmp = a.head;
    while(tmp)
    {
        cout << tmp->x << " " << tmp->day << " " << tmp->month << " " << tmp->year << " " << tmp->y << "\n";
        tmp = tmp->next;
    }
}

void pushStack(List a, int x, int day, int month, int year, float y)
{

}

int main()
{
    List a = readFile("train.txt");
    printList(a);
    return 0;
}

