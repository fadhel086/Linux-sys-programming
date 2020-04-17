#ifndef _DLL_H_
#define _DLL_H_

typedef struct dll_node_ {
	void *data;
	struct dll_node_ *left, *right;
} dll_node_t;

typedef struct dll_ {
	dll_node_t *head;
}dll_t;

/* Initialize the doubly linked list head
   returns head
*/
dll_t *init_dll();

/* Add's data to the doubly linked list
   returns 0 on success, -1 on error
*/
int add_data(dll_t *dll, void *data);

#endif
