数据结构与算法的学习
==
1.关于队列

      基于数组的队列，链表的队列，循环队列。一些高级的队列结构如阻塞队列，并发队列其底层还是队列的基本结构，
      只不过是在之上附加了其他功能。阻塞队列就是入队、出队操作可以阻塞。当队列为空时从对头取数时会阻塞，
      直到队列中有数据之后才返回；当队列为满时的插入操作就会阻塞，直到队列中有空闲位置时插入数据之后在返回。
      并发队列就是队列的操作多线程安全，基于数组的循环队列，利用CAS原子操作，可以实现非常高效的并发队列。

2.散列表/哈希表（Hash Table）
      
      散列思想：
      散列表用的是数组支持下标随机访问的数据特性，所以散列表其实就是一种数组的扩展，有数组演化而来，
      可以说，没有数组就没有散列表。
![image](https://github.com/chysh/data_struct/blob/master/images/hash.jpg)
      
      散列表用的就是数组支持按照下标随机访问的时候，时间复杂度是 O(1) 的特性。我们通过散列函数把元素的键值映射为下标，
      然后将数据存储在数组中对应下标的位置。当我们按照键值查询元素时，我们用同样的散列函数，将键值转化数组下标，
      从对应的数组下标的位置取数据。
      
      散列函数：顾名思义是一个函数，记作 hash(key),key代表元素的键值，hash(key)的值就是经过散列函数计算得到的散列值。
      散列函数设计的基本要求：
            1.散列函数计算得到的散列值是非负整数。
            2.如果key1 == key2，那么hash(key1) == hash(key2).
            3.如果key1 != key2，那么hash(key1) != hash(key2).
            其中第三点，在真实的环境中，要找到一个不同的key得到不同的散列值的散列函数，几乎是不可能的，即使是业界著名的
            MD5，SHA，CRC等哈希算法也无法避免这种散列冲突，而且数组的空间有限，也会加大这种散列冲突的概率。
            
      散列冲突：
         再好的散列函数也无法避免散列冲突。那究竟该如何解决散列冲突问题呢？我们常用的散列冲突解决方法有两类，
         开放寻址法（open addressing）和链表法（chaining）。
         1.开放寻址法
            开放寻址法的核心思想是，如果出现了散列冲突，我们就重新探测一个空闲位置，将其插入。那如何重新探测新的位置呢？
            一个比较简单的探测方法，线性探测（Linear Probing）：
            1.当我们往散列表中插入数据时，如果某个数据经过散列函数散列之后，存储位置已经被占用了，我们就从当前位置开始，
            依次往后查找，看是否有空闲位置，直到找到为止。
            如下图（黄色的色块表示空闲位置，橙色的色块表示已经存储了数据。）
![image](https://github.com/chysh/data_struct/blob/master/images/xianxingtance.jpg)

            2.在散列表中查找元素的过程有点儿类似插入过程。我们通过散列函数求出要查找元素的键值对应的散列值，然后比较数组
            中下标为散列值的元素和要查找的元素。如果相等，则说明就是我们要找的元素；否则就顺序往后依次查找。如果遍历到数
            组中的空闲位置，还没有找到，就说明要查找的元素并没有在散列表中。如图：
![image](https://github.com/chysh/data_struct/blob/master/images/xianxingtance1.jpg)

            散列表跟数组一样，不仅支持插入、查找操作，还支持删除操作。对于使用线性探测法解决冲突的散列表，删除操作稍微有些
            特别。不能单纯地把要删除的元素设置为空。因为在查找的时候，一旦我们通过线性探测方法，找到一个空闲位置，我们就可
            以认定散列表中不存在这个数据。但是，如果这个空闲位置是我们后来删除的，就会导致原来的查找算法失效。本来存在的数
            据，会被认定为不存在。这个问题如何解决呢？我们可以将删除的元素特殊标记为 deleted。当线性探测查找的时候，遇到
            标记为 deleted 的空间，并不是停下来，而是继续往下探测。
![image](https://github.com/chysh/data_struct/blob/master/images/xianxingtance2.jpg)
            
           线性探测法其实存在很大问题。当散列表中插入的数据越来越多时，散列冲突发生的可能性就会越来越大，空闲位置会越来越少，
           线性探测的时间就会越来越久。极端情况下，我们可能需要探测整个散列表，所以最坏情况下的时间复杂度为 O(n)。同理，
           在删除和查找时，也有可能会线性探测整张散列表，才能找到要查找或者删除的数据。
           
           对于开放寻址冲突解决方法，除了线性探测方法之外，还有另外两种比较经典的探测方法，二次探测（Quadratic probing）和
           双重散列（Double hashing）。
           
           所谓二次探测，跟线性探测很像，线性探测每次探测的步长是 1，那它探测的下标序列就是 hash(key)+0，hash(key)+1，
           hash(key)+2……而二次探测探测的步长就变成了原来的“二次方”，也就是说，它探测的下标序列就hash(key)+0，
           hash(key)+1^2，hash(key)+2^2……
           
           所谓双重散列，意思就是不仅要使用一个散列函数。我们使用一组散列函数 hash1(key)，hash2(key)，hash3(key)……
           我们先用第一个散列函数，如果计算得到的存储位置已经被占用，再用第二个散列函数，依次类推，直到找到空闲的存储位置。

           不管采用哪种探测方法，当散列表中空闲位置不多的时候，散列冲突的概率就会大大提高。为了尽可能保证散列表的操作效率，
           一般情况下，我们会尽可能保证散列表中有一定比例的空闲槽位。我们用装载因子（load factor）来表示空位的多少。

           装载因子的计算公式是：
                  散列表的装载因子 = 填入表中的元素个数 / 散列表的长度
                  
           装载因子越大，说明空闲位置越少，冲突越多，散列表的性能会下降.

         2.链表法
            链表法是一种更加常用的散列冲突解决办法，相比开放寻址法，它要简单很多。我们来看这个图，在散列表中，
            每个“桶（bucket）”或者“槽（slot）”会对应一条链表，所有散列值相同的元素我们都放到相同槽位对应的链表中。
![image](https://github.com/chysh/data_struct/blob/master/images/lianbiaofa.jpg)
      
            当插入的时候，我们只需要通过散列函数计算出对应的散列槽位，将其插入到对应链表中即可，所以插入的
            时间复杂度是 O(1)。当查找、删除一个元素时，我们同样通过散列函数计算出对应的槽，然后遍历链表查找或者删除。
            那查找或删除操作的时间复杂度是多少呢?
            
            实际上，这两个操作的时间复杂度跟链表的长度 k 成正比，也就是 O(k)。对于散列比较均匀的散列函数来说，理论上讲，
            k=n/m，其中 n 表示散列中数据的个数，m 表示散列表中“槽”的个数。



            
 
