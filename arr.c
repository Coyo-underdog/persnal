#include<stdio.h>
#include<stdlib.h>

int main()
{
	int width;
	scanf("%d", &width);
	int *arr;
	arr = (int*)malloc(sizeof(int) * width);
	for(int i = 0; i < width; i++)
	printf("%d ", arr[i]);
	return 0;
}
