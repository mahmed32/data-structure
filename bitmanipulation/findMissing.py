def findMissing(list, n):
    total = 0
    for i in range(n):
        total += (i+1)
        total -= list[i]
    if total != 0:
        total += (n+1)
    return total

l = [1,2,3,4,5]
print(findMissing(l, 5))
