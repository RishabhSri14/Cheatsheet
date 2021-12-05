# Trees
Tree represents the nodes connected by edges.
>> Important Terms  :

Path − Path refers to the sequence of nodes along the edges of a tree.

Root − The node at the top of the tree is called root. There is only one root per tree and one path from the root node to any node.

Parent − Any node except the root node has one edge upward to a node called parent.

Child − The node below a given node connected by its edge downward is called its child node.

Leaf − The node which does not have any child node is called the leaf node.

Subtree − Subtree represents the descendants of a node.

Visiting − Visiting refers to checking the value of a node when control is on the node.

Traversing − Traversing means passing through nodes in a specific order.

Levels − Level of a node represents the generation of a node. If the root node is at level 0, then its next child node is at level 1, its grandchild is at level 2, and so on.

keys − Key represents a value of a node based on which a search operation is to be carried out for a node.

>> Type of binary tree
>>- Balanced binary tree
    A balanced binary tree, also referred to as a height-balanced binary tree, is defined as a binary tree in which the height of the left and right subtree of any node differ by not more than 1.  
>> - Full binary tree  
    A tree where every node (except for the leaves) has 2 branches is called a full binary tree. Full binary trees are sometimes also called proper or plane binary trees.
>>  - Complete Binary Tree(Heap property):  
    A Binary Tree is a Complete Binary Tree if all the levels are completely filled except possibly the last level and the last level has all keys as left as possible 
>>  - Perfect Binary Tree  
    A Binary tree is a Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same level.

>> Different algos of Trees
- General Tree  
>If no constraint is placed on the tree’s hierarchy, a tree is called a general tree. Every node may have infinite numbers of children in General Tree. The general tree is the super-set of all other trees.  

- Binary Tree  
> The binary tree is the kind of tree in which most two children can be found for each parent. The kids are known as the left kid and right kid.

- Binary Search Tree
> Binary Search Tree (BST) is a binary tree extension with several optional restrictions. The left child value of a node should in BST be less than or equal to the parent value, and the right child value should always be greater than or equal to the parent’s value.
>> Mainly used for searching 

- AVL Tree (Self balancing BST)
> A balancing factor is allocated for each node in the AVL tree, based on whether the tree is balanced or not. The height of the node kids is at most 1. AVL vine. In the AVL tree, the correct balance factor is 1, 0 and -1. If the tree has a new node, it will be rotated to ensure that it is balanced.Common operations such as viewing, insertion, and removal take O(log n) time in the AVL tree.

- Red-Black Tree
>Another kind of auto-balancing tree is red-black. According to the red-black tree’s properties, the red-black name is given because the Red-black tree has either red or Black painted on each node. It maintains the balance of the forest. Even though this tree is not fully balanced, the searching operation only takes O (log n) time. When the new nodes are added in Red-Black Tree, nodes will be rotated to maintain the Red-Black Tree’s properties.


Click <a href ="code.c">here</a> to access code for traversal in binary tree
