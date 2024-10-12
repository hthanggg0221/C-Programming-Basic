#include <stdio.h>

#define NUMBER_OF_CHARACTER 26

int main()
{
    char s;
    int count[NUMBER_OF_CHARACTER] = { 0 };
    while ((s = getchar()) != '\n')
        if (s >= 'a' && s <= 'z')
            count[s - 'a']++;
    for (int i = 0; i < NUMBER_OF_CHARACTER; ++i)
        if (count[i] > 0)
            printf("The letter '%c' appears %d time(s).\n", 'a' + i, count[i]);
    return 0;
}