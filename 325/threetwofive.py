cache = {}
def win(x, y):
	global cache
	if x == 0:
		return 0
	if (x == y):
		return 1
	if (y < x):
		 return win(y, x)
	if cache.has_key((x,y)):
		return cache[(x,y)]
	cache[(x,y)] = 0
	d = 1
	while d * x <= y:
		if win(x, y - d * x) == 0:
			cache[(x,y)] = 1
			return 1 
		d += 1
	return 0

def SSS(N):
	import math
	total = 0
	totalx = 0
	totaly = 0
	totalF = 0
	for x in range(N+1):
		if x > 0:
			fl = int(math.ceil( (1.0 * x) / ((1.0 + 5.0**0.5)/2.0)))
			cate = x - fl
			t = cate * (cate - 1) / 2
			t += cate * x + cate * fl
			totalF += t
		for y in range(N+1):
			if (x < y and x > 0 and y > 0) and win(x,y) == 0:
				total += x + y
				totalx += x
				totaly += y
	return [total % (7 ** 10), totalF, totalx, totaly]
def perioada():
	import math
	x = 1
	totalF = 0
	seen = {}
	while True:
		fl = int(math.ceil( (1.0 * x) / ((1.0 + 5.0**0.5)/2.0)))
		cate = x - fl
		t = cate * (cate - 1) / 2
		t += cate * x + cate * fl
		totalF += t
		totalF %= (7**10)
		if seen.has_key(totalF):
			print(x, totalF, seen[totalF])
		seen[totalF] = x
		x += 1
		
def pe(N):
	for x in range(N):
		line = ""
		for y in range(N):
			line += str(win(x,y))
		print line

def inainte(N):
	toate = []
	for x in range(N):
		cate = 0
		for y in range(N):
			if (y < x and x > 0 and y > 0):
				 cate += (win(x,y)^1)
		toate.append(cate)
	print toate
def fib(N):
	import math
	lst = 0
	for x in range(1, N + 1):
		for y in range(1, x+1):
			if (win(x,y)==0):
				break
		if y != math.ceil( (1.0 * x) / ((1.0 + 5.0**0.5)/2.0)):
			print "NO"
		print y - lst
		lst = y 
