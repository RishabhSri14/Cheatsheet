# Info:

>>We call an algorithm **randomized** if its behavior is determined
not only by its input but also by values produced by a random-number gener-
ator. We shall assume that we have at our disposal a random-number generator
RANDOM . A call to RANDOM(a, b) returns an integer between a and b, inclusive, with each such integer being equally likely.  
For example, RANDOM (0, 1)  
produces 0 with probability 1/2, and it produces 1 with probability 1/2. A call to
RANDOM (3, 7) returns either 3, 4, 5, 6, or 7, each with probability 1/5. Each inte-
ger returned by RANDOM is independent of the integers returned on previous calls.
You may imagine RANDOM as rolling a(b - a + 1)-sided die to obtain its out-
put. (In practice, most programming environments offer a pseudorandom-number
generator: a deterministic algorithm returning numbers that “look” statistically
random.)


> When analyzing the running time of a randomized algorithm, we take the expec-
tation of the running time over the distribution of values returned by the random
number generator. We distinguish these algorithms from those in which the input
is random by referring to the running time of a randomized algorithm as an ex-
pected running time. In general, we discuss the average-case running time when
the probability distribution is over the inputs to the algorithm, and we discuss the
expected running time when the algorithm itself makes random choices