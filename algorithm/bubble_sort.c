#include <stdio.h>

void bubble_sort(int arr[], int len)
{
	int i,j;
	int flag = 0;
	for(i = 0; i < len-1 && flag == 0; i++){
		flag = 1;
		for(j = 0; j < len-1-i; j++){
			if(arr[j] > arr[j+1]){
				flag = 0;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = {6,3,7,2,9,0,4,1};
	int len = 8;
	bubble_sort(arr, len);
	for(int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
