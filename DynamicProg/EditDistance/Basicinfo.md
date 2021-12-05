# Edit Distance
*Problem*  
The minimum number of Insert/Delete/Overwrite operations to convert one word to another.
eg. SNOWY and SUNNY  

>> The above problem can be rephrased as:

> You are free to insert '_' in the first or second word such that total length remains same and we are required minimise mismatches.  
> eg. S_NOWY  
>     SUNN_Y 
>
> '_' in first word implies insert the corressponding below letter.  
> '_' in second word implies delete the corressponding above letter.  
> any mismatch in letters implies overwrite.
> Hence the cost is 3.  

**Algo by Dynamic Programming**

> - *Subproblem* - Calculate edit distance E(i,j) between some prefix of the first string, x[1 … i], and some
prefix of the second, y[1 … j].
> - *Relation or Topological order-* E[ i,j ] =min( 1 + E[ i,j-1 ] (*insert*) + 1 + E[ i-1,j ] (*delete*) + diff(i,j) + E[ i-1, j-1] (*Overwrite*) ).  // where diff(i,j)=0 if x[ i ] == y[ j ](*No Overwrite*) else 1.
> - Since first row and first column are known, traverse row wise or column wise book-keeping the previous values in a 2-d array.  


*NOTE-*
> - Generally subproblems are prefix of input or suffix of input(In LIS it was prefix and here too).  
> - In LIS the topological order or relation was L(i)=1+max(L[ j ]); // where 0 < j < i; and L[ i ] is LIS ending at ith index.
> - Generally the value which we book-keep is the value used in relation.

<pre>
for i in 1 to n{
    E[i,0]=i;
}
for j in 1 to m{
    E[0,j]=j
}
for i in 1 to n{
    for j in 1 to m{
        E[i,j]=min( 1 + E[ i,j-1 ] + 1 + E[ i-1,j ] + diff(i,j) + E[ i-1, j-1] )
    }
}
</pre>

>> Time Complexity=O(m*n)
