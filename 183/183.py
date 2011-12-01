from decimal import *
import math
getcontext().prec = 10
def gcd(a, b):
    if a == b:
        return a
    while a > b:
        a -= b
    while b > a:
        b -= a
    return gcd(a, b)
    
def isT(m, n):
    n /= gcd(m, n)
    while n % 2 == 0:
        n /= 2
    while n % 5 == 0:
        n /= 5
    return n == 1
def f(n):
    best = -1
    bestp = 1
    p = 1
    while p <= n:
        x =  (1.0 * n) #** (p)
        x /= (1.0 * p) #** (p)
        x = math.log(x) * p
        if x > best:
            best = x
            bestp = p
        else:
            break
        p += 1
    return isT(n, bestp)
def solve(N):
    total = 0
    n = 5
    while n <= N:
        if f(n):
            total -= n
        else:
            total += n
        n += 1
    return total
print(solve(10000))
