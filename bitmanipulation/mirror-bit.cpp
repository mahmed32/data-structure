//reverse the bits in a give integer x

int result = 0;
for(; x; x>>=1)
    result = result << 1 | x & 1;
return reuslt
