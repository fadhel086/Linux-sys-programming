#include <stdlib.h>

/*Step 5 : */

/*Return 0 if ds1 and ds2 are clones,
 * else return -1*/
int
diff (void *root1,    /*pointer to Data structure 1*/
      void *root2,    /*pointer to data structure 2*/
      void *(*iterator(void *)), /*Iterator function callback*/
      int comparator(void *, void *),
      void *(*get_app_data(void *))){  /*Comparison function callback*/

      /*Write your code here*/
      void *node1 = root1;
      void *node2 = root2;

	if (!node1 || !node2)
		return -1;

	while (node1 && node2) {
		// Get the nodes and compare 
		if ( comparator(get_app_data(node1), get_app_data(node2)) == 0){
			// If data is equal, then move onto next node;
			node1 = iterator(node1);
			node2 = iterator(node2);
		} else {
			return -1;
		}	        
	}

	// Have both the nodes reached the end of DS at the same time,
	return (node1 == node2) ? 0 : -1;
}
