#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int r, c, i, j, k,  count;
	scanf("%d %d", &r, &c);
	scanf("%d", &k);
	int a[k], b[k];

	int** arr = (int**)malloc(r*sizeof(int*));
	for (i = 0; i < r; i++)
		arr[i] = (int*)malloc(c * sizeof(int));
	
	
	
	for(j = 0; j < k; j++) {
		scanf("%d %d", &a[j], &b[j]);
		arr[a[j]][b[j]] = 1;
	}

	for(int row = 0; row < r; row++){
		for(int col = 0; col < c; col++)
			printf("%d ", arr[row][col]);
		printf("\n");
	}

	for(int i = 0; i < r; i++)
		free(arr[i]);

	free(arr);

	return 0;
}
	


