#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int sort(int n, int k,int time){

	int* c = (int*)malloc(n*sizeof(int*));
	memset(c, 0, sizeof(c));
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	int** arr = (int**)malloc(n*sizeof(int*));
	for(int i = 0; i < n; i++)
		arr[i] = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++)
		memset(arr[i], 0, sizeof(arr[i]));

	int* a = (int*)malloc(n*sizeof(int*));
	memset(a, 0, sizeof(a));

	int* b = (int*)malloc(n*sizeof(int*));
	memset(b, 0, sizeof(b));
	
	for(int i = 0; i < k; i++){
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		arr[a[i]][b[i]] = 1;
	}
	free(a);
	free(b);

	int j = 0, l = n, temp;
	int* no = (int*)malloc(n*sizeof(int));
	memset(no, 0, sizeof(no));
	int* s= (int*)malloc(n*sizeof(int));
	memset(s, 0, sizeof(s));

	for(int i = 0; i < n; i++)
		no[i] = i;
	while(l != 0){
	temp = l;
	l = 0;
	for(int i = 0; i < temp; i++){
		int sum =0;
		for(int r = 0; r < n; r++)
			sum += arr[r][no[i]];
		
		 if(sum == 0){
                s[j] = no[i];
                j++;
                }
                else{
                no[l] = no[i];
                l++;
                }

	}
	for(int r = 0; r < j; r++){
                for(int e = 0; e < n; e++)
                	arr[s[r]][e] = 0;
	}
	
	int min = c[s[0]];
        for(int d = 0; d < j; d++){
                if(c[s[d]] < min)
                        min = c[s[d]];
        }
	time += min;
	for(int i = 0; i < j; i++)
		s[i] = 0;
	j = 0;
	}
return time;
free(c);
int y = 0;
	for(y = 0; y < n; y++);
		free(arr[y]);

free(arr);
free(no);
free(s);
free(s);
}

int main(){
	int n, k, time = 0;

	scanf("%d %d", &n, &k);
	int result = sort(n, k, time);
	for(int i = 0; i < n; i++);
	printf("%d\n", result);
}
	
