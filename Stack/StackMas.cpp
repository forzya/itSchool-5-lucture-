#include <stdio.h>

#define maxsize 100

typedef struct stack
{
	char bracket[maxsize];
	int top;
}stack;

void initial(stack *mystack);
void push(stack *mystack, char symbol);
char pop(stack *mystack);
bool checkbrecket(stack *mystack, char *str, char *open, char *close);
bool isEmpty(stack *mystack);

int main()
{
	char open[3] = { '(','[','{' };
	char close[3] = { ')',']','}' };
	char str[50];

	stack mystack;
	initial(&mystack);

	fgets(str, 50, stdin);
	
	if (checkbrecket(&mystack, str, open, close) == false)
		printf("false\n");
	else printf("true\n");

	return 0;
}

void initial(stack *mystack)
{
	mystack->top = 0;
}

bool isEmpty(stack *mystack)
{
	if (mystack->top == 0)
		return 0;
	else return 1;
}

void push(stack *mystack, char symbol)
{
	if (mystack->top == maxsize)
	{
		printf("stack full\n");
		return;
	}
	else
	{
		mystack->bracket[mystack->top++] = symbol;
	}
}

char pop(stack *mystack)
{
	if (!mystack->top)
	{
		printf("stack empty\n");
		return 0;
	}
	else
	{
		mystack->top--;
		return mystack->bracket[mystack->top];
	}
}

bool checkbrecket(stack *mystack, char *str, char *open, char *close)
{
	bool f = true;

	for (int i = 0; f==true && str[i] != '\0'; i++)
		for (int j = 0; j < 3;j++)
		{
			if (str[i] == open[j])
			{
				push(mystack, str[i]);
				break;
			}
			if (str[i] == close[j])
			{
				if (pop(mystack) != open[j])
					f = false;
				break;
			}
		}
	if (isEmpty(mystack))
		f = false;

	return f;
}