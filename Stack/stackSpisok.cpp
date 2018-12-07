#include <stdio.h>
#include "stdlib.h"
typedef char info_t;

struct Node
{
	info_t info;
	Node *prev;
};


void push(Node **top, info_t value);
int pop(Node **top);
int getTopValue(Node *top);
bool isEmpty(Node *top);
bool checkbrecket(Node *top, char *str, char *open, char *close);


int main()
{
	Node *top = NULL;

	char open[3] = { '(','[','{' };
	char close[3] = { ')',']','}' };
	char str[50];

	fgets(str, 50, stdin);

	if (checkbrecket(top, str, open, close) == false)
		printf("false\n");
	else
		printf("true\n");

	return 0;
}

void push(Node **top, info_t value)
{
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->info = value;

	if ( *top==NULL )
	{
		*top = newnode;
		newnode->prev = NULL;
	}
	else
	{
		newnode->prev = *top;
		*top = newnode;
	}
}

int pop(Node **top)
{
	Node *del;
	info_t value;

	if (*top == NULL)
	{
		printf("stack empty\n");
		return 0;
	}
	else
	{
		del = *top;
		*top = (*top)->prev;
		value = del->info;
		free(del);
		return value;
	}
}

int getTopValue(Node *top)
{
	return(top->info);
}

bool isEmpty(Node *top)
{
	return top == NULL;
}

bool checkbrecket(Node *top, char *str, char *open, char *close)
{
	bool f = true;

	for (int i = 0; f == true && str[i] != '\0'; i++)
		for (int j = 0; j < 3; j++)
		{
			if (str[i] == open[j])
			{
				push(&top, str[i]);
				break;
			}

			if (str[i] == close[j])
			{
				if (pop(&top) != open[j])
					f = false;

				break;
			}
		}

	if (!isEmpty(top))
		f = false;

	return f;
}