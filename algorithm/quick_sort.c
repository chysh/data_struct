#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int *arr, int size)
{
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *arr, int p, int r)
{
	int i,j;
	i = j = p;
	
	for(; j < r; j++){
		if(arr[j] < arr[r]){
			if(i != j)
				swap(arr+i,arr+j);
			i++;
		}
	}
	swap(arr+i, arr+r);
	return i;
}

void _quick_sort(int *arr, int p, int r)
{
	int q;

	if(p >= r)
		return;
	q = partition(arr, p, r);
	_quick_sort(arr, p, q-1);
	_quick_sort(arr, q+1, r);
}

void quick_sort(int *arr, int size)
{
	_quick_sort(arr, 0, size-1);
}

void quick_sort_test()
{
	int arr[] = {5,8,3,9,0,6,2,7,1,4};
	int len = 10;
	print(arr, len);
	quick_sort(arr, len);
	print(arr, len);
}

int main()
{
	quick_sort_test();
	return 0;
}







