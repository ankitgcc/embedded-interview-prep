# Bit Manipulation

## Common Operations

### Set nth bit
num |= (1 << n);

### Clear nth bit
num &= ~(1 << n);

### Toggle nth bit
num ^= (1 << n);

### Check nth bit
(num >> n) & 1

---

## Interview Questions

1. Check if a number is power of two
2. Count number of set bits
3. Find the only non-repeating element in array
4. Swap two numbers without temp variable
5. Reverse bits of a number
6. Turn off the rightmost set bit
7. Check if a number is even or odd
8. Toggle the ith bit of a number

---

## Tricks

x & (x-1) → remove rightmost set bit  
x & -x → isolate rightmost set bit  
x | (x+1) → set rightmost zero bit