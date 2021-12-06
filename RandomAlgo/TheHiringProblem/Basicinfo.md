# Hiring Problem

**Basic Idea**
>>Suppose that you need to hire a new ofﬁce assistant. Your previous attempts at
hiring have been unsuccessful, and you decide to use an employment agency. The
employment agency sends you one candidate each day. You interview that person
and then decide either to hire that person or not. You must pay the employment
agency a small fee to interview an applicant. To actually hire an applicant is more
costly, however, since you must ﬁre your current ofﬁce assistant and pay a substan-
tial hiring fee to the employment agency. You are committed to having, at all times,
the best possible person for the job. Therefore, you decide that, after interviewing
each applicant, if that applicant is better qualiﬁed than the current ofﬁce assistant,
you will ﬁre the current ofﬁce assistant and hire the new applicant. You are willing
to pay the resulting price of this strategy, but you wish to estimate what that price
will be?

*Pseudo Code*
<pre>
HIRE-ASSISTANT(n)
1 best = 0 // candidate 0 is a least-qualiﬁed dummy candidate
2 for i = 1 to n
3       interview candidate i
4 if candidate i is better than candidate best:
5       best = i
6       hire candidate i
</pre>

>Interviewing has a low cost, say ci , whereas hiring is expensive, costing ch . Letting m be the number of people hired, the total cost associated with this algorithm is O(ci*n + ch*m).    
No matter how many people we hire, we always interview n candidates and thus always incur the cost ci*n associated with interviewing. We therefore concentrate on analyzing ch *m, the hiring cost.

>>In the worst case, we actually hire every candidate that we interview. This situation
occurs if the candidates come in strictly increasing order of quality, in which case
we hire n times, for a total hiring cost of O(ch* n).