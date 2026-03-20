//Turn off the rightmost set bit
#include <stdio.h>

/* Function to turn off the rightmost set bit */
int turnOffRightMostSetBit(unsigned int n) {
    return n & (n - 1);
}

int main() {
    unsigned int n = 12; // Binary: ...00001100
    unsigned int result = turnOffRightMostSetBit(n);

    // The result should be 8 (Binary: ...00001000)
    printf("Original n = %u\n", n);
    printf("Result after turning off the rightmost set bit = %u\n", result);

    return 0;
}
//check 