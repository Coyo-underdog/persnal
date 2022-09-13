#include<stdio.h>
#include<string.h>

int scan(){
	int n,k;
	scanf("%d%d", &n, &k);
	int c[n];
	int order[n];
	int arr[n][n];
	int check[n];
	int column = 0;
	memset(arr, 0, sizeof(int));
	memset(order, 0, sizeof(int));
	for(int i = 0; i < n; i++) scanf("%d", c+i);
	int a[k], b[k];
	int j = 0;
	for(int id = 0; id < k; id++){
		scanf("%d%d", &a[id], &b[id]);
		a[id]--;
		b[id]--;
		arr[a[id]][b[id]]=1;
	}
}
int sort(int start){
	int check = 0;
	for(column = start; column < n; column++){
		int sum = 0;

		for(int row = 0; row < n; row++){
			sum += arr[row][column];
		}
		if(sum == 0){
		order[j] = column+1;
		j++;
		for(int l = 0; l < n; l++)
			arr[column][l] = 0;
		}
		else {
		if(check == 0){
		check = column;
		return check;
		}
		}
		
	
	}
 
}

		
	

}
	int main(){
		scan();
		return 0;
	}
