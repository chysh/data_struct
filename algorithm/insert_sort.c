#include <stdio.h>

void insert_sort(int arr[], int len)
{
	int i,j;
	for(i = i; i < len; i++){
		j = i -1;
		int temp = arr[i];
		for(; j >= 0 && temp < arr[j]; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = temp;
	}
}

int main()
{
	int arr[] = {6,3,7,1,2,9,0,8};
	int len = 8;
	insert_sort(arr, len);
	for(int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
