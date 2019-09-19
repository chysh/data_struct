#ifndef __SEQ_QUEUE_H
#define __SEQ_QUEUE_H

#include <stdlib.h>

#define MAXSIZE 6
#define bool char
#define true	1
#define false	0

struct seq_queue{
	void *data[MAXSIZE];
	int size;
	int head;
	int tail;
};

//初始化
struct seq_queue *init_seq_queue();
//入队
bool push_seq_queue(struct seq_queue *queue, void *data);
//出队
bool pop_seq_queue(struct seq_queue *queue);
//获取队头元素
void *get_head_seq_queue(struct seq_queue *queue);
//获取队尾元素
void *get_tail_seq_queue(struct seq_queue *queue);
//获取队列长度
int get_length_seq_queue(struct seq_queue *queue);
//销毁队列
void destroy_seq_queue(struct seq_queue *queue);

#endif

