int secondRightmostZeroBit(int n) {
  return ~((~n&(n+1))|n)&(((~n&(n+1))|n)+1); 
}

//better vesion
int secondRightmostZeroBit(int n) {
  return ((~n&(n+1))+(n+1))& ~n;
}

//even better
int secondRightmostZeroBit(int n) {
  return (~n) & ( (n|(n+1)) + 1);
}
