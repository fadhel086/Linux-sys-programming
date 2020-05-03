#include "serialize.h"

void init_serialized_buffer(ser_buff_t **b)
{
	(*b) = (ser_buff_t *)calloc(1, sizeof(ser_buff_t));
	// if no memory, then fail
	if (*b == NULL) assert(0);

	(*b)->b = calloc(1, SERIALIZE_BUFFER_DEFAULT_SIZE);
	// if no buffer is allocated , fail
	if ((*b)->b == NULL) assert(0);

	(*b)->size = SERIALIZE_BUFFER_DEFAULT_SIZE;
	(*b)->next = 0;
	(*b)->checkpoint = 0;
	return;
}

void init_serialized_buffer_of_defined_size(ser_buff_t **b, int size)
{
	(*b) = (ser_buff_t *)calloc(1, sizeof(ser_buff_t));
	// if no memory fail,
	if (*b == NULL) assert(0);
	
	(*b)->b = calloc(1, size);
	// if no buffer is allocated, fail
	if ((*b)->b == NULL) assert(0);

	(*b)->size = size;
	(*b)->next = 0;
	(*b)->checkpoint = 0;
 	return;
}

void serialize_string(ser_buff_t *b, char *data, int nbytes)
{
	int should_resize = 0;
	if (!b || !b->b) assert(0);
	int available_size = b->size - b->next;

	// Check if there is space to occupy nbytes in ser_but_t
	while(available_size < nbytes) {
		b->size = b->size * 2;
		available_size = b->size - b->next;
		should_resize = 1;
	}

	// Resize and add the data to b->b
	if (should_resize) {
		b->b = realloc(b->b, b->size);
		memcpy(((char *)b->b + b->next), data, nbytes);
		b->next += nbytes;
		return;
	}

	// Copy data and return
	memcpy(((char *)b->b + b->next), data, nbytes);
	b->next += nbytes;
	return;
}

int is_serialized_buffer_empty(ser_buff_t *b)
{
	if (!b || !b->b) assert(0);
	return b->next ? 1:0;
}

// start de-serializing at receiving end from b->next(=0)
void de_serialize_string(char *dest, ser_buff_t *b, int nbytes)
{
	// sanity checks
	if (!dest || !b || !b->b) assert(0);
	// check if nbytes is within the limit to read
	if (!(nbytes < b->size)) assert(0);
	
	// Copy the data to dest buffer and increment b->next;
	memcpy(dest, b->b + b->next, nbytes);
	b->next += nbytes;
}

void copy_in_serialized_buffer_by_offset(ser_buff_t *b, int size, char *value, int offset)
{
	if (!b || !b->b) assert(0);
	if (offset > size) assert(0);
	
	// Check if length of value will fit in the buffer
	if (size > (b->size - offset)) assert(0);
	memcpy(b->b + offset, value, size);
}

void mark_checkpoint_serialized_buffer(ser_buff_t *b)
{
	if (!b || !b->b) assert(0);
	b->checkpoint = b->next;
}

int get_serialized_buffer_checkpoint_offset(ser_buff_t *b)
{
	return (!b || !b->b) ? -1: b->checkpoint;
}

void serialize_buffer_skip(ser_buff_t *b, int skip_size)
{
	int temp = 0;
	if (!b || !b->b) assert(0);

	// check on both boundary conditions
	if (skip_size < 0) {
		// Check if it overshoots in negative direction
		temp = b->next - skip_size;
		if (temp < 0) b->next = 0;
		else b->next = temp;
		return;
	}

	if ((b->next + skip_size) > b->size) {
		b->b = realloc(b->b, (b->size + b->next + skip_size));
		b->next += skip_size;
		return;
	}

	b->next += skip_size;
}

void free_serialize_buffer(ser_buff_t *b)
{
	if (!b || !b->b) assert(0);
	free(b->b);
	free(b);
}
