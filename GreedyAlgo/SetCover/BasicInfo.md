*Problem*

>> Given a set of elements {s1,s2,s3,...sn} in B, such that S1, S2, S3, ...Sm are subsets of B.  
>> We are required to select minimum number of subsets whose union cover whole of B.

**Greedy  Algo**

> - *Greedy Choice Property* - Select the subset which has the maximum cardinality (say Sk).  
> - *Optimum Sustructure Property* - Now select the subset that comprises of the maximum si's that are not present Sk.  
> - *Recursion* - Recurse second step changing Sk to (Sk U Sk').

<pre>
(Not Ideal; Better version can be created using hashtable)
int main(){
    struct Subset
    {
        char Subset[n];
        int Covered[n]=0;
        int card;
    };
    int c=0;
    char  Elements[n];
    struct Subset s[m];
    char ** Result;
    getResult();// No. steps in this will be atmost kln(n)
}
getResult(struct Subset s[],int n, int* c, char** Result)
{
    Sort(s,card,n);  // klogk
    strcpy(s[0].Subset,Result[c++]);
    UpdateCardinality(s,n); //kn
    getResult(s,n, &c);
}

</pre>

>> Note- This Algo doesn't always give the minimum cost solution.

> *Examples*

> - Consider B = {a,d,e,h,i,l,o,r,n ,s t,u} and subsets be {arid, dash, drain, lost, heard, nose, shun, snare, roast, lid, slate, thread}  
> First pick: thread  
> Uncovered: {i,l,n,o,s,u}  
> Second pick:  lost  
> Uncovered yet: {i,n,u}  
> Third pick: drain  
> Not yet covered: {u}  
> Fourth pick: shun  
>> In this example greedy approach works.

> - Consider B = {1,2,3,4,5,6} with subsets {1,3,5,2},{3,5,6},{4,1,2}
> First pick: {1,3,5,2}  
> Uncovered: {4,6}  
> Second pick:  {3,5,6}  
> Uncovered yet: {4}  
> Third pick: {4,1,2}  
>> The optimum solution should be {3,5,6} and {1,4,2}

>> *Note*- Set Cover is NP - complete i.e. class of computational problems for which no efficient solution algorithm has been found. These type of problems has no polynomial time solution

**Greedy Strategy in Set Cover is O(ln n)- Approximate**

*Claim* - If B has n elements and the subsets given are k in number then the greedy approach uses atmost kln(n) sets.

*Proof*  
>Let nt denotes the number of uncovered elements after t iterations.
>By pigeonhole, since there are nt elements (pigeons) and atmost k subsets(pigeonholes), there must be a set that contains nt/k elements.  
> n(t+1) < nt - nt/k => nt+1 < nt(1-1/k) => nt+1 < n0(1-1/k)^t.  
> nt+1 < ne^(-t/k) // as 1-x < e^-x for all x.  
> At t= kln(n) nt+1<=1.  
