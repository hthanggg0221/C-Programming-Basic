#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int key;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *root;

void initBST()
{
    root = NULL;
}

Node *makeNode(int k)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = k;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *insert(Node *p ,int k)
{
    if (p == NULL)
        p = makeNode(k);
    else if (p->key > k)
        p->leftChild = insert(p->leftChild, k);
    else if (p->key < k)
        p->rightChild = insert(p->rightChild, k);
    return p;
}

void preOrder(Node *r)
{
    if (r == NULL)
        return;
    printf("%d ", r->key);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}

void postOrder(Node *r)
{
    if (r == NULL)
        return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
    printf("%d ", r->key);
}

void freeBST(Node *r)
{
    if (r == NULL)
        return;
    freeBST(r->leftChild);
    freeBST(r->rightChild);
    free(r);
}

int main()
{
    initBST();
    while (1)
    {
        char cmd[10];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
            break;
        else if (strcmp(cmd, "insert") == 0)
        {
            int value;
            scanf("%d", &value);
            root = insert(root, value);
        }
        else if (strcmp(cmd, "preorder") == 0)
        {
            preOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "postorder") == 0)
        {
            postOrder(root);
            printf("\n");
        }
    }
    freeBST(root);
    return 0;
}