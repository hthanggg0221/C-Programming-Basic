#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100001
#define MAX_LEN 101

int n;
char* s[N];

void swap(int i, int j)
{
    char *t = s[i];
    s[i] = s[j];
    s[j] = t;
}

void heapify(int size, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < size && strcmp(s[left], s[largest]) > 0)
        largest = left;
    if (right < size && strcmp(s[right], s[largest]) > 0)
        largest = right;
    if (largest != i)
    {
        swap(largest, i);
        heapify(size, largest);
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
    for (int i = n-1; i >= 0; i--)
    {
        swap(i, 0);
        heapify(i, 0);
    }
}

void input()
{
    scanf("%d", &n);
    char str[MAX_LEN];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        s[i] = (char*)malloc(strlen(str)+1);
        strcpy(s[i], str);
    }      
}

void output()
{
    for (int i = 0; i < n; i++)
        printf("%s\n", s[i]);
}

void freeMemory()
{
    for (int i = 0; i < n; i++)
        free(s[i]);
}

int main()
{
    input();
    heapSort();
    output();
    freeMemory();
    return 0;
}