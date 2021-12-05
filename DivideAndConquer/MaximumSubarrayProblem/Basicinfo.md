# Maximum Sub array sum
*Problem*  
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum.

For example, if the given array is {-2, -5, <strong>6, -2, -3, 1, 5,</strong> -6}, then the maximum subarray sum is 7 (see highlighted elements).

>>Basic Algo
<pre>
1) Divide the given array in two halves
2)Return the maximum of following three
    -Maximum subarray sum in left half (Make a recursive call)
    -Maximum subarray sum in right half (Make a recursive call)
    -Maximum subarray sum such that the subarray crosses the  midpoint
</pre>

>>Time Complexity:O(nlogn)

>>Click <a href="code.cpp">here</a> to acccess the code