import sys
sys.setrecursionlimit(100)
fib = [0 for x in range(100)]
fib[0] = 1
fib[1] = 2
hash = {}
def solve(a, b):
    if b == 0:
        return 0
    if a == 0:
        a = 1
    global hash
    key = (a, b)
    if hash.has_key(key):
        return hash[key]
    total = 0
    big = 1
    for f in fib:
        if f > b:
            break
        if f >= a:
            big = f
    c = big
    total += solve(a, c - 1) + solve(c - big, b - big) + b - c + 1
    hash[key] = total
    return total
for i in range(2, 100):
    fib[i] = fib[i-1] + fib[i-2]
print solve(1, (10**17) - 1)
