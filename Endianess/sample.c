/*  Code to find if machine is little or Big endian */

#include <stdio.h>


int main() {
	
	unsigned short num = 1;
	unsigned char *val = (char *)&num;

	if (*val == 0)
		printf("Your machine is BigEndian. It's in Network byte order\n");
	else if(*val == 1)
		printf("Your machine is LittleEndian. It's in Host Byte order\n");
}


