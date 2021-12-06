# Johnson’s algorithm for sparse graphs

*Problem*
The problem is to find shortest paths between every pair of vertices in a given weighted directed Graph and weights may be negative. 

>We have discussed Floyd Warshall Algorithm for this problem. Time complexity of Floyd Warshall Algorithm is Θ(V3). Using Johnson’s algorithm, we can find all pair shortest paths in O(V2log V + VE) time.   
> If we apply Dijkstra’s Single Source shortest path algorithm for every vertex, considering every vertex as source, we can find all pair shortest paths in O(V*VLogV) time. So using Dijkstra’s single source shortest path seems to be a better option than Floyd Warshell, but the problem with Dijkstra’s algorithm is, it doesn’t work for negative weight edge.

*Basic Idea*
The idea of Johnson’s algorithm is to re-weight all edges and make them all positive, then apply Dijkstra’s algorithm for every vertex.

**Algorithm**
<pre>
1) Let the given graph be G. Add a new vertex s to the graph, add edges from new vertex to all vertices of G. Let the modified graph be G’.

2) Run Bellman-Ford algorithm on G’ with s as source. Let the distances calculated by Bellman-Ford be h[0], h[1], .. h[V-1]. If we find a negative weight cycle, then return. Note that the negative weight cycle cannot be created by new vertex s as there is no edge to s. All edges are from s.

3) Reweight the edges of original graph. For each edge (u, v), assign the new weight as “original weight + h[u] – h[v]”.

4) Remove the added vertex s and run Dijkstra’s algorithm for every vertex.
</pre>

The following property is always true about h[] values as they are shortest distances.
<pre>
   h[v] <= h[u] + w(u, v)</pre>   

The property simply means, shortest distance from s to v must be smaller than or equal to shortest distance from s to u plus weight of edge (u, v). The new weights are w(u, v) + h[u] - h[v]. The value of the new weights must be greater than or equal to zero because of the inequality "h[v] <= h[u] + w(u, v)".

**Time Complexity**
Time Complexity: The main steps in algorithm are Bellman Ford Algorithm called once and Dijkstra called V times. Time complexity of Bellman Ford is O(VE) and time complexity of Dijkstra is O(VLogV). So overall time complexity is O(V^2log V + VE).  
The time complexity of Johnson's algorithm becomes same as Floyd Warshell when the graphs is complete (For a complete graph E = O(V^2). But for sparse graphs, the algorithm performs much better than Floyd Warshell.