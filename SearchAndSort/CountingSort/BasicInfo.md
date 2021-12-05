# Counting Sort

Counting sort assumes that each of the n input elements is an integer in the range 0 to k, for some integer k. When k = O(n), the sort runs in O(n) time.

>> Basic Algo  
- Counting the number of objects having distinct key values (kind of hashing).  
- Then doing some arithmetic to calculate the position of each object in the output sequence.

Example:
<pre>
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in 
the output sequence.

  3) Rotate the array clockwise for one time.
   Index:     0 1 2 3 4 5 6 7 8 9
   Count:     0 0 2 4 4 5 6 6 7 7
  
  4) Output each object from the input sequence followed by 
  increasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 0.
  Put data 1 at index 0 in output. Increase count by 1 to place next data 1 at an index 1 greater than this index.
</pre>

Click <a href="code.c">here</a> to access the code.
