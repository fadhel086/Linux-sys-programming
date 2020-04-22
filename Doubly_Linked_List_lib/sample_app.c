/* Program to test the dll library */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dll.h>

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
void print(struct person *member)
{
	printf("\n");
	printf("Name: %s\n", member->name);
	printf("Age: %d\n", member->age);
	printf("Sex: %c\n", member->sex);
}


void my_dump_db(dll_t *db)
{
	if (!db || !db->head) {
		printf("Error in Database.\n");
		return;
	}

	dll_node_t *head = db->head;
	
	while(head) {
		print(head->data);
		head = head->right;
	}
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
	
	// Populate the data base
	if ( add_data(family_db, person1) == -1 )
		die_out("add_data() failed.\n");
		
	if ( add_data(family_db, person2) == -1)
		die_out("add_data() failed.\n");

	if ( add_data(family_db, person3) == -1 )
		die_out("add_data() failed.\n");

	if ( add_data(family_db, person4) == -1 )
		die_out("add_data() failed.\n");

	// Let's see the filled DB
	my_dump_db(family_db);

#if 0
	if ( remove_data_from_dll_by_data_ptr(family_db, person2) == 0) {
		printf("Removed an entry\n");
		dump_db(family_db);
			
	} else {
		die_out("remove_data_from_dll failed.\n");
	}

	// Let's drain the db
	drain_dll(family_db);
	if (is_dll_empty(family_db) == 0) {
		printf("empty Database\n");
	} else {
		die_out("drain_dll failed.\n");
	}
#endif	
	return 0;
}
