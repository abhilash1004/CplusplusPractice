def closingvalue(l):
	ini = dict()
	buyer = dict()
	final = dict()
	for rec in l:
		if rec[1] == 'Sell':
			if(rec[2] in ini):
				ini[rec[2]][0] = int(rec[3])
				ini[rec[2]][1] = ini[rec[2]][1] + int(rec[4])
			else:
				temp = list()
				temp.append(int(rec[3]))
				temp.append(int(rec[4]))
				ini[rec[2]]=temp
		if rec[1] == 'Buy':
			if rec[2] in buyer:
				continue
			temp = list()
			temp.append(int(rec[3]))
			temp.append(int(rec[4]))
			buyer[rec[2]]  = temp
	#for r in ini:
		#print("seller",r,ini[r])
	#for b in buyer:
		#print("buyer",b,buyer[b])
	for b in buyer:
		if b in ini:
			if buyer[b][0] < ini[b][0]:
				continue
			if buyer[b][1] < ini[b][1]:
				ini[b][1] = ini[b][1] - buyer[b][1]
			else:
				ini[b][1] = 0
			final[b] = ini[b][0]
	if len(final)==0:
		print("Stocks not traded",end="")
	else:
		ans = list()
		for f in final:
			s = str(f) + ":" + str(final[f])
			ans.append(s)
		ans.sort()
		for i in ans:
			print(i,end=" ")




if __name__ == "__main__":
	n = int(input())
	l = list()
	for i in range(0,n):
		x = input()
		temp = list(x.split(" "))
		l.append(temp)
	closingvalue(l)