#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact_t
{
    char msv[6];
    char ten[31];
    float dtb;
} contact;

typedef struct Node
{
    contact el;
    struct Node *next;
} Node;

Node *head;

void initList()
{
    head = NULL;
}

contact readNode()
{
    contact tmp;
    scanf("%s", tmp.msv);
    scanf("%s", tmp.ten);
    scanf("%f", &tmp.dtb);
    return tmp;
}

int emptyList()
{
    return head == NULL;
}

void displayNode(Node *p)
{
    contact temp = p->el;
    printf("%s %s %.2f\n", temp.msv, temp.ten, temp.dtb);
}

Node *makeNode(contact ct)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->el = ct;
    p->next = NULL;
    return p;
}

void insertAtHead(contact ct)
{
    Node *p = makeNode(ct);
    p->next = head;
    head = p;
}

void traversalList()
{
    if (emptyList())
    {
        printf("NULL\n");
        return;
    }
    Node *p;
    for (p = head; p != NULL; p = p->next)
        displayNode(p);
}

float maxOfGPA()
{
    if (emptyList())
        return 0;
    Node *p = head;
    float max = p->el.dtb;
    while (p->next != NULL)
    {
        p = p->next;
        if (max < p->el.dtb)
            max = p->el.dtb;
    }
    return max;
}

float averageOfGPA()
{
    if (emptyList())
        return 0;
    float average = 0.0;
    int count = 0;
    Node *p;
    for (p = head; p != NULL; p = p->next)
    {
        average += p->el.dtb;
        count++;
    }
    average = (float)average / count;
    return average;
}

void deleteStudent(char *x)
{
    if (head == NULL)
        return;
    Node *p = head;
    Node *prev = NULL;
    while (p != NULL)
    {
        if (strcmp(p->el.msv, x) == 0)
        {
            if (prev == NULL)
                head = p->next;
            else
                prev->next = p->next;
            free(p);
            return;
        }
        prev = p;
        p = p->next;
    }
}

void freeList()
{
    while (!emptyList())
    {
        Node *p = head;
        head = head->next;
        free(p);        
    }
}

int main()
{
    char cmd[11];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0)
            break;
        else if(strcmp(cmd, "CreateList") == 0)
            initList();
        else if(strcmp(cmd, "Insert") == 0)
            insertAtHead(readNode());
        else if(strcmp(cmd, "Print") == 0)
            traversalList();
        else if(strcmp(cmd, "Max") == 0)
            printf("%.2f\n", maxOfGPA());
        else if(strcmp(cmd, "Avg") == 0)
            printf("%.2f\n", averageOfGPA());
        else if(strcmp(cmd, "Delete") == 0)
        {
            char x[6];
            scanf("%s", x);
            deleteStudent(x);
        }
    }
    freeList();
    return 0;
}