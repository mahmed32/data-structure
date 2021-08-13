def findTwoMissing(list):
    n = len(list) + 2

    xor=0
    for x in range(1, n+1):
        xor ^= x

    xor_elments = 0
    for x in list:
        xor ^= x

    right_set_bit = xor & ~(xor-1)

    num1 = 0
    num2 = 0

    for x in list:
        if(right_set_bit & x):
            num1 ^= x
        else:
            num2 ^= x

    for x in range(1, n+1):
        if(right_set_bit & x):
            num1^=x
        else:
            num2^=x

    print(num1)
    print(num2)


l = [2,1,3,6,4,5]
findTwoMissing(l)
