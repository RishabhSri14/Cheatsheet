# Binary Search
>>Search a sorted array by repeatedly dividing the search interval in half. 
>>*Basic Algo*
- Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half. 
- Repeatedly check until the value is found or the interval is empty.

>> Time Complexity:O(logn)

>> Click <a href="code.c">here</a> to access the code.

