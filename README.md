数据结构与算法的学习
==
1.##关于队列
  基于数组的队列，链表的队列，循环队列。一些高级的队列结构如阻塞队列，并发队列其底层还是队列的基本结构，只不过是在之上附加了其他功能。
  阻塞队列就是入队、出队操作可以阻塞。当队列为空时从对头取数时会阻塞，直到队列中有数据之后才返回；当队列为满时的插入操作就会阻塞，
  直到队列中有空闲位置时  插入数据之后在返回。
  并发队列就是队列的操作多线程安全，基于数组的循环队列，利用CAS原子操作，可以实现非常高效的并发队列。
