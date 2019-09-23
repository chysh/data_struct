#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_queue.h"


struct person{
	char name[64];
	int age;
};


int main()
{
	struct cir_queue *queue = init_cir_queue();
	if(queue == NULL)
		return -1;
	struct person p[] = {
		{"aaa", 10},
		{"bbb", 20},
		{"ccc", 30},
		{"ddd", 40},
		{"eee", 50},
		{"fff", 60},
		{"ggg", 70},
		{"hhh", 80},
	};

	for(int i = 0; i < 8; i++){
		push_cir_queue(queue, (void *)&p[i]);
	}
	
	struct person *p1 = NULL;
	while(length_cir_queue(queue)){
		p1 = (struct person *)head_cir_queue(queue);
		printf("name = %s, age = %d\n", p1->name, p1->age);
		p1 = (struct person *)tail_cir_queue(queue);
		printf("name = %s, age = %d\n", p1->name, p1->age);
		pop_cir_queue(queue, (void **)&p1);
		printf("name = %s, age = %d\n", p1->name, p1->age);
		printf("-------------------------------------\n");
	}

	destroy_cir_queue(queue);

	return 0;
}





