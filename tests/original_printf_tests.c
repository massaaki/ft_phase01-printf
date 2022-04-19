#include <stdio.h>

int	main(void)
{
	int num_int = 123;
	char str[] = "ABCDEFG";
	char singleChar = 'Z';

	printf("'%dany-string'\n", num_int);	 // '123any-string'
	printf("'% 5dany-string'\n", num_int); // '  123any-string'
	printf("'%10dany-string'\n", num_int); // '       123any-string'
	printf("'%-#x'\n", num_int);					 // '0x7b'
	printf("'%-#5x'\n", num_int);					 // '0x7b  '
	printf("'%d'\n", singleChar);					 // '90' <== returns ASCII
	printf("'%1.4s'\n", str); // 'min 4, max 8 -> if strlen==0 prints ' '

	return (0);
}