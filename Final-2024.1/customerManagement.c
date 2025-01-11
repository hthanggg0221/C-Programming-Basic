#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer
{
    char id[8];
    char name[21];
    char level[7];
    struct Customer *next;
} Node;

Node *root, *tail;

void initQueue()
{
    root = NULL;
    tail = NULL;
}

int queueEmpty()
{
    return root == NULL && tail == NULL;
}

Node *makeNode(char *x, char *y, char *z)
{
    Node *p = (Node*)malloc(sizeof(Node));
    strcpy(p->id, x);
    strcpy(p->name, y);
    strcpy(p->level, z);
    p->next = NULL;
    return p;
}

void insert(char *x, char *y, char *z)
{
    Node *p = makeNode(x, y, z);
    if (queueEmpty())
    {
        root = p;
        tail = p;
        return;
    }
    tail->next = p;
    tail = p;
}

void print()
{
    Node *p;
    if (queueEmpty())
        printf("EMPTY\n");
    else
        for (p = root; p != NULL; p = p->next)
            printf("%s %s %s\n", p->id, p->name, p->level);
}

void vip()
{
    Node *prev, *cur;

    while(root != NULL)
    {
        if(strcmp(root->level, "VIP") == 0)
        {
            cur = root;
            root = root->next;
            free(cur);
            if (root == NULL)
                tail = NULL;
        }
        else
            break;
    }
    if (root != NULL)
    {
        prev = root;
        cur = root->next;
        while (cur != NULL)
        {
            if (strcmp(cur->level, "VIP") == 0)
            {
                if (cur == tail)
                    tail = prev;
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
                continue;
            }
            if (cur != NULL)
            {
                prev = cur;
                cur = cur->next;
            }
        }
        
    }
}
void gold()
{
    int count = 0;
    Node *p = root;
    while (p != NULL)
    {
        if (strcmp(p->level, "GOLD") == 0)
            count++;
        p = p->next;
    }
    if (!count)
        printf("NO GOLD\n");
    else
        printf("%d\n", count);
    
}

void serve()
{
    if (queueEmpty())
        return;
    else
    {
        Node *p = root;
        root = root->next;
        free(p);
        if (root == NULL)
            tail = NULL;
    }
}

void freeQueue()
{
    while (!queueEmpty())
    {
        Node *p = root;
        root = root->next;
        free(p);
        if (root == NULL)
            tail = NULL;
    }
}

int main()
{
    char cmd[7];
    char x[8], y[21], z[7];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
            break;
        else if (strcmp(cmd, "Create") == 0)
            initQueue();
        else if (strcmp(cmd, "Insert") == 0)
        {
            scanf("%s %s %s", x, y, z);
            insert(x, y, z);
        }
        else if (strcmp(cmd, "Print") == 0)
            print();
        else if(strcmp(cmd, "Vip") == 0)
            vip();
        else if(strcmp(cmd, "Gold") == 0)
            gold();
        else if(strcmp(cmd, "Serve") == 0)
            serve();
    }
    freeQueue();
    return 0;
}