#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

void swap(int* a, int* b);
int* sum(int* a, int* b);
void inputArray(int* &a, int &n);
void printArray(int* a, int n);
int* findMax(int* arr, int n);
int* findLongestAscendingSubarray(int* a, int n, int &length);
void swapArrays(int* &a, int* &b, int &na, int &nb);
int* concatenate2Arrays(int* a, int* b, int na, int nb, int &nc);
int* merge2Arrays(int* a, int* b, int na, int nb, int &nc);
void print2D(int** a, int length, int width);
void delete2D(int** a, int row);
void generateMatrix1(int** &a, int &length, int &width);
int** generateMatrix2(int* a, int* b, int na, int nb, int &crow, int &ccol);
void swapRows(int** a, int length, int width, int ir1, int ir2);
void swapColumns(int** a, int length, int width, int ic1, int ic2);
int** transposeMatrix(int** a, int length, int width);
int** concatenate2MatricesH(int** a, int** b, int length, int width, int &lres, int &wres);
int** concatenate2MatricesV(int** a, int** b, int length, int width, int &lres, int &wres);
bool multiple2Matrices(int**& res, int** a, int **b, int& lengthr, int& widthr, int lengtha, int widtha, int lengthb, int widthb);
int** findSubmatrix(int** a, int length, int width, int &lres, int &wres);
int LinearSearch(int* a, int n, int key);
int SentinelLinearSearch(int* a, int n, int key);
int BinarySearch(int* a, int n, int key);
int RecursiveBinarySearch(int* a, int left, int right, int key);
int recursionSum(int sum, int n);
int recursionFactorial(int result, int n);
double recursionExponential(double x, int n);
int recursionCountDigits(int n);
bool recursionAllDigitsEven(int n);
int recursionCountDivisor(int a, int b, int divisor);
int gcd(int a, int b);
int lcm(int a, int b);
int recursionReverseValue(int result, int num);
int recursionFibonacci(int n);
void stringPermutation(string& str, int l, int r);

//3. File handling
struct Examinee
{
    string id;
    float maths, literature, physics, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
};

Examinee readExaminee(string line_info);
vector<Examinee> readExamineeList(string line_info);
void writeScores(vector<Examinee> examinee_list, string out_file_name);

//4. Linked list
struct node
{
    int key;
    node* next;
};

struct list
{
    node* head;
    node* tail;
};

node* createNode(int data);
list createList(node* pNode);
void addHead(list &L, int data);
void addTail(list &L, int data);
void removeHead(list &L);
void removeTail(list &L);
void removeAll(list &L);
void removeBefore(list& L, int val);
void removeAfter(list& L, int val);
void addPos(list &L, int data, int pos);
void removePos(list &L, int pos);
void addBefore(list& L, int data, int val);
void addAfter(list& L, int data, int val);
void printList(list L);
int countElements(list L);
list reverseList(list L);
void removeDuplicate(list &L);
bool removeElement(list &L, int key);

//5. Doubly Linkedlist
struct dnode 
{
    int key;
    dnode* next;
    dnode* prev;
};
struct dList 
{
    dnode* head;
    dnode* tail;
};

dnode* createDnode(int data);
dList createDList(dnode* pNode);
void DaddHead(dList &L, int data);
void DaddTail(dList &L, int data);
void DremoveHead(dList &L);
void DremoveDTail(dList &L);
void DremoveAll(dList &L);
void DremoveBefore(dList& L, int val);
void DremoveAfter(dList& L, int val);
void DaddPos(dList &L, int data, int pos);
void DremovePos(dList &L, int pos);
void DaddBefore(dList& L, int data, int val);
void DaddAfter(dList& L, int data, int val);
void DprintList(dList L);
int DcountElements(dList L);
dList DreverseList(dList L);
void DremoveDuplicate(dList &L);
bool DremoveElement(dList &L, int key);

//6. Stack - Queue
struct stack
{
    node* head;
    node* tail;
};

struct queue
{
    node* head;
    node* tail;
};

void push(stack& a, int data);
void pop(stack& a);
int countStack(stack a);
bool isStackEmpty(stack a);

void enqueue(queue& a,int data);
void dequeue(queue& a);
int countQueue(queue a);
bool isQueueEmpty(queue a);