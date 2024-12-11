#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

Node *top;

void initStack()
{
	top = NULL;
}

int emptyStack()
{
	return top == NULL;
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
	p->next = top;
	top = p;
}

int pop()
{
	int x = top->value;
	Node *tmp = top;
	top = top->next;
	free(tmp);
	return x;
}

void freeStack()
{
	while (!emptyStack())
	{
		Node *tmp = top;
		top = top->next;
		free(tmp);
	}
}

int main(){
	initStack();
	char cmd[5];
	while (1)
	{
		scanf("%s", cmd);
		if(strcmp(cmd,"#") == 0)
			break;
		else if(strcmp(cmd, "PUSH") == 0)
		{
			int v;
			scanf("%d", &v);
			push(v);
		}
		else if(strcmp(cmd, "POP") == 0)
		{
			if(emptyStack())
				printf("NULL\n");
			else
				printf("%d\n", pop());
		}
	}
	freeStack();
    return 0;
}
