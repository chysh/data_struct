#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_queue.h"

struct person{
	struct queue_node *node;
	char name[64];
	int age;
};

void print_queue_node(struct queue_node *queue_node)
{
	struct person *pnode = (struct person *)queue_node;
	printf("name = %s, age = %d\n", pnode->name, pnode->age);
	return;
}

int main()
{
	struct list_queue *queue = init_list_queue();
	if(queue == NULL)
		return -1;
	struct person p[] = {
		{NULL, "aaa", 10},
		{NULL, "bbb", 20},
		{NULL, "ccc", 30},
		{NULL, "ddd", 40},
		{NULL, "eee", 50},
		{NULL, "fff", 60},
	};

	for(int i = 0; i < 6; i++){
		push_list_queue(queue, (struct queue_node *)&p[i]);
	}
	
	struct person *p1 = (struct person *)head_list_queue(queue);
	printf("head:name = %s, age = %d\n", p1->name, p1->age);
	p1 = (struct person *)tail_list_queue(queue);
	printf("tail:name = %s, age = %d\n", p1->name, p1->age);

	traverse_list_queue(queue, print_queue_node);
	
	printf("---------------------------------------------------\n");

	while(size_list_queue(queue)){
				
		p1 = (struct person *)head_list_queue(queue);
		printf("head:name = %s, age = %d\n", p1->name, p1->age);
		p1 = (struct person *)tail_list_queue(queue);
		printf("tail:name = %s, age = %d\n", p1->name, p1->age);
		printf("---------------------------------------------------\n");
		pop_list_queue(queue, (struct queue_node **)&p1);
		if(p1 == NULL){
			printf("NULL------NULL\n");
			continue;
		}
		printf("xpop:name = %s, age = %d\n", p1->name, p1->age);
		printf("===================================================\n");
	}

	printf("--------------------------0------------------------\n");
	traverse_list_queue(queue, print_queue_node);

	destroy_list_queue(queue);
	return 0;
}






