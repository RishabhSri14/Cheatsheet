# Topological Sorting
*Definition*
>Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering

*Algo*
> Do DFS ( any Pre/Post/In) from a source (say S) but do not print the nodes.   
> Pust the nodes in stack when all of its adjacent vertices are already in the stack(i.e all it's neighbours is traversed and when the function returns back).  
> Finally print the value in stack by pulling out members sequentially.  

>> Time Complexity: O(V+E)  
>> Space Complexity: O(V)

>> Here is the code for <a href="https://github.com/Github-Classroomtest/assignment-RishabhSri14/blob/main/Code/TopologicalSort.c">Topological Sort</a> 


### Example:

***Shortest Path in DAG***  

*Problem*
Given a DAG find the shortest path between source S and dest D.

*Algo*  
<pre>
Topological Sort(V,S);
dist[V];
dist[S->S]=0, dist[rest]=infinte;
for v in V's in sorted order
{
    for u in Neigbour(v)
    {
        dist[v]=min(dist[v],dist[u]+E(u,v));
    }
}
</pre>

>> Time Complexity = O(V+E) in the while if we use dijshta it is (V+ElogE)

>> For Longest Path, in any general graph it is an NP problem(due to negative edge weights prsent).
>> But in DAG, it can be done in O(V+E) by following the same steps as above, except instead of initialising with infinity initialise with - infinity and replace min with max.