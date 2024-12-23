#include <stdio.h>

#define N 100001

int n;
int a[N];

void swap(int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void heapify(int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
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

void printArray()
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
}

void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int main()
{
    input();
    heapSort();
    printArray();
    return 0;
}