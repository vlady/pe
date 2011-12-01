p = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131]
best = 1
goal = 1

def backT(n, fac, k):
    global goal
    global best
    if fac >= goal:
        if n < best:
            print(n, fac)
            best = n
        return
    i = 0
    while True:
        i += 1
        global p
        n *= p[k]
        if n >= best:
            return
        backT(n, fac * (2 * i + 1), k + 1)
    
def solve(n):
    # first to have more than or equal to n
    global p
    num = 1
    fac = 1
    k = 0
    while fac < n:
        fac *= 3
        num *= p[k]
        k += 1
    global best
    best = num
    global goal
    goal = n
    print(best, fac)
    backT(1, 1, 0)

solve(2*1000)
backT(11, 1, 1) 

