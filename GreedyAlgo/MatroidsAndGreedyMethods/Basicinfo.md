# Matroids
A matroid is an ordered pair M =(S, I) satisfying the following conditions.
1. S is a ﬁnite set.
2. I is a nonempty family of subsets of S, called the independent subsets of S,
such that if B belongs to I and A is subset of B, then A belongs to I .   
We say that I is hereditary if it satisﬁes this property. Note that the empty set  is necessarily a member of I .
3. If A belongs to I , B belongs to I , and |A| < |B|, then there exists some element x belongs to B - A such that AU{x} belongs to I .   
We say that M satisﬁes the exchange property.


>>Example of matroids:  
Consider the graphic matroid M=(S, I)
deﬁned in terms of a given undirected graph G = (V, E) as follows:
>>- The set S is deﬁned to be E, the set of edges of G.
>>- If A is a subset of E, then A belongs to I if and only if A is acyclic. That is, a set of
edges A is independent if and only if the subgraph G =(V, A) forms a forest.  
*A forest is an undirected graph in which any two vertices are connected by at most one path.*

>Basic Use:  
A matroid is a mathematical structure that generalizes the notion of linear independence from vector spaces to arbitrary sets. If an optimization problem has the structure of a matroid, then the appropriate greedy algorithm will solve it optimally.

*Problem*
Many problems for which a greedy approach provides optimal solutions can be formulated in terms of ﬁnding a maximum-weight independent subset in a weighted
matroid. That is, we are given a weighted matroid M =(S,I), and we wish to ﬁnd an independent set A belongs to I such that w(A) is maximized. We call such a sub-set that is independent and has maximum possible weight an optimal subset of the matroid.

<pre>
GREEDY(M, w)
1 A !=phi;
2 sort M.S into monotonically decreasing order by weight w
3 for each x belonging to M.S, taken in monotonically decreasing order by weight w(x)
4 if A U{x} 2 M.I
5 A = A U{x}
6 return A
</pre>