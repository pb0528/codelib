#Range(begin,end,step)  范围内按照补偿递增 按照[,)方式递增
for i in range(1,100):
    print(i)

for i in range(100,0,-1):
    print(i)

#while 与C++大致相似
sum,num = 0,2
while num<100:
    sum+=num
    num+=2
print(sum)