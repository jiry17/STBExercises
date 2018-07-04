## Rikka with Sequence

As we know, Rikka is poor at math. Yuta is worrying about this situation, so he gives Rikka some math tasks to practice. There is one of them:

Yuta has an array $A$ with $n$ numbers and he keeps an auxiliary $n \times n$ 2D-array $B$ with inital values $B_{i,j} = \sum_{k=i}^j A_k$.

Then Yuta makes m operations on it. There are two types of operations.

1. `1 a x` : change $A_a$ to $x$
2. `2 l r` : query for the value of $B_{l,r}$  

And after each operation, Yuta will update the value of each $B_{i,j}$ to $\min(B_{i,j},\sum_{k=i}^jA_k)$

It is too difficult for Rikka. Can you help her?

#### Input

The first line contains two numbers $1 \leq n,m \leq 10^5$. 

The second line contains $n$ numbers $A_i$. Then $m$ lines follow, each line describe an operation. 

It is guaranteed that $1 \leq l,r \leq n, l \leq r, 1 \leq A_i,x \leq 10^9$

#### Output

For each query, print a single line with a single number -- the answer.

#### Sample Input

```
3 3
1 2 3
2 1 3
1 2 1
2 1 3
```

#### Sample Output

```
6
5
```

