#include "dll.h"
#include <stdlib.h>

dll_t *init_dll()
{
	dll_t *dll = calloc(1, sizeof(dll_t));
	dll->head = NULL;
	return dll;
}

void register_comparison_callback(dll_t *dll, int (*comp_call_back)(void *, void *))
{
	dll->comparison_callback = comp_call_back;
}

void register_print_node_callback(dll_t *dll, void (*print_call_back)(void *))
{
	dll->print_node = print_call_back;
}

int dll_priority_insert_data(dll_t *dll, void *data)
{

	if (!dll)
		return -1;

	dll_node_t *data_node = calloc(1, sizeof(dll_node_t));
	data_node->data = data;
	data_node->right = NULL;
	data_node->left = NULL;

	// if Head is NULL, insert at  head and return
	if (!dll->head) {
		dll->head = data_node;
		return 0;
	}

	// if head is alone,
	if (!dll->head->right) {
		if (dll->comparison_callback(data_node->data, dll->head->data) == -1) {
			dll->head->right = data_node;
			data_node->left = dll->head;
		} else {
			dll->head->left = data_node;
			data_node->right = dll->head;
			dll->head = data_node;
		}
		return 0;
	}

	// Here, we have multiple nodes, check if (node > head) insert at head and return
	
	if (dll->comparison_callback(data_node->data, dll->head->data) == 1) {
		dll->head->left = data_node;
		data_node->right = dll->head;
		dll->head = data_node;
		return 0;
	}

	// Iterate over
	dll_node_t *curr = dll->head;
	dll_node_t *prev = NULL;

	while (curr) {
		if (dll->comparison_callback(data_node->data, curr->data) == 1) {
			prev->right = data_node;
			data_node->left = prev;
			data_node->right = curr;
			curr->left = data_node;
			return 0;
		}
		prev = curr;
		curr = curr->right;
	}

	// Add node to the end
	curr = data_node;
	curr->left = prev;
	prev->right = curr;
	
	return 0;
}

void dump_db(dll_t *db)
{
	if (!db || !db->head) {
		printf("Error in Database.\n");
		return;
	}

	dll_node_t *head = db->head;
	
	while(head) {
		db->print_node(head->data);
		head = head->right;
	}
	
}

int add_data(dll_t *dll, void *app_data)
{
	if (!dll || !app_data)
		return -1;

	// Initialize the node
	dll_node_t *new_node = calloc(1, sizeof(dll_node_t));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = app_data;

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
