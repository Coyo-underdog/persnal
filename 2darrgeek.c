#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int r = 3, c = 4, i, j, count;

	int* arr[r];
	for(int i = 0; i < r; i++)
		arr[i] = (int*)malloc(c*sizeof(int));

	count = 0;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			arr[i][j] = ++count;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			printf("%d ", arr[i][j]);

	for (int i = 0; i < r; i++)
		free(arr[i]);

	return 0;
}
