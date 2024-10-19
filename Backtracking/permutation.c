#include <stdio.h>

int X[21];
int n;
int mark[21];

void solution()
{
    for (int i = 1; i <= n; i++)
        printf("%d ", X[i]);
    printf("\n");
}

int check(int v, int k)
{
    return mark[v] == 0;
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            X[k] = v;
            mark[v] = 1;
            if (k == n)
                solution();
            else
                Try(k + 1);
            mark[v] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        mark[i] = 0;
    Try(1);
    return 0;
}