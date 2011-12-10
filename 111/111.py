import random
suma = 0
n = 10
def modulo(a, b,c): 
    x = 1
    y = a
    while (b > 0):
        if ((b & 1) == 1):
            x = (x * y) % c
        y = (y * y) % c
        b >>= 1
    return x % c

def mulmod(a, b, c): 
    x = 0
    y = a % c
    while (b > 0):
        if ((b&1) == 1):
            x = (x+y)%c
        y = (y*2)%c
        b >>= 1
    return x % c
def Miller(p, n): 
    #assume not divisible by 2
    s = p - 1
    while ((s&1) == 0):
        s >>= 1
    
    while n > 0: 
        a = random.randint(1, p - 1);
        aux = s
        mod = modulo(a, s, p)
        while (aux != p-1 and mod != 1 and mod != p-1):
            mod = mulmod(mod, mod, p)
            aux <<= 1
        
        if (mod != p-1 and (aux&1) == 0):
            return False
        n -= 1
    return True

def is_prim(num):
    if (num == 2):
        return True
    if (num % 2 == 0 or num % 3 == 0 or num % 5 == 0 or num % 7 == 0):
        return False
    return Miller(num, 100)

def back(num, k, l, c): 
    global n
    if (n - k < l):
        return;
    if (k == n):
        if (is_prim(num)):
            global suma
            suma += num
        return;
    d = (k == 0);
    while (d <= 9):
        if (d == c):
            l -= 1
        back(num*10 + d, k + 1, l, c)
        if (d == c):
            l += 1
        d += 1

def main():
    total = 0;
    for i in range(10):
        global n
        cate = n
        while (cate >= 1):
            global suma
            suma = 0;
            back(0, 0, cate, i);
            total += suma;
            if (suma):
                print(suma,cate)
            if (suma):
                break;
            cate -= 1
    print(total)
main()
