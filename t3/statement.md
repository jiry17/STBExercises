## Rikka with Sequence

As we know, Rikka is poor at math. Yuta is worrying about this situation, so he gives Rikka some math tasks to practice. There is one of them:

Yuta has an array $A$ with $n$ numbers and he keeps an auxiliary array $B$ with length $n$ and inital values $A_i$. 

Then Yuta makes m operations on it. There are four types of operations.

1. `1 l r c` : change $A_i$ to $A_i+c$ for all $i \in [l,r]$
2. `2 l r d` : change $A_i$ to $\max(A_i,d)$ for all $i \in [l,r]$
3. `3 l r` : query for $\min A_i$ for all $i \in [l,r]$
4. `4 l r` : query for $\min B_i$ for all $i \in [l,r]$

And after each operation, Yuta will update the value of each $B_i$ to $\min(B_i,A_i)$.

It is too difficult for Rikka. Can you help her?

#### Input

The first line contains two numbers $1 \leq n,m \leq 5 \times 10^5$. 

The second line contains $n$ numbers $A_i$. Then $m$ lines follow, each line describe an operation. 

It is guaranteed that $1 \leq l,r \leq n, l \leq r, 0 \leq |A_i|,|d| \leq 10^9,0 \leq |c| \leq 2000$. 

#### Output

For each query, print a single line with a single number -- the answer.

#### Sample Input

```
3 6
1 2 3
4 3 3
1 2 3 -2
3 1 3
4 3 3
2 2 3 4
3 1 3
```

#### Sample Output

```
3
0
1
1
```

