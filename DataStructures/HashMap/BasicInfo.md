# Hashing
Hashing is a process of converting an object(of any data type) into integer form by using the method GetHash().  

It is used basically for three functions:  
- INSERT//O(1)
- SEARCH//O(1)
- DELETE//O(1)

>>Hah Table  
With direct addressing, an element with key k is stored in slot k. With hashing,
this element is stored in slot h(k); that is, we use a hash function h to compute the
slot from the key k. Here, h maps the universe U of keys into the slots of a hash
table T.

HashTables are implemented basically in three form:
- Direct Chaining
- Seperate Chaining 
- Linear Probing
- Quadratic Probing



Click <a href="code.c">here</a> to viewstring hashing and integer hashing for seperate chaoning, linear probing and quadratic probing 
