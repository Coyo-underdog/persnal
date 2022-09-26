#include<stdio.h>
#include<stdlib.h> 

int main()
{
	int height;
	int width;
	int **arr;
	scanf("%d %d", &height, &width);
	arr = (int**)malloc(sizeof(int*)*height);
	for(int i=0; i<height; i++){
		arr[i] = (int*)malloc(sizeof(int)*width);
	}
	for(int j = 0; j <  height; j++){
		for(int k = 0; k < width; k++){
			printf("%d ", arr[j][k]);
		}
		printf("\n");
	}
	for(int i = 0; i<height; i++){
		free(arr[i]);
	}
	free(arr);
}
