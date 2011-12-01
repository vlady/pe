hash = {}
def bouncy(lastd, n, step):
    if lastd < 0 or lastd > 9:
        return 0
    if n == 0:
        if lastd == 0:
            return 0
        return 1
    global hash
    key = (lastd, n, step)
    if hash.has_key(key):
        return hash[key]
    total = 0
    while lastd >= 0 and lastd <= 9:
        total += bouncy(lastd, n - 1, step)
        lastd += step
    hash[key] = total
    return total
def solve(n):
    overlap = 9
    return bouncy(9, n, -1) + bouncy(0, n, 1) - overlap
def solve2(n):
    total = 0
    for i in range(1, n+1):
        total += solve(i)
    print(total)
solve2(10)
solve2(6)
solve2(100)
    
