#include <stdio.h>

#define N 100001

int n, k;
int a[N];

void input()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
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
    else if(a[mid] < k)
        return bSearch(a, mid + 1, right, k);
    else
        return bSearch(a, 0, mid - 1, k);
}

void output()
{
    printf("%d", bSearch(a, 0, n-1, k));
}

int main()
{
    input();
    output();
    return 0;
}