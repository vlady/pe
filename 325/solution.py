import math
#aug (sum, zeros)
hash_aug = {}
def augCstr(width, maxL):
	global hash_aug
	if hash_aug.has_key((width, maxL)):
		return hash_aug[(width, maxL)]
	if (width < 0):
		return (0, 0)
	if maxL == 0:
		return (0, 0)
	if maxL == 1:
		return ((width * (width + 1)) // 2 + 2*width, width)
	if maxL % 2 == 1:
		t = maxL - 1
		A = augCstr(width, maxL - 1)
		B = augCstr(width, 1)
	else:
		t = maxL // 2
		A = augCstr(width, maxL // 2)
		B = A # augCstr(width, maxL // 2)
	# translate B down and right by t
	B = (B[0] + B[1] * t * 2, B[1])
	# aggregate
	ret = (A[0] + B[0], A[1] + B[1])
	hash_aug[(width, maxL)] = ret
	return ret

# Construct ith fibonaci thing.
# Return the number of lines and the sum of indices, num of ones, num of zeros
hash_fibo = {}
fib_len = [0, 1, 2]
def fiboCstr(i, maxL):
	global hash_fibo
	if (maxL > fib_len[i]):
		maxL = fib_len[i]
	if hash_fibo.has_key((i, maxL)):
		return hash_fibo[(i, maxL)]
	if maxL == 0:
		return (0, 0, 0, 0)
	if i == 1:
		return (1, 2, 1, 1)
	if i == 2:
		if maxL == 1:
			return (1, 2, 1, 1)
		return (2, 9, 1, 3)
	A = fiboCstr(i-2, maxL)
	B = fiboCstr(i-1, maxL - A[0])
	# AB
	# augment with zeros
	aug = augCstr(A[0] - A[2], B[0])
	B = (B[0], B[1] + aug[0], B[2], B[3] + aug[1])
	# translate B down
	B = (B[0], B[1] + B[3] * A[0], B[2], B[3])
	# translate B right
	B = (B[0], B[1] + B[3] * (A[2]), B[2], B[3])
	# aggregate
	ret = (A[0] + B[0], A[1] + B[1], A[2] + B[2], A[3] + B[3])
	hash_fibo[(i, maxL)] = ret
	return ret

def S(n):
	# fit fibonaci strings
	global fib_len
	for i in range(3, 1001):
		fib_len.append(fib_len[i-1] + fib_len[i-2])
	i = 1
	total = 0
	last_line = 0
	last_col = 0
	lena = 1
	lenb = 2
	while n > 0:
		need = lenb
		if n < need:
			need = n
		fibo = fiboCstr(i, need)
		need = lena
		lena = lenb
		lenb = lenb + need
		# augument
		# print(last_line, last_col, fibo)
		aug = augCstr(last_line - last_col - 1, fibo[0])
		# print(aug)
		partial = fibo[1] + aug[0]
		# translate last_line lines, last_col
		partial += (fibo[3] + aug[1]) * (last_line + last_col)
		total += partial
		last_line += fibo[0]
		last_col += fibo[2]
		n -= fibo[0]
		i += 1
	return total - 12 # works for N >= 10
print S(10**16) % (7 ** 10)
