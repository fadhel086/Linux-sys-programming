/*
  In the program below, provide the implementation of Macro ITERATE_ARRAY_BEGIN. 
  This macro must facilitate the developer to iterate over arrays/
  The Macro accepts 5 arguments:
      arrptr      - base pointer to array
      array_size
      start_index - index of the array where array scan need to start from
      scansize    - No.of elements of the array to be scanned, can be more than size of the array.
                    Wrap it again from beginning of the array if scan reaches the end of the array. 
      out_index   - This is the index value which macro should set.
 */
#include <stdio.h>
#include <stdlib.h>

#define ITERATE_ARRAY_BEGIN(arrptr, array_size, start_index, scansize, out_index)	\
	{										\
		unsigned int *ptr = arrptr + start_index;				\
		unsigned int _scan_cnt = 0;						\
		for (;_scan_cnt < scansize; ++ptr, ++_scan_cnt)				\
		{									\
			if (ptr == (arrptr + array_size) )				\
				ptr = arrptr;						\
			out_index = ptr - arrptr;					\


#define ITERATE_ARRAY_END }}


int main(int argc, char **argv) {

	unsigned int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	unsigned int i;

	ITERATE_ARRAY_BEGIN(arr, 10, 5, 10 , i) {
		printf("arr[%u] = %u\n", i, arr[i]);
	} ITERATE_ARRAY_END;

	return 0;
}
