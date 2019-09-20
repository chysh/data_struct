#include "seq_queue.h"
struct seq_queue *init_seq_queue()
{
	struct seq_queue *queue = (struct seq_queue *)malloc(sizeof(struct seq_queue));
	if(queue == NULL){
		return NULL;
	}
	queue->head = 0;
	queue->tail = 0;
	return queue;
}

bool push_seq_queue(struct seq_queue *queue, void *data)
{
	if(queue == NULL || data == NULL)
		return false;
	if(queue->tail == MAXSIZE){
		if(queue->head == 0)
			return false;
		for(int i = queue->head; i < queue->tail; ++i)
			queue->data[i-queue->head] = queue->data[i];
		queue->tail -= queue->head;
		queue->head = 0;
	}
	queue->data[queue->tail] = data;
	queue->tail++;
	return true;
}

bool pop_seq_queue(struct seq_queue *queue)
{
	if(queue == NULL)
		return false;
	if(queue->head == queue->tail)
		return false;
	queue->head++;
	return true;
}

void *get_head_seq_queue(struct seq_queue *queue)
{
	if(queue == NULL)
		return NULL;
	if(queue->head == queue->tail)
		return NULL;
	return queue->data[queue->head];
}

void *get_tail_seq_queue(struct seq_queue *queue)
{
	if(queue == NULL)
		return NULL;
	if(queue->head == queue->tail)
		return NULL;
	return queue->data[queue->tail-1];
}

int get_length_seq_queue(struct seq_queue *queue)
{
	if(queue == NULL)
		return -1;
	return queue->tail-queue->head;
}

void destroy_seq_queue(struct seq_queue *queue)
{
	if(queue == NULL)
		return;
	free(queue);
}







