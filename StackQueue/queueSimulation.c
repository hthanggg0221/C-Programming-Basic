#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *head;
Node *tail;

void initQueue()
{
    head = NULL;
    tail = NULL;
}

int emptyQueue()
{
    return head == NULL && tail == NULL;
}

Node *makeNode(int val)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->value = val;
    p->next = NULL;
    return p;
}

void push(int val)
{
    Node *p = makeNode(val);
    if (emptyQueue())
    {
        head = p;
        tail = p;
        return;
    }
    tail->next = p;
    tail = p;
}

int pop()
{
    Node *p = head;
    int x = head->value;    
    head = head->next;
    if (head == NULL)
        tail = NULL;
    free(p);
    return x;
}

void freeQueue()
{
    while (!emptyQueue())
    {
        Node *tmp = head;
        head = head->next;
        if(head == NULL)
            tail = NULL;
        free(tmp);
    }   
}

int main()
{
    initQueue();
    char cmd[5];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
            break;
        else if(strcmp(cmd, "PUSH") == 0)
        {
            int v;
            scanf("%d", &v);
            push(v);
        }
        else if(strcmp(cmd, "POP") == 0)
        {
            if (emptyQueue())
                printf("NULL\n");
            else
            {
                printf("%d\n", pop());
            }
        }
    }
    freeQueue();
    return 0;
}