#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define N		(10)
#define STACK_MAX 100

struct Stack {
	int		data[STACK_MAX];
	int		size;
};
typedef struct Stack Stack;

void Stack_Init(Stack *S)
{
	S->size = 0;
}

int Stack_Top(Stack *S)
{
	if (S->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return -1;
	}

	return S->data[S->size-1];
}

void Stack_Push(Stack *S, int d)
{
	if (S->size < STACK_MAX)
		S->data[S->size++] = d;
	else
		fprintf(stderr, "Error: stack full\n");
}

void Stack_Pop(Stack *S)
{
	if (S->size == 0)
		fprintf(stderr, "Error: stack empty\n");
	else
		S->size--;
}


int main(void)
{
	int a;
	int accum_num = 0;
	int stack_counter = 0;
	struct Stack* stack = malloc(sizeof(struct Stack));

	while(1) {
		a = getchar();
		while (isdigit(a) != 0) {
			accum_num = accum_num * 10 + (a-'0');
			a = getchar();
		}
		if (accum_num != 0) {
			printf("the number %d was pushed to stack\n", (accum_num));
			accum_num = 0;
		}

		switch (a)
			{
				case '+':
					printf("+\n");
					break;
				case '-':
					printf("-\n");
					break;
				case '*':
					printf("*\n");
					break;
				case '/':
					printf("/\n");
					break;
				case '\n':
					printf("calculating\n");
					break;
			}
		//printf("you pressed: %d\n", isdigit(a));
	}
}
