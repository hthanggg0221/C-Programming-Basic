#include <stdio.h>
#include <math.h>
#include <limits.h>

void arrayReserve(double array[])
{
    for (int i = 9; i >= 0; --i)
        printf("%lf ", array[i]);
}

double arrayAverage(double array[])
{
    double averageOfArray = 0;
    for (int i = 0; i < 10; ++i)
        averageOfArray += array[i];
    averageOfArray /= 10.0;
    return averageOfArray;
}

double minDifferent(double array[], double averageOfArray)
{
    double minDiff = INT_MAX;
    for (int i = 0; i < 10; ++i)
    {
        double different = fabs(array[i] - averageOfArray);
        if (different < minDiff)
            minDiff = different;
    }
    return minDiff;
}

void printMinDiffElement(double array[])
{
    printf("Please enter 10 numbers:\n");
    for (int i = 0; i < 10; ++i)
        scanf("%lf", &array[i]);
    double averageOfArray = arrayAverage(array);
    double minDiff = minDifferent(array, averageOfArray);
    for (int i = 0; i < 10; ++i)
        if (minDiff == fabs(array[i] - averageOfArray))
            printf("%lf ", array[i]);
}

int main()
{
    double A[10];
    printMinDiffElement(A);
    return 0;
}