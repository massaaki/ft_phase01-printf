#include <stdio.h>
#include <limits.h>
int returnInt();

int main(void)
{
	int num_int = 123;
	char str[] = "hello world";
	char singleChar = 'Z';
	int result;

	int test = INT_MIN;

	printf("x: '%x'\n", test);

	// printf("'%dany-string'\n", num_int);	 // '123any-string'
	// printf("'% 5dany-string'\n", num_int); // '  123any-string'
	// printf("'%10dany-string'\n", num_int); // '       123any-string'
	// printf("'%-#x'\n", num_int);					 // '0x7b'
	// printf("'%-#5x'\n", num_int);					 // '0x7b  '
	// printf("'%d'\n", singleChar);					 // '90' <== returns ASCII
	// printf("'%1.4s'\n", str); // 'min 4, max 8 -> if strlen==0 prints ' '

	// result = printf("%s", "hello: 123456 world\n");


	// printf("hello: %p world\n", &str);

	// printf("\n\nresult: %d\n", result);
	return (0);
}


int returnInt()
{
	return 32;
}