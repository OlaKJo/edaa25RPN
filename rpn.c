#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define N		(10)


int main(void)
{
	int a;
	int accum_num;
	int stack_counter = 0;


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
