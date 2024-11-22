#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20

char name[NAME_LENGTH];

typedef struct Node
{
    char value[NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    Node* tail;
} Queue;

void initQueue(Queue *p)
{
    p->head = NULL;
    p->tail = NULL;
}

Node* makeNode(char *s)
{
    Node *p = (Node*)malloc(sizeof(Node));
    strcpy(p->value, s);
    p->next = NULL;
    return p;
}

int queueEmpty(Queue *p)
{
    return p->head == NULL && p->tail == NULL;
}

void enqueue(Queue *q, char* s)
{
    Node *p = makeNode(s);
    if(queueEmpty(q))
    {
        q->head = p;
        q->tail = p;
        return;
    }
    q->tail->next = p;
    q->tail = p;
}

void dequeue(Queue *p)
{
    if (queueEmpty(p))
    {
        printf("NULL\n");
        return;
    }
    Node* tmp = p->head;
    printf("Welcome %s\n", tmp->value); 
    p->head = p->head->next;
    if (p->head == NULL)
        p->tail = NULL;
    free(tmp);
}

void freeQueue(Queue *p)
{
    while(!queueEmpty(p))
    {
        Node *tmp = p->head;
        p->head = p->head->next;
        if (p->head == NULL)
            p->tail = NULL;
        free(tmp);
    }
}

int main()
{
    Queue male, female;
    initQueue(&male);
    initQueue(&female);
    char cmd[10];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
            break;
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            int choice;
            scanf("%d %s", &choice, name);
            if (choice == 0)
                enqueue(&male, name);
            else if(choice == 1)
                enqueue(&female, name);
        }
        if (strcmp(cmd, "DEQUEUE") == 0)
        {
            int choice;
            scanf("%d", &choice);
            if (choice == 0)
            {
                dequeue(&male);
            }
            else if (choice == 1)
            {
                dequeue(&female);
            }
        }
    }
    freeQueue(&male);
    freeQueue(&female);
    return 0;
}