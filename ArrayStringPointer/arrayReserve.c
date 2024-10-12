#include <stdio.h>

void arrayReserve(double array[])
{
    printf("Please enter 10 numbers:\n");
    for (int i = 0; i < 10; ++i)
        scanf("%lf", &array[i]);
    for (int i = 9; i >= 0; --i)
        printf("%lf ", array[i]);
}

int main()
{
    double A[10];
    arrayReserve(A);
    return 0;
}