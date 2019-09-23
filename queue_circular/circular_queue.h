#ifndef __CIRCULAR_H_
#define __CIRCULAR_H_

#include <stdlib.h>

#define MAXSIZE 1024

struct cir_queue{
	void *data[MAXSIZE];
	int head;
	int tail;
	int size;
};

//初始化
struct cir_queue *init_cir_queue();
//入队
int push_cir_queue(struct cir_queue *queue, void *data);
//出队
int pop_cir_queue(struct cir_queue *queue, void **data);
//获取队头元素
void *head_cir_queue(struct cir_queue *queue);
//获取队尾元素
void *tail_cir_queue(struct cir_queue *queue);
//队列长度
int length_cir_queue(struct cir_queue *queue);
//销毁队列
void destroy_cir_queue(struct cir_queue *queue);

#endif


