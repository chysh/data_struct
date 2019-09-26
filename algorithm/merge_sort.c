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

void _merge(int *arr, int p, int q, int r)
{
	int i,j,k;

	int *tmp = (int *)malloc((r-p+1) * sizeof(int));
	if(tmp == NULL)
		return;

	for(i=p, j=q+1, k=0; i<=q && j<=r;){
		if(arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}

	if(i == q+1){
		for(; j <= r;)
			tmp[k++] = arr[j++];
	}else{
		for(; i <= q;)
			tmp[k++] = arr[i++];
	}

	memcpy(arr+p, tmp, (r-p+1)*sizeof(int));
	free(tmp);
	return;
}

void _merge_sort(int *arr, int p, int r)
{
	int q;

	if(p >= r)
		return;
	
	q = (p+r) / 2;
	_merge_sort(arr, p, q);
	_merge_sort(arr, q+1, r);
	_merge(arr, p, q, r);
}

void merge_sort(int *arr, int size)
{
	_merge_sort(arr, 0, size-1);
}

int main()
{
	int arr[] = {7,3,16,2,8,0,5,4,4,1};
	int len = 10;
	print(arr, len);
	merge_sort(arr, len);
	print(arr, len);
	return 0;
}








