#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//查找第一个值等于给定值的元素
int binary_search_variant1(int *arr, int size, int value)
{
	int low = 0;
	int high = size -1;
	int mid;

	while(low <= high){
		mid = low + ((high-low) >> 1);
		if(arr[mid] > value){
			high = mid - 1;
		}else if(arr[mid] < value){
			low = mid + 1;
		}else{
			if(mid == 0 || arr[mid - 1] != value)
				return mid;
			else 
				high = mid - 1;
		}
	}
	return -1;
}

//查找最后一个值等于给定值的元素
int binary_search_variant2(int *arr, int size, int value)
{
	int low = 0;
	int high = size -1;
	int mid;

	while(low <= high){
		mid = low + ((high-low) >> 1);
		if(arr[mid] > value){
			high = mid - 1;
		}else if(arr[mid] < value){
			low = mid + 1;
		}else{
			if(mid == size-1 || arr[mid + 1] != value)
				return mid;
			else 
				low = mid + 1;
		}
	}
	return -1;
}

//查找第一个大于等于给定值的元素
int binary_search_variant3(int *arr, int size, int value)
{
	int low = 0;
	int high = size -1;
	int mid;

	while(low <= high){
		mid = low + ((high-low) >> 1);
		if(arr[mid] >= value){
			if(mid == 0 || arr[mid-1] < value)
				return mid;
			else
				high = mid -1;
		}else
			low = mid + 1;
	}
	return -1;
}

//查找最后一个小于等于给定值的元素
int binary_search_variant4(int *arr, int size, int value)
{
	int low = 0;
	int high = size -1;
	int mid;

	while(low <= high){
		mid = low + ((high-low) >> 1);
		if(arr[mid] > value){
			high = mid - 1;
		}else{
			if(mid == size - 1 || arr[mid + 1] > value)
				return mid;
			else
				low = mid + 1;
		}
	}
	return -1;
}

void binary_search_test()
{
	int arr[10] = {3,5,7,8,8,8,10,10,26,30};
	int idx;
	//idx = binary_search_variant1(arr, 10, 8);
	//idx = binary_search_variant2(arr, 10, 8);
	//idx = binary_search_variant3(arr, 10, 10);
	idx = binary_search_variant4(arr, 10, 10);
	if(idx != -1)
		printf("find 8 in %d\n", idx);
	else
		printf("8 not in arr\n");
}

int main()
{
	binary_search_test();
	return 0;
}
