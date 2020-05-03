#ifndef __SERIALIZE__
#define __SERIALIZE__

#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct serialized_buffer {
	#define SERIALIZE_BUFFER_DEFAULT_SIZE 521
	void *b;
	int size;
	int next;
	int checkpoint;
}ser_buff_t;

// Init functions
/* Initialize the serialize buffer with default size = SERIALIZE_BUFFER_DEFAULT_SIZE */
void init_serialized_buffer(ser_buff_t **);

/* Must Initialize the serialize buffer with size specified as 2nd argument */
void init_serialized_buffer_of_defined_size(ser_buff_t **, int);

/* API copies 'size' bytes of data into serialized buffer. if the buffer do not have space for 'size' bytes of data, 
then expand the buffer to twice its current size while preserving the content already copied */
void serialize_string(ser_buff_t *, char *, int);

/*Return 0 if empty, else -1 */
int is_serialized_buffer_empty(ser_buff_t *);

/*
  1st argument - pointer to src memory into which data should be copied from serialized buffer.
  2nd argument - pointer to serialized buffer
  3rd argument - no of bytes to be copied.

 starting position of bytes to be copied from serialize buffer should be b->next,
 b->next should be incremented by val_size units as per the number of bytes copied.
 */
void de_serialize_string(char *, ser_buff_t *, int);

/*
 The API should be used to copy the src data represented by 'value' 
of 'size' bytes into serialized buffer b at any position (represented by offset) 
into the serialized buffer.

e,g the call copies the string "csepracticals.com" in a serialized buffer 
at byte location 32th from the beginning of serialize buffer.
The API is not supposed to update b->next or b->size variables of the 
serialize buffer.
 */
void copy_in_serialized_buffer_by_offset(ser_buff_t *, int, char *, int);

/*
 Sometimes, the program needs to remember certain locations in the serialized buffer 
so that in future it can write into those positions into serializing buffer, 
while b->next pointer of the serialize buffer has already moved ahead due to 
successive data copy.

Below API must save b->next into b->checkpoint
 */
void mark_checkpoint_serialize_buffer(ser_buff_t *);

/* API must return the value of b->checkpoint */
int get_serialize_buffer_checkpoint_offset(ser_buff_t *);

/*
  Sometimes. one have to jump a certain number of bytes in the serialize buffer 
- forward or backward without writing any content into it.
  if skip_size 0s +ve -jump the b->next forward else backward.

 check the boundary condition, don't overshoot the buffer in either direction.
if there is no enough space while jumping the serialize buffer in fwd direction, 
feel free to double the size of serialize buffer to take a jump.
 */
void serialize_buffer_skip(ser_buff_t *, int);

/* free the serialize buffer using below API */
void free_serialize_buffer(ser_buff_t *);
#endif
