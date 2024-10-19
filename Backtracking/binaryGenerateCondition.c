#include <stdio.h>

int X[20];
int n;

void solution()
{
    for (int i = 1; i <= n; i++)
        printf("%d", X[i]);
    printf("\n");
}

int check(int v, int k)
{
    if (k == 1)
        return 1;
    else
        return v + X[k - 1] <= 1;
}

void Try(int k)
{
    for (int v = 0; v <= 1; v++)
    {
        if (check(v, k))
        {
            X[k] = v;
            if (k == n)
                solution();
            else
                Try(k + 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(1);
    return 0;
}