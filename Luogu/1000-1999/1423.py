S=float(input())
dis=0
i=2
cnt=0
while(dis<S):
	dis+=i
	cnt+=1
	i*=0.98
print(cnt)