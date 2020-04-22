/* Program to test the dll library */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"

typedef struct person {
	char name[24];
	unsigned char age;
	unsigned char sex;
} person_t;

void die_out(char *err_msg)
{
	printf("%s", err_msg);
	exit(EXIT_FAILURE);
}
void print_family_node(void *node)
{
	struct person *member = (struct person *)node;
	printf("\n");
	printf("Name: %s\n", member->name);
	printf("Age: %d\n", member->age);
	printf("Sex: %c\n", member->sex);
}

int main() {
	
	int ret;
	dll_t *family_db = NULL;

	// Initialize first person
	person_t *person1 = calloc(1, sizeof(person_t));
	strncpy(person1->name, "Fadhel Habeeb", strlen("Fadhel Habeeb"));
	person1->age = 33;
	person1->sex = 'M';

	// Next person
	person_t *person2 = calloc(1, sizeof(person_t));
	strncpy(person2->name, "Fidha Fathima", strlen("Fidha Fathima"));
	person2->age = 27;
	person2->sex = 'F';

	// Next person
	person_t *person3 = calloc(1, sizeof(person_t));
	strncpy(person3->name, "Maryam Fadhel", strlen("Maryam Fadhel"));
	person3->age = 4;
	person3->sex = 'F';

	// Next person
	person_t *person4 = calloc(1, sizeof(person_t));
	strncpy(person4->name, "Aymen Fadhel", strlen("Aymen Fadhel"));
	person4->age = 1;
	person4->sex = 'M';

	// Initialize DB
	family_db = init_dll();
	if (!family_db) {
		die_out("init_dll() failed.\n");
	}

	// Register print node callbacl
	register_print_node_callback(family_db, print_family_node);
	// Populate the data base
	add_data(family_db, person1);
	add_data(family_db, person2);
	add_data(family_db, person3);
	add_data(family_db, person4);

	//Let's dump the family db
	dump_db(family_db);	
	return 0;
}