# Priority Queue

>Priority Queue is an extension of queue with following properties.

- Every item has a priority associated with it.
- An element with high priority is dequeued before an element with low priority.
- If two elements have the same priority, they are served according to their order in the queue.
<pre>
struct item {
   int item;
   int priority;
}
</pre>
>> Basic Functions:
- insert(item, priority): Inserts an item with given priority.
- getHighestPriority(): Returns the highest priority item.
- deleteHighestPriority(): Removes the highest priority item.

>> Priority Queues can be implemented in many ways:
- Using Arrays:  
Insert: O(1)  
getHighestPriority(): O(n) //Linear search  
deleteHighestPriority(): O(n) //Linear search + shifting  

- Using Linked List:  
Insert: O(n)  
getHighestPriority(): O(n) //Linear search  
deleteHighestPriority(): O(n) //Linear search  

- Using Heaps:  
Insert: O(log n) [Binary]; O(1) [Fibonacci]  
getHighestPriority(): O(1) //Linear search  
deleteHighestPriority(): O(log n) //Linear search

Click <a href="code.cpp">here</a> to view priority queue using binary heap