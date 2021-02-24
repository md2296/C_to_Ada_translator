#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	typedef struct endings_node {
		char *endings_buffer;
		struct endings_node *next;
		struct endings_node *prev;
	} en;
	
	en *en_cur = NULL;
	en_cur = (en *)malloc(sizeof(en));

	en_cur->endings_buffer = "end main";
	en_cur->next = (en *)malloc(sizeof(en));
	en_cur->next->endings_buffer = "end loop";
	en_cur->next->prev = en_cur;
	en_cur = en_cur->next;
	en_cur->next = NULL;

	printf("%s", en_cur->endings_buffer);

	en_cur = en_cur->prev;
	free(en_cur->next);

	printf("%s", en_cur->endings_buffer);
	free(en_cur);

	return 0;
}
