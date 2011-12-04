CC = [0, 10, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]
CH = [0, 10, 11,24,39, 5,-2,-2,-3,-4,-1,-1,-1,-1,-1,-1]

CC_pos = 0
CH_pos = 0

P = [0 for x in range(40)]
def evaluate():
    l = []
    for i in range(40):
        l.append((P[i], i))
    l.sort()
    print l[-3:]
doubles = 0
def is_R(pos):
    return pos % 10 == 5
def is_U(pos):
    return pos == 12 or pos == 28
def land_CC(pos):
    global CC_pos
    if CC[CC_pos] != -1:
        pos = CC[CC_pos]
    return pos 
def land_CH(pos):
    global CH_pos
    if CH[CH_pos] >= 0:
        pos = CH[CH_pos]
    if CH[CH_pos] == -2:
        while not is_R(pos):
            pos = (pos + 1) % 40
        # next R
    if CH[CH_pos] == -3:
        while not is_U(pos):
            pos = (pos + 1) % 40
        # next U
    if CH[CH_pos] == -4:
        pos = (37 + pos) % 40 
    return pos
def land(pos):
    global CC_pos
    global CH_pos
    global doubles
    if doubles == 3:
        doubles = 0
        return 10
    if pos == 30:
        return 10
    if pos == 2 or pos == 17 or pos == 33:
        CC_pos += 1
        CC_pos %= 16
        return land_CC(pos)
    if pos == 7 or pos == 22 or pos == 36:
        CH_pos += 1
        CH_pos %= 16
        return land_CH(pos)
    return pos

def simulate(N):
    pos = 0
    global CC_pos
    global CH_pos
    global doubles
    CC_pos = 0
    doubles = 0
    CH_pos = 0
    while N > 0:
        N -= 1
        import random
        zar1  = random.randint(1,4)
        zar2  = random.randint(1,4)
        if zar1 == zar2:
            doubles += 1
        else:
            doubles = 0
        pos = land((pos + zar1 + zar2) % 40)
        P[pos] += 1
        if N % 100000 == 0:
            evaluate()
    evaluate()

simulate(1000000)
