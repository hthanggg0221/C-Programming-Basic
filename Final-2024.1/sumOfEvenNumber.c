#include <stdio.h>

int n;
int sum = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i = i + 2)
        sum += i;
    printf("%d\n", sum);
    return 0;
}