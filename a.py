count={}
count[(1,2,4)] = 5
count[(4,2,1)] = 7
count[(1,2)] = 6
count[(4,2,1)] = 4
tot = 0
for i in count:
    tot=tot+count[i]
print(len(count)+tot)