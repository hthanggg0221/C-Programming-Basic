#include <stdio.h>
#include <string.h>

#define N 100001

int n;
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
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(i, largest);
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

int bSearch(int a[], int left, int right, int k)
{
    if (left > right)
        return 0;
    if (left == right)
    {
        if (a[left] == k)
            return left;
        else
            return 0;
    }
    int mid = (left + right)/2;
    if (a[mid] == k)
        return 1;
    else if (a[mid] < k)
        return bSearch(a, mid + 1, right, k);
    else
        return bSearch(a, left, mid - 1, k);
}

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    heapSort();
    char cmd[6];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
            break;
        if (strcmp(cmd, "check") == 0)
        {
            int k;
            scanf("%d", &k);
            printf("%d\n", bSearch(a, 0, n - 1, k));
        }
    }
    
}



int main()
{
    solve();
    return 0;
}