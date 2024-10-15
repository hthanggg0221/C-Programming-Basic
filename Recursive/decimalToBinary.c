#include <stdio.h>

void convert(int number)
{
    if (number == 0)
        return;
    int binary = number % 2;
    convert(number / 2);
    printf("%d", binary);
}

int main()
{
    int n;
    scanf("%d", &n);
    convert(n);
    return 0;
}