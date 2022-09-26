#include<stdio.h>
#include<stdlib.h>

int main()
{

	int height=3;
	int width=4;
	
	//scanf("%d %d", &height, &width);
	int **arr;
	arr = (int**)malloc(sizeof(int*)*height);
	for(int i=0; i<height; i++){
		arr[i] = (int*)malloc(sizeof(int) * width);
	}
	printf("%ld\n", sizeof(arr));
	int col = sizeof(arr[0])/sizeof(int);
	int row = sizeof(arr)/sizeof(arr[0]);
	printf("row: %d col: %d\n", row, col);

	for(int j=0; j<height; j++){
		for(int k=0; k<width; k++){
			printf("%d ", arr[j][k]);
		}
		printf("\n");
	}
	
	int x =1;
	for(int a=0; a<height; a++){
                for(int b=0; b<width; b++){
                        arr[a][b] = x;
			x++;
                }
                
        }

	for(int c=0; c<height; c++){
                for(int d=0; d<width; d++){
                        printf("%d ", arr[c][d]);
                }
                printf("\n");
        }


	for(int e=0; e<height; e++){
		free(arr[e]);
	}
	free(arr);
}
