# Activity Selection
### ***Activity Selection***

*Problem*
> Given a set of activities S={a0,a1,a2,a3,...}, where each ai is defned as [si,fi) where si=starting time and fi=finish time.  
> Goal: Select the largest possible set of non-overlapping activities.  

**Greedy Algo**

> - *Greedy Choice Property* : The activity with the least finish time (say a0) belongs to solution.  
> Reason: Say ak is the activity with least finish time in the final set of activities.
> If we remove ak and add a0 the resulting set of solution will also be a optimum solution,  
> as f0 < fk , so no overlapping will occur among the activities.  

> - *Optimum Sustructure Property* -Solve for the activity selection problem for the activities compatible with the activity a0 and recurse.

*Pseudo Code*
<pre>
struct activities{
    int si;
    int fi;
};
struct activities A[n],R[n];
Sort(A,fi);
int c=0;
R[0]=A[0];
int finish=A[0].fi;
for(i=1;i < n;i++)
{
    if(A[i].s>=finish)
    {
        R[c++]=A[i];
        finish=A[i].fi;
    }
}
</pre>
