#include "glthreads.h"

void glthread_add(gl_t *list, gl_node_t *glnode)
{
	/* check if head is empty */
	if (!list->head) {
		list->head = glnode;
		return;
	}

	glnode->right = list->head;
	list->head->left = glnode;
	list->head = glnode;
}

void glthread_remove(gl_t *list, gl_node_t *glnode)
{
	gl_node_t *head = list->head;
	// If it's head to remove
	if (head == glnode) {
		glnode->right->left = NULL;
		list->head = glnode->right;
		glnode->right = NULL;
		return;
	}

	// if it's the last node
	if (!glnode->right) {
		glnode->left->right = NULL;
		glnode->left = NULL;
		return;
	}

	glnode->left->right = glnode->right;
	glnode->right->left = glnode->left;
	glnode->right = NULL;
	glnode->left = NULL;
}

void init_gl_list(gl_t *list, unsigned int offset)
{
	list->head = NULL;
	list->offset = offset;
}
