#include <stdio.h>

struct list
{
    char data;
    struct list *link;
};
// Cấu trúc tự trỏ

int main()
{
    struct list item1,item2,item3;
    item1.data = 'a';
    item2.data = 'b';
    item3.data = 'c';
    item1.link = item2.link = item3.link = NULL;
    return 0;
}