#include <stdio.h>

void arrayReserve(double array[])
{
    printf("Please enter 10 numbers:\n");
    for (int i = 0; i < 10; ++i)
        scanf("%d", &array[i]);
    for (int i = 9; i >= 0; --i)
        printf("%d ", array[i]);
}

int main()
{
    double A[10];
    arrayReserve(A);
    return 0;
}