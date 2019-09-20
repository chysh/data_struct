#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seq_queue.h"

struct person{
	char name[64];
	int age;
};

int main()
{
	//初始化队列
	struct seq_queue *queue = init_seq_queue();
	if(queue == NULL){
		printf("队列创建失败!\n");
		return 0;
	}
	//创建数据
	struct person p1 = { "aaa", 10 };
	struct person p2 = { "bbb", 20 };
	struct person p3 = { "ccc", 30 };
	struct person p4 = { "ddd", 40 };
	struct person p5 = { "eee", 50 };
	struct person p6 = { "fff", 60 };
	struct person p7 = { "ggg", 70 };
	//入队
	push_seq_queue(queue, (void*)&p1);
	push_seq_queue(queue, (void*)&p2);
	push_seq_queue(queue, (void*)&p3);
	push_seq_queue(queue, (void*)&p4);
	push_seq_queue(queue, (void*)&p5);
	push_seq_queue(queue, (void*)&p6);
	push_seq_queue(queue, (void*)&p7);
	//打印队头, 队尾元素
	struct person *head = (struct person *)get_head_seq_queue(queue);
	printf("Name:%s Age:%d\n",head->name,head->age);
	struct person *tail = (struct person *)get_tail_seq_queue(queue);
	printf("Name:%s Age:%d\n", tail->name, tail->age);
	printf("----------------------------\n");
	//输出
	/*while (get_length_seq_queue(queue) > 0){
		//获得队头元素
		head = (struct person*)get_head_seq_queue(queue);
		printf("Name:%s Age:%d\n", head->name, head->age);
		//出队操作
		pop_seq_queue(queue);
	}*/
	pop_seq_queue(queue);
	push_seq_queue(queue, (void*)&p7);

	int num = get_length_seq_queue(queue);
	printf("========== num = %d ==========\n", num);

	while (get_length_seq_queue(queue) > 0){
		//获得队头元素
		head = (struct person*)get_head_seq_queue(queue);
		printf("Name:%s Age:%d\n", head->name, head->age);
		//出队操作
		pop_seq_queue(queue);
	}
	//销毁队列
	destroy_seq_queue(queue);
	return 0;
}
