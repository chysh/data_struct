用普通数组实现的队列当tail==n（n尾数组元素个数）时【见代码《队列的顺序存储》】，会有数据搬移操作，这样入队操作的性能会受到影响，所以通过循环队列可以解决这个问题。

队列中（head==tail）代表队列为空
（tail+1）% n == head 代表队列为满：考虑tail == n-1时，tail+1 应该是0, 所以 tail+1 == n，n % n == 0;当tail+1< n 时，
则（tail +1）% n == tail+1.

tail+1最后一个位置不保存数据，为了区分队空或队满。
