#include <stdio.h>

#define P 1000000007

int combination(int k, int n)
{
    if (k == 0 || k == n)
        return 1;
    return (combination(k - 1, n - 1) + combination(k, n - 1)) % P;
}

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%d\n", combination(k, n));
    return 0;
}