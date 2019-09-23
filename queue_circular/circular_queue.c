#include "circular_queue.h"

struct cir_queue *init_cir_queue()
{
	struct cir_queue *queue = NULL; 
	queue = (struct cir_queue *)malloc(sizeof(struct cir_queue));
	if(queue == NULL)
		return NULL;
	queue->head = 0;
	queue->tail = 0;
	queue->size = 0;
	return queue;
}

int push_cir_queue(struct cir_queue *queue, void *data)
{
	if(queue == NULL || data == NULL)
		return -1;
	if((queue->tail+1) % MAXSIZE == queue->head)
		return -1;
	queue->data[queue->tail] = data;
	queue->tail = (queue->tail+1) % MAXSIZE;
	queue->size++;
	return 0;
}

int pop_cir_queue(struct cir_queue *queue, void **data)
{
	if(queue == NULL || queue->tail == queue->head)
		return -1;
	*data = queue->data[queue->head];
	queue->head = (queue->head+1) % MAXSIZE;
	queue->size--;
	return 0;
}

void *head_cir_queue(struct cir_queue *queue)
{
	if(queue == NULL || queue->head == queue->tail)
		return NULL;
	return queue->data[queue->head];
}

void *tail_cir_queue(struct cir_queue *queue)
{
	if(queue == NULL || queue->head == queue->tail)
		return NULL;
	return queue->data[queue->tail == 0 ? MAXSIZE : queue->tail-1];
}

int length_cir_queue(struct cir_queue *queue)
{
	if(queue == NULL)
		return -1;
	return queue->size;
}

void destroy_cir_queue(struct cir_queue *queue)
{
	if(queue == NULL)
		return;
	free(queue);
}













