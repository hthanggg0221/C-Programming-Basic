#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* makeNode(int u)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->id = u;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *find(int u, Node *r)
{
    if (r == NULL)
        return NULL;
    if (r->id == u)
        return r;
    Node *p = find(u, r->leftChild);
    if (p != NULL)
        return p;
    return find(u, r->rightChild);
}

void addLeft(int u, int v, Node *r)
{
    Node *p = find(v, r);
    if (p == NULL)
        return;
    if (p->leftChild != NULL)
        return;
    Node *q = find(u, r);
    if (q != NULL)
        return;
    p->leftChild = makeNode(u);
}

void addRight(int u, int v, Node *r)
{
    Node *p = find(v, r);
    if (p == NULL)
        return;
    if (p->rightChild != NULL)
        return;
    Node *q = find(u, r);
    if (q != NULL)
        return;
    p->rightChild = makeNode(u);
}

void preOrder(Node *r)
{
    if (r == NULL)
        return;
    printf("%d ", r->id);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}

void inOrder(Node *r)
{
    if (r == NULL)
        return;
    inOrder(r->leftChild);
    printf("%d ", r->id);
    inOrder(r->rightChild);
}

void postOrder(Node *r)
{
    if (r == NULL)
        return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
    printf("%d ", r->id);
}

void freeBinaryTree(Node *r)
{
    if (r == NULL)
        return;
    freeBinaryTree(r->leftChild);
    freeBinaryTree(r->rightChild);
    free(r);
}

int main()
{
    char cmd[10];
    Node* root = NULL;
    while(1)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "*") == 0)
            break;
        else if(strcmp(cmd, "MakeRoot") == 0)
        {
            int u;
            scanf("%d", &u);
            root = makeNode(u);
        }
        else if(strcmp(cmd, "AddLeft") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            addLeft(u, v, root);
        }
        else if(strcmp(cmd, "AddRight") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            addRight(u, v, root);
        }
        else if(strcmp(cmd, "PreOrder") == 0)
        {
            preOrder(root);
            printf("\n");
        }
        else if(strcmp(cmd, "InOrder") == 0)
        {
            inOrder(root);
            printf("\n");
        }
        else if(strcmp(cmd, "PostOrder") == 0)
        {
            postOrder(root);
            printf("\n");
        }
    }
    freeBinaryTree(root);
    return 0;
}