#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define offset(type, member) (unsigned int)&(((type *)0)->member)


typedef struct glthread_node_ {
	struct glthread_node_ *left, *right;
}glthread_node_t;

typedef struct gl_dll_ {
	glthread_node_t *head;
}gldll_t;

typedef struct emp_ {
	char name[30];
	unsigned int salary;
	char designation[30];
	unsigned int emp_id;
	glthread_node_t glnode;
}emp_t;

void print_employee_info(emp_t *emp);

/* Invoke below to print employee Details */
void print_employee_details(glthread_node_t *glnode)
{
	emp_t *emp = (emp_t *)((char *)glnode - offset(emp_t, glnode));	
	print_employee_info(emp);
}

/*function to print employee details */
void print_employee_info(emp_t *emp)
{
	printf("Employee name: %s\n", emp->name);
	printf("Salary: %d\n", emp->salary);
	printf("Designation: %s\n", emp->designation);
	printf("Employee ID: %d\n", emp->emp_id);
}


int main(){

	/* Creating one employee object */
	emp_t *emp1 = calloc(1, sizeof(emp_t));
	strncpy(emp1->name, "Fadhel", strlen("Fadhel"));
	emp1->salary = 64000;
	strncpy(emp1->designation, "Sr.Engineer", strlen("Sr.Engineer"));
	emp1->emp_id = 212;

	print_employee_details(&emp1->glnode);
	return 0;
}
