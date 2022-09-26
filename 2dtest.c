#include<stdio.h>
#include<stdlib.h>

int main()
{
	int height, width;
	int **arr;
	scanf("%d %d", &height, &width);
	arr = (int **)malloc(sizeof(int *) * height);
	arr[0] = (int *)malloc(sizeof(int) * width*height);
	for(int i=1; i<height; i++){
		arr[i] = arr[ i - 1 ];
	}
	for (int j =0; j<height; j++){
		for(int k=0; k<width; k++){
			printf("%d ", arr[j][k]);
		}
		printf("\n");
	}
	int col = sizeof(arr[0])/sizeof(int);
	int row = sizeof(arr)/sizeof(arr[0]);
	printf("row : %d col : %d \n", row, col);
	free(arr[0]);
	free(arr);
	return 0;
}
