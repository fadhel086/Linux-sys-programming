#ifndef _DLL_H_
#define _DLL_H_

#include <stdio.h>

typedef struct dll_node_ {
	void *data;
	struct dll_node_ *left, *right;
} dll_node_t;

typedef struct dll_ {
	dll_node_t *head;
	void (*print_node)(void *);
	int (*comparison_callback)(void *, void *);
}dll_t;

/* Initialize the doubly linked list head
   returns head
*/
dll_t *init_dll();

/* register comparison callback */
void register_comparison_callback(dll_t *dll, int (*call_back)(void *, void *));
/* register print node callbacl */
void register_print_node_callback(dll_t *dll, void (*call_back)(void *));

/* Procedure to dump the database contents */
void dump_db(dll_t *);

/* Inserts data in a sorted manner,
   Returns 0 on success, and -1 on failure
 */

int dll_priority_insert_data(dll_t *dll, void *data);
/* Add's data to the doubly linked list
   returns 0 on success, -1 on error
*/
int add_data(dll_t *dll, void *app_data);

/* return 0 on success and -1 on failure */
int remove_data_from_dll_by_data_ptr(dll_t *dll, void *app_data);

/* return 0 if empty, -1 if not empty */
int is_dll_empty(dll_t *dll);

/* delete all nodes from dll, but do not free appln data */
void drain_dll(dll_t *dll);

#endif
