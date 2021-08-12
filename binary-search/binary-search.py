import math
def BinarySearch(list, target):
    start = 0
    end = len(list) - 1
    while(start <= end):
        mid = start + math.ceil((end - start)/2)
        if(target > list[mid]):
            start = mid + 1
        elif(target < list[mid]):
            end = mid - 1
        else:
            return mid
    return -1
l = [1,2,3,4,5]
print(BinarySearch(l, 1))
print(BinarySearch(l, 2))
print(BinarySearch(l, 3))
print(BinarySearch(l, 4))
print(BinarySearch(l, 5))
print(BinarySearch(l, 6))
    
