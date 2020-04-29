#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glthreads.h"

typedef struct family {
	char name[30];
	int age;
	gl_node_t glnode;
} family_t;


void print_family_details(family_t *per)
{
	printf("\n");
	printf("Name:%s\n", per->name);
	printf("Age:%d\n", per->age);
}

int main() {

	/* family member 1 */
	family_t *per1 = calloc(1, sizeof(family_t));
	strncpy(per1->name, "Fadhel Habeeb", strlen("Fadhel Habeeb"));
	per1->age = 33;
	init_glnode(per1->glnode);

	/* family member 2*/
	family_t *per2 = calloc(1, sizeof(family_t));
	strncpy(per2->name, "Fidha Fathima K", strlen("Fidha Fathima K"));
	init_glnode(per2->glnode);

	/* family member 3*/
	family_t *per3 = calloc(1, sizeof(family_t));
	strncpy(per3->name, "Maryam Fadhel", strlen("Maryam Fadhel"));
	per3->age = 4;
	init_glnode(per3->glnode);

	/*family member 4*/
	family_t *per4 = calloc(1, sizeof(family_t));
	strncpy(per4->name, "Aymen Fadhel", strlen("Aymen Fadhel"));
	per4->age = 1;
	init_glnode(per4->glnode);

	gl_t *family_db = calloc(1, sizeof(gl_t));
	init_gl_list(family_db, offsetof(family_t, glnode));
	
	glthread_add(family_db, &per1->glnode);
	glthread_add(family_db, &per2->glnode);
	glthread_add(family_db, &per3->glnode);
	glthread_add(family_db, &per4->glnode);
		
	family_t *ptr = NULL;

	ITERATE_GLTHREAD_BEGIN(family_db, family_t, ptr) {
		print_family_details(ptr);
	} ITERATE_GLTHREAD_END;

	// Let's remove one node and test
	glthread_remove(family_db, &per3->glnode);
	free(per3);
	ptr = NULL;
	ITERATE_GLTHREAD_BEGIN(family_db, family_t, ptr) {
		print_family_details(ptr);
	} ITERATE_GLTHREAD_END;

	// Free all nodes and database
	ptr = NULL;
	ITERATE_GLTHREAD_BEGIN(family_db, family_t, ptr) {
		glthread_remove(family_db, &ptr->glnode);
		free(ptr);
	} ITERATE_GLTHREAD_END;

	free(family_db);
		
	return 0;
}
