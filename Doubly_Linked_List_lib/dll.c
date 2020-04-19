#include "dll.h"
#include <stdlib.h>

dll_t *init_dll()
{
	dll_t *dll = calloc(1, sizeof(dll_t));
	dll->head = NULL;
	return dll;
}

int add_data(dll_t *dll, void *data)
{
	if (!dll || !data)
		return -1;

	// Initialize the node
	dll_node_t *new_node = calloc(1, sizeof(dll_node_t));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = data;

	// Insert to end of dll_t
	if ( !dll->head ) {
		dll->head = new_node;
		return 0;
	}

	/* head, will be always to the right */
	dll_node_t *first_node = dll->head;
	first_node->left = new_node;
	new_node->right = first_node;
	dll->head = new_node;

	return 0;
}
