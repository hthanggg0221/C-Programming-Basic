#include <stdio.h>

char c;
int n;
int X[100];

void solution()
{
    printf("%c", c);
    for (int i = 1; i <= n; i++)
        printf("%d", X[i]);
    printf("\n");
}

void Try(int k)
{
    for (int v = 1; v <= 5; v += 2)
    {
        X[k] = v;
        if (k == n)
            solution();
        else
            Try(k + 1);
    }
}

int main()
{
    c = getchar();
    scanf("%d", &n);
    if (c >= 'A' && c <= 'E')
        Try(1);
    else
    {
        printf("Error");
        return 1;
    }
    return 0;
}