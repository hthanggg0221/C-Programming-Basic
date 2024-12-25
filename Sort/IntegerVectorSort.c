#include <stdio.h>
#include <stdlib.h>

#define N 100001

int n, m;
int *a[N];

void input()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(sizeof(int) * (m+1));
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
}

void swap(int i, int j)
{
    int *temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int compare(int i, int j)
{
    for (int k = 0; k < m; k++)
    {
        if (a[i][k] < a[j][k]) return -1;
        else if(a[i][k] > a[j][k]) return 1;
    }
    return 0;
}

void heapify(int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && compare(largest, left) < 0)
        largest = left;
    if (right < n && compare(largest, right) < 0)
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

void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main()
{
    input();
    heapSort();
    output();
    return 0;
}