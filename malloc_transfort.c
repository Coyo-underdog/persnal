#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned char *input_image;
	unsigned int bmp_image_size = 262144;

	if(alloc_pixels(input_image, bmp_image_size)==NULL)
		printf("\nPoint2: Memory allocated: %d bytes",_msize(input_image));
	else
		printf("\nPoint3: Memory not allocated");
	return 0;
}

signed char alloc_pixels(unsigned char *ptr, unsigned int size)
{
	signed char status = NO_ERROR;
	ptr = NULL;

	ptr = (unsigned char*)malloc(size);

	if(ptr==NULL)
	{
		status = ERROR;
		free(ptr):
		printf("\nERRoR: Memory allocation did not complete sucessfully!");
	}
	printf("\nPoint1: Memory allocated: %d bytes",_msize(ptr));

	return status;
}
