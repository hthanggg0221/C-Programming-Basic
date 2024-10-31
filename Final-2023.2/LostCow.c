#include <stdio.h>
#include <math.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    int i = 1, pre = x, distance = 0, dir = 1;
    while(1)
    {
        distance += abs(x + dir * i - pre);
        pre = x + dir * i;
        if ((x >= y && pre <= y) || (y >= x && pre >= y))
        {
            distance -= abs(y - pre);
            break;
        }
        i *= 2;
        dir *= (-1);
    }
    printf("%d\n", distance);
    return 0;
}
