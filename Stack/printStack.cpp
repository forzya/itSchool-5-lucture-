void printStack(Node *top)
{
	if (isEmpty(top) == 0)
	{
		printf("stack empty\n");
		return;
	}
	while (top)
	{
		printf("%c ", top->info);
		top = top->prev;
	}
}