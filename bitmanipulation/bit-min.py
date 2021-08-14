def bitMin(x, y):
    return x^((x^y) & (y-x)>>31)

print(bitMin(2,3) == 2)
print(bitMin(0,1) == 0)
print(bitMin(1,1) == 1)
