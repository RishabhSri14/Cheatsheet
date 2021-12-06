# Ford-Fulkerson Algorithm

*Problem*
Given a graph which represents a flow network where every edge has a capacity. Also given two vertices source ‘s’ and sink ‘t’ in the graph, find the maximum possible flow from s to t with following constraints:  
a) Flow on an edge doesn’t exceed the given capacity of the edge.  
b) Incoming flow is equal to outgoing flow for every vertex except s and t.  

**Basic Algo**
<pre>
The following is simple idea of Ford-Fulkerson algorithm:
1) Start with initial flow as 0.
2) While there is a augmenting path from source to sink. 
           Add this path-flow to flow.
3) Return flow.
</pre>

Time Complexity: Time complexity of the above algorithm is O(max_flow * E). We run a loop while there is an augmenting path. In worst case, we may add 1 unit flow in every iteration. Therefore the time complexity becomes O(max_flow * E).