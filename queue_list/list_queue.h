#ifndef __LIST_QUEUE_H
#define __LIST_QUEUE_H

#include <stdlib.h>

struct queue_node{
	struct queue_node *next;
};

struct list_queue{
	int size;
	struct queue_node *head;
	struct queue_node *tail;
};

typedef void(*print_data)(struct queue_node *node);

//初始化
struct list_queue *init_list_queue();
//入队
int push_list_queue(struct list_queue *queue, struct queue_node *data);
//出队
int pop_list_queue(struct list_queue *queue, struct queue_node **data);
//获得队头元素
struct queue_node *head_list_queue(struct list_queue *queue);
//获得队尾元素
struct queue_node *tail_list_queue(struct list_queue *queue);
//队列大小
int size_list_queue(struct list_queue *queue);
//遍历队列
void traverse_list_queue(struct list_queue *queue, print_data pfun);
//销毁队列
void destroy_list_queue(struct list_queue *queue);

#endif
