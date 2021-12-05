# Binary Search Trees
The binary tree is the kind of tree in which most two children can be found for each parent. The kids are known as the left kid and right kid.

The basic operations required by any search data structures are:SEARCH , MINIMUM , MAXIMUM , PREDECESSOR , SUCCESSOR , INSERT , and
DELETE .

>>Binary-search-tree property:  
Let x be a node in a binary search tree. If y is a node in the left subtree of x, then y:key <= x:key. If y is a node in the right subtree of x, then y:key >= x:key.

Similar to general trees here also there are preorder, postorder and levelorder walks. each taking O(n) time.  

- Basic Searching is performed as:
<pre>TREE -SEARCH (x, k)
if x == NIL or k == x:key
    return x
if k < x:key
    return T REE -S EARCH .x:left; k/
else 
    return T REE -S EARCH .x:right; k/
</pre>

- Basic insert operation is reffered as:
<pre>
TREE -INSERT(T,z)
1 y = NIL
2 x =T.root
3 while x != NIL
4   y=x
5   if z.key < x.key
6   x=x.left
7   else x= x.right
8 z.p = y
9 if y == NIL
10 T.root = z// tree T was empty
11 elseif z.key < y.key
12   y.left = z
13 else y.right = z
</pre>

- Getting minimum/maximum element is same as getting leftmost/rightmost element
Click <a href ="code.c">here</a> to access code for operation in binary search tree
