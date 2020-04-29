#ifndef _GLTHREADS_H_
#define _GLTHREADS_H_

#include <stdlib.h>

#define offsetof(struct_name, member) \
	((unsigned int)&((struct_name *)0)->member)

#define init_glnode(glnode)		\
	{ 				\
		glnode.left = NULL; 	\
		glnode.right = NULL; 	\
	}

typedef struct glthreads_node_t_ {
	struct glthreads_node_t_ *left, *right;
} gl_node_t;

typedef struct glthreads_dll_t_ {
	gl_node_t *head;
	unsigned int offset;
} gl_t;

void glthread_add(gl_t *list, gl_node_t *glnode);
void glthread_remove(gl_t *list, gl_node_t *glnode);
void init_gl_list(gl_t *list, unsigned int offset);

/* Iterative MACRO to Iterate oer GLThreads */

#define ITERATE_GLTHREAD_BEGIN(list, struct_name, out_ptr)	\
	{ \
		gl_node_t *curr = list->head; \
		for(; curr; curr = curr->right) { \
			out_ptr = (struct_name *)((char *)curr - list->offset);
		
#define ITERATE_GLTHREAD_END }}

#endif /* _GLTHREADS_H_ */
