#include <stdlib.h>
#include "list_queue.h"

struct list_queue *init_list_queue()
{
	struct list_queue *queue = NULL; 
	queue = (struct list_queue *)malloc(sizeof(struct list_queue));
	if(queue == NULL)
		return NULL;

	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

int push_list_queue(struct list_queue *queue, struct queue_node *data)
{
	if(queue == NULL)
		return -1;
	if(data == NULL)
		return -1;
	
	if(queue->head == NULL)
		queue->head = data;
	else
		queue->tail->next = data;

	queue->tail = data;
	queue->size++;
	
	return 0;
}

int pop_list_queue(struct list_queue *queue, struct queue_node **data)
{
	if(queue == NULL)
		return -1;
	if(queue->size == 0)
		return -1;
	*data = queue->head;
	queue->head = queue->head->next;
	queue->size--;
	
	if(queue->head == NULL)
		queue->tail == NULL;

	return 0;
}

struct queue_node *head_list_queue(struct list_queue *queue)
{
	if(queue == NULL || queue->size == 0)
		return NULL;
	return queue->head;
}

struct queue_node *tail_list_queue(struct list_queue *queue)
{
	if(queue == NULL || queue->size == 0)
		return NULL;
	return queue->tail;
}

int size_list_queue(struct list_queue *queue)
{
	if(queue == NULL)
		return -1;
	return queue->size;
}

void traverse_list_queue(struct list_queue *queue, print_data pfun)
{
	if(queue == NULL)
		return;

	struct queue_node *ptmp;
	ptmp = queue->head;
	while(ptmp != NULL)
	{
		pfun(ptmp);
		ptmp = ptmp->next;
	}
	return;
}

void destroy_list_queue(struct list_queue *queue)
{
	if(queue == NULL)
		return;
	free(queue);
}

















