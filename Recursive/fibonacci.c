#include <stdio.h>
#define P 10000000007

int fibonacci(int num)
{
    if (num <= 1)
        return num;
    return (fibonacci(num - 1) + fibonacci(num - 2)) % P;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    return 0;
}