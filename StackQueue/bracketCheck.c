#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define stringSize 1000000

char s[stringSize];

int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    return 0;
}

typedef struct Node
{
    char value;
    struct Node* next;
} Node;

Node* top;

Node* makeNode(char c)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->value = c;
    p->next = NULL;
    return p;
}

void initStack()
{
    top = NULL;
}

int stackEmpty()
{
    return top == NULL;
}

void push(char c)
{
    Node* p = makeNode(c);
    p->next = top;
    top = p;
}

int pop()
{
    char c = top->value;
    Node* p = top;
    top = top->next;
    free(p);
    return c;
}

int check(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            push(s[i]);
        else
        {
            if(stackEmpty())
                return 0;
            char a = top->value;
            pop();
            if (!match(a, s[i]))
                return 0;
        }
    }
    return stackEmpty();
}

int main()
{
    scanf("%s", s);
    printf("%d", check(s));
    return 0;
}