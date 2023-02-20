#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	int* arr = (int*)malloc(n*sizeof(int));
	printf("Enter the elements: ");
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	int m = n/2;
	int des_sum = sum/2;
	int curr = 0;
	for(int i=0;i<n-1;i++){
		curr = arr[i];
		int* seg = (int*)calloc(m,sizeof(int));
		for(int j=i+1;j<n;j++){
			curr += arr[j];
			seg[--m] = arr[j];
			if(m == 0){
				m = n/2;
			}
			if(curr > des_sum){
				curr = arr[i];
				continue;
			}
			if(curr == des_sum){
				for(int k = 0;i<m;k++){
					printf("%d",seg[k]);
				}
			}
		}
	}



	return 0;
}
