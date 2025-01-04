#include <stdio.h>

#define N 1000001

int n, q;
int a[N];

void swap(int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void heapify(int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && a[largest] < a[left])
        largest = left;
    if (right < n && a[largest] < a[right])
        largest = right;
    if (largest != i)
    {
        swap(i, largest);
        heapify(n, largest);
    }
}

void buildHeap()
{
    for(int i = n/2 - 1; i >= 0; i--)
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

int bSearch(int a[], int left, int right, int k)
{
    if (left > right)
        return -1;
    if (left == right)
    {
        if (a[left] == k)
            return left;
        else
            return -1;
    }
    int mid = (left + right)/2;
    if (a[mid] == k)
        return mid;
    else if (a[mid] < k)
        return bSearch(a, mid + 1, right, k);
    else
        return bSearch(a, left, mid - 1, k);
}

void input()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int main()
{
    input();
    heapSort();
    int result = 0;
    for (int i = 0; i < n-2; i++)
    {
        int index = bSearch(a, i+1, n-1, q-a[i]);
        if (index > -1)
            result++;
    }
    printf("%d\n", result);
    return 0;
}