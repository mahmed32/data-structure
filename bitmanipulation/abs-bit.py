def abs_bit(x):
    mask = x>>31
    return (x ^ mask) - mask

print(abs_bit(-2) == 2)
print(abs_bit(0) == 0)
print(abs_bit(2) == 2)
