#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*bs)(int *arr, int size, int val);

int binary_serch_r(int *arr, int size, int val)
{
	int mid = size / 2;
	int idx;

	if(arr[mid] == val)
		return mid;

	if(!mid)
		return -1;

	if(arr[mid] < val){
		idx = binary_serch_r(arr + mid + 1, size-mid-1, val);
		if(idx != -1)
			idx += mid + 1;
	}else{
		idx = binary_serch_r(arr, mid, val);
	}

	return idx;
}

int binary_serch_i(int *arr, int size, int val)
{
	int low = 0, high = size-1, mid;

	while(low <= high){
		mid = (low + high) / 2;
		if(arr[mid] == val)
			return mid;
		
		if(arr[mid] < val)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

void iteration_test(bs binary_serch)
{
	int a[10] = {1, 4, 6, 8, 12, 17, 26, 28, 31, 36};
	int idx;
	idx = binary_serch(a, 10, 12);
	if(idx != -1)
		printf("find 12 at %d\n", idx);
	else
		printf("12 not in arr\n");
	
	idx = binary_serch(a, 10, 13);
	if(idx != -1)
		printf("find 13 at %d\n", idx);
	else
		printf("13 not in arr\n");
	
	idx = binary_serch(a, 10, 1);
	if(idx != -1)
		printf("find 1 at %d\n", idx);
	else
		printf("1 not in arr\n");
	
	idx = binary_serch(a, 10, 36);
	if(idx != -1)
		printf("find 36 at %d\n", idx);
	else
		printf("36 not in arr\n");
	
	idx = binary_serch(a, 10, 31);
	if(idx != -1)
		printf("find 31 at %d\n", idx);
	else
		printf("31 not in arr\n");
}

int main()
{
	printf("==== Test iteration version:\n");
	iteration_test(binary_serch_i);

	printf("==== Test recursive version:\n");
	iteration_test(binary_serch_r);
	return 0;
}
