import math
def BinarySearch(target, list, start, end):
    if(start > end):
        return -1
    mid = start + math.ceil((end - start)/2)
    if(target > list[mid]):
        return BinarySearch(target, list, mid+1 , end)
    elif(target < list[mid]):
        return BinarySearch(target, list, start, mid-1)
    else:
        return mid


l = [1,2,3,4,5]

print(BinarySearch(1, l, 0, len(l) -1))
print(BinarySearch(2, l, 0, len(l) -1))
print(BinarySearch(3, l, 0, len(l) -1))
print(BinarySearch(4, l, 0, len(l) -1))
print(BinarySearch(5, l, 0, len(l) -1))
print(BinarySearch(6, l, 0, len(l) -1))
