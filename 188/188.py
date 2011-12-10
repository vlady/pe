import sys
sys.setrecursionlimit(2000)
def f(a, k, mod):
    if k == 1:
        return a % mod
    return pow(a, f(a,k-1,mod), mod)
print f(1777, 1855, 10**8)
