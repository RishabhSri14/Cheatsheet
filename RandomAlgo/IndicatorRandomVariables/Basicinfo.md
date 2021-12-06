# Indicator Random Variable

>>In order to analyze many algorithms, including the hiring problem, we use indicator
random variables. Indicator random variables provide a convenient method for
converting between probabilities and expectations.  

Suppose we are given a sample space S and an event A. Then the indicator random variable I{A} associated with
event A is deﬁned as:  
<pre>
I{A} = {1 if A occurs ;}
I{A} = {0 if A does not occur}
</pre>

>*Example:*  
Let us determine the expected number of heads that we obtain when ﬂipping a fair coin. Our sample space is S = {H; T }, with Pr {H } =
Pr {T } = 1/2. We can then deﬁne an indicator random variable XH , associated
with the coin coming up heads, which is the event H . This variable counts the
number of heads obtained in this ﬂip, and it is 1 if the coin comes up heads and 0
otherwise. We write 
<pre> 
XH= I{H }
(
1 if H occurs ,
0 if T occurs .
)
</pre>
The expected number of heads obtained in one ﬂip of the coin is simply the ex-
pected value of our indicator variable X H :
<pre>
E [XH] =E [I {H}]
= 1 * (Pr{H}) + 0 *(Pr{T})
= 1 * .1/2 + 0 * 1/21
= 1/2
</pre>
Thus the expected number of heads obtained by one ﬂip of a fair coin is 1=2. As
the following lemma shows, the expected value of an indicator random variable
associated with an event A is equal to the probability that A occurs.

**Analysis of the hiring problem using indicator random variables**
Returning to the hiring problem, we now wish to compute the expected number of
times that we hire a new ofﬁce assistant. In order to use a probabilistic analysis, we
assume that the candidates arrive in a random order.  
Let X be therandom variable whose value equals the number of times we hire a new ofﬁce as-
sistant.  
<pre>E[X]=Σx.Pr(X=x)</pre>
but this calculation would be cumbersome. We shall instead use indicator random
variables to greatly simplify the calculation.

>To use indicator random variables, instead of computing E[X] by deﬁning one
variable associated with the number of times we hire a new ofﬁce assistant, we
deﬁne n variables related to whether or not each particular candidate is hired. In
particular, we let X i be the indicator random variable associated with the event in
which the ith candidate is hired. Thus,
<pre>
Xi= I {candidate i is hired}
(
= 1 if candidate i is hired ;

=0 if candidate i is not hired ;
and
X = X1 + X2+...+ Xn .
</pre>

>Candidate i is hired, in line 6, exactly when candidate i is better than each of
candidates 1 through i - 1. Because we have assumed that the candidates arrive in
a random order, the ﬁrst i candidates have appeared in a random order. Any one of
these ﬁrst i candidates is equally likely to be the best-qualiﬁed so far. Candidate i
has a probability of 1/i of being better qualiﬁed than candidates 1 through i - 1
and thus a probability of 1/i of being hired.

Now we can compute E [X]:
<pre>
E[X] = E[Σxi]
    = ΣE[xi]
    = Σ(1/i)
    =ln(n) +O(1)
</pre>
>Even though we interview n people, we actually hire only approximately ln n of
them, on average.

>>**Assuming that the candidates are presented in a random order, algorithm HIRE-ASSISTANT has an average-case total hiring cost of O(chln(n)).**