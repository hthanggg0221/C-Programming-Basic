#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100001
int n;

typedef struct Student
{
    char studentID[11];
    int grade;
    int pos;
} Student;

Student S[N];

void swap(int i, int j)
{
    Student t = S[i];
    S[i] = S[j];
    S[j] = t;
}

void heapify(int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && S[largest].grade < S[left].grade)
        largest = left;
    if (right < n && S[largest].grade < S[right].grade)
        largest = right;
    if (largest != i)
    {
        swap(largest, i);
        heapify(n, largest);
    }
}

void buildHeap()
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(n, i);
}

void heapSort()
{
    buildHeap();
    for (int i = n - 1; i >= 0; i--)
    {
        swap(i, 0);
        heapify(i, 0);
    }
}

void position()
{
    for (int i = 0; i < n; i++)
        S[i].pos = i;
}

void heapify1(int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && strcmp(S[largest].studentID, S[left].studentID) < 0)
        largest = left;
    if (right < n && strcmp(S[largest].studentID, S[right].studentID) < 0)
        largest = right;
    if (largest != i)
    {
        swap(largest, i);
        heapify(n, largest);
    }
}

void buildHeap1()
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapify1(n, i);
}

void heapSort1()
{
    buildHeap1();
    for (int i = n - 1; i >= 0; i--)
    {
        swap(i, 0);
        heapify1(i, 0);
    }
}

void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s %d", S[i].studentID, &S[i].grade);
}

void output()
{
    for (int i = 0; i < n; i++)
        printf("%s %d\n", S[i].studentID, S[i].pos);
}

int main()
{
    input();
    heapSort();
    position();
    heapSort1();
    output();
    return 0;
}