#include <stdlib.h>
#include "dll.h"

int remove_data_from_dll_by_data_ptr(dll_t *dll, void *data)
{
	dll_node_t *remove_node = NULL;

	if (!dll || !dll->head || !data)
		return -1;

	remove_node = dll->head;
	// if data is in head_node, remove and return
	if (remove_node->data == data) {
		dll->head = dll->head->right;
		dll->head->left = NULL;
		free(remove_node);
		return 0;
	}
	remove_node = remove_node->right;
	
	while(remove_node)
	{
		if (remove_node->data == data) {
			remove_node->left->right = remove_node->right;
			remove_node->right->left = remove_node->left;
			free(remove_node);
			return 0;
		}		
		remove_node = remove_node->right;
	}	
	return -1;
}

int is_dll_empty(dll_t *dll)
{
	if (!dll || !dll->head)
		return 0;
	return -1;
}

void drain_dll(dll_t *dll)
{
	dll_node_t *drain_node = NULL;

 	if (!dll || !dll->head)
		return;
	
	drain_node = dll->head;
	while(drain_node)
	{	
		// Move head to next node and remove present node
		dll->head = drain_node->right;
		free(drain_node);
		drain_node = dll->head;		
	}			
}
