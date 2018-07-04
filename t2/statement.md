## Rikka with Sequence

As we know, Rikka is poor at math. Yuta is worrying about this situation, so he gives Rikka some math tasks to practice. There is one of them:

Yuta has an array $A$ with $n$ numbers and he keeps an auxiliary array $B$ with length $n$ and inital values $0$. 

Then Yuta makes m operations on it. There are four types of operations.

1. `1 l r x` : change $A_i$ to $\min(A_i, x)$ for all $i \in [l,r]$
2. `2 l r x` : change $A_i$ to $\max(A_i,x)$ for all $i \in [l,r]$
3. `3 l r y` : change $A_i$ to $A_i + y$ for all $i \in [l,r]$
4. `4 l r` : query for $\sum_{i=l}^r B_i$

And after each operation, Yuta will update the value of each $B_i​$ to $B_i + f(i)​$. If $A_i​$ is changed by this operation, then $f(i) = 1​$, otherwise $f(i) = 0​$. 

It is too difficult for Rikka. Can you help her?

#### Input

The first line contains two numbers $1 \leq n,m \leq 10^5$. 

The second line contains $n$ numbers $A_i$. Then $m$ lines follow, each line describe an operation. 

It is guaranteed that $1 \leq l,r \leq n, l \leq r, 0 \leq |A_i|,|x| \leq 10^9,0 \leq |y| \leq 10^4$. 

#### Output

For each query, print a single line with a single number -- the answer.

#### Sample Input

```
3 6
1 2 3
1 1 3 3
4 1 3
2 1 3 -1
4 1 3
3 1 3 0
4 1 3
```

#### Sample Output

```
2
5
5
```

