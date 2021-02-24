#include <stdio.h>

int main(void)
{
	int a = 0;
	while ( a <= 100 ) {
		printf("%d", a);
		if ( ( a % 3 ) == 0 ) {
			printf("fizz");
		}
		if ( ( a % 5 ) == 0 ) {
			printf("buzz");
		}
		printf("\n");
		a = a + 1;
	}
	return 0;
}
