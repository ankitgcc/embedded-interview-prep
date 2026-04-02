#include <stdio.h>

// Helper to compute XOR from 1 to n in O(1)
int computeXOR(int n) {
    if (n < 0) return 0;
    int rem = n % 4;
    if (rem == 0) return n;
    if (rem == 1) return 1;
    if (rem == 2) return n + 1;
    return 0; // rem == 3
}

// Function to compute XOR of range [L, R]
int xorRange(int L, int R) {
    return computeXOR(R) ^ computeXOR(L - 1);
}

int main() {
    int L = 4, R = 8;
    printf("XOR of range [%d, %d] is: %d\n", L, R, xorRange(L, R));
    return 0;
}
