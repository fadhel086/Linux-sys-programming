/* Write a Macro which generates a function which returns pointer to the object from gl_thread_t member.
   for example for the data structure below, macro should generate a fuction called "glnode_to_employee", whose prototype is as
emp_t *glnode_to_employee(glthread_node_t *glnode);
 The above function must return pointer to emp_t object, when invoked with address of glnode member of emp_t as an argument.
 */

#define glthread_to_object(fn_name, struct_name, member) \
	static inline struct struct_name *fn_name(glthread_node_t *member) { \
		return (struct_name *)((char *)member - offset(struct_name, member)); \
	}\
