def findNonRepeatedTwo(list):
    xor = 0
    for x in list:
        xor ^= x

    rMostBit = xor & ~(xor - 1)
    
    num1 = 0
    num2 = 0
    
    for x in list:
        if x & rMostBit:
            num1^=x
        else:
            num2^=x

    print(num1)
    print(num2)
    return


l = [1,2,3,4,5,6,1,2,4,3]
findNonRepeatedTwo(l)


