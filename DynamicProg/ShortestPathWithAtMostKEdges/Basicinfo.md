## ***Shortest Path that uses atmost k edges***

*Problem:*  
> Given a graph G with Source s and Destination t with edge lengths Ei, we want to calculate shortest path b/w s and t using atmost k edges.

*Algo*

Let dis(v,i) = distance from s to v that uses i edges, where i< k .

> - Subproblem -  dist(v,i). Since there can be a total of n edges and i< k so there are a total nk subproblems.   
> - Relation or Topological order- dist(v,i)=min{dist(u,i-1)+l(u,v)} where (u,v) belongs to E.  
> - Toplogical sort the graph and book-keep dist(v,i).  

>> Time Complexity = O(nK)