if __name__ == '__main__':
	n = int(input())
	arr = list()
	depa = list()
	for i in range(0,n):
		x =input()
		#print(x)
		num = x.split(" ")
		#print(num)
		n1 = int(num[0])
		n2 = int(num[1])
		arr.append(n1)
		depa.append((n2+n1))
	maxi = 0
	plat = 1
	arr.sort()
	depa.sort()
	i,j = 1,0
	while i < n and j < n:
		if arr[i] <= depa[j]:
			i = i+1
			plat = plat +1
			if maxi < plat: maxi = plat
		else:
			j = j+1
			plat = plat -1
	print(maxi,end=" ")
